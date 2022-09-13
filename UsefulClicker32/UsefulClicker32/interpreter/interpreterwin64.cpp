#include <QDebug>
#include <QPoint>
#include <QTime>
#include <QDateTime>
#include <QClipboard>
#include <QDir>
#include <QGuiApplication>
#include <QScreen>
#include <QtGlobal>
#include <QApplication>
#include <windef.h>
#include "interpreter/interpreterwin64.h"
//#include "log/logger.h"
#include "cv/dspmodule.h"
#include "../mainwindow.h"
#include "windows.h"
#include "globals.h"
#include "./interpreter/expression_calculator.h"
#include "settings/clickersettings.h"
#include <windows.h>
#include <random>
#include <QRect>
#include <QRegularExpression>


static DspModule* dsp;
using namespace cv;

InterpreterWin64::InterpreterWin64()
    : AbstractInterpreter(), stopFlag(false)
{
    dsp = new DspModule();
}

void InterpreterWin64::init(QDomDocument& dom)
{
    // run every function which name contains word "init"
    QDomNodeList nodes = dom.elementsByTagName("func");
    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if( elm.toElement().hasAttribute("name") )
        {
            auto name = elm.toElement().attribute("name");
            functionMap[name] = elm;
        }

        if( elm.isElement() )
        {
            if( elm.toElement().attribute("name").contains("init") )
            {
                executeFunction(elm.toElement().attribute("name"));
            }
        }
    }

    // cache lists
}


QDomNode InterpreterWin64::populateVars(QDomNode nodE)
{
    QDomNode node = nodE.cloneNode(true);
    int N = node.toElement().attributes().count();
    for(int i=0; i < N; i++)
    {
        QString attr = node.attributes().item(i).nodeName();
        QString value = node.attributes().item(i).nodeValue();

        //$(UsefulClicker)/images/21.03.12.119.png
        QRegularExpression reVar("[#{]{2}([\\w_]+)[}]{1}");
        auto match = reVar.match(value);
        QString clickerPath = QDir::currentPath();
        // change relative path ./ on absolute path
        if( match.hasMatch() )
        {
            auto varname = match.capturedTexts()[1];
            if( Globals::global_vars.find(varname) != Globals::global_vars.end() )
            {
                //value = global_vars[varname].toString();
                QString val = Globals::global_vars[varname].toString();
                value = value.replace(reVar, val);
                node.toElement().setAttribute(attr,value);
            }
        }
        Log("-+-+-+: >>>> : " + attr + "=" + value);
    }
    return node;
}

void send_key2(QVector<WORD>& vkeys, bool keyUp)
{
    INPUT inputs[2];
    ZeroMemory(inputs, sizeof(inputs));
    // keydown events
    int i=0;
    for(auto key : vkeys)
    {
        inputs[i].type = INPUT_KEYBOARD;
        inputs[i].ki.wVk = key;
        if(keyUp) inputs[i].ki.dwFlags = KEYEVENTF_KEYUP;
        i++;
    }
    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

void send_key3(QVector<WORD>& vkeys, bool keyUp)
{
    INPUT inputs[3];
    ZeroMemory(inputs, sizeof(inputs));
    // keydown events
    int i=0;
    for(auto key : vkeys)
    {
        inputs[i].type = INPUT_KEYBOARD;
        inputs[i].ki.wVk = key;
        if(keyUp) inputs[i].ki.dwFlags = KEYEVENTF_KEYUP;
        i++;
    }
    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}


void ScrollDown()
{
    POINT mouse_pos;
    GetCursorPos(&mouse_pos);
    mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_WHEEL, 0, 0, DWORD(-100), 0);
    /*
    INPUT inputs[2];
    ZeroMemory(inputs, sizeof(inputs));
    inputs[0].mi.mouseData = -1040;
    inputs[0].mi.dy = -100;
    inputs[0].mi.dwExtraInfo = -100;
    SendInput(ARRAYSIZE(inputs), inputs, sizeof(MOUSEINPUT));
    */
}

void ScrollUp()
{
    POINT mouse_pos;
    GetCursorPos(&mouse_pos);
    mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_WHEEL, 0, 0, DWORD(100), 0);
    /*
    INPUT inputs[2];
    ZeroMemory(inputs, sizeof(inputs));
    inputs[0].mi.mouseData = 1040;
    inputs[0].mi.dy = 100;
    inputs[0].mi.dwExtraInfo = 100;
    SendInput(ARRAYSIZE(inputs), inputs, sizeof(MOUSEINPUT));
    */
}


std::set<WORD> modifiers_set { VK_CONTROL, VK_MENU, VK_SHIFT} ;

std::map<char*, WORD> keys_map{ {"ctrl", VK_CONTROL}, {"alt", VK_MENU}, {"shift", VK_SHIFT}, {"F1", VK_F1}, {"F2", VK_F2}, {"F3", VK_F3},
                                      {"F4", VK_F4}, {"F5", VK_F5}, {"F6", VK_F6},
                                      {"F7", VK_F7}, {"F8", VK_F8}, {"F9", VK_F9},
                                      {"F10", VK_F10}, {"F10", VK_F11},{"F10", VK_F12},
                                      {"return", VK_RETURN},{"enter", VK_RETURN},
                                      {"escape", VK_ESCAPE},{"up", VK_UP},{"left", VK_LEFT},
                                      {"right", VK_RIGHT},{"up", VK_UP},{"down", VK_DOWN},
                                      {"tab", VK_TAB},{"back", VK_BACK},{"insert", VK_INSERT},
                                      {"delete", VK_DELETE},{"lwin", VK_LWIN},{"rwin", VK_RWIN},{"space", VK_SPACE}};

void Key(char* hot_key)
{
    if( strlen(hot_key) < 1 ) return;
    if( strlen(hot_key) > 30 ) return;

    QVector<WORD> vkeys;
    QString key(hot_key);

    // delete spaces
    key = key.replace(" ","");

    // key combination is exactly one key
    if( key.size() == 1 )
    {
        char c = key[0].toLatin1();
        SHORT code = c-32;
        code = VkKeyScanA(c);
        vkeys.push_back(code);
    }
    else
    {

        for(auto it=keys_map.begin(); it!=keys_map.end(); it++)
            if( key.contains(it->first) )
                vkeys.push_back(it->second);

        // check that all keys already added tu vkeys is modifiers
        bool allModifiers = true;
        for(auto k : vkeys)
            if( modifiers_set.find(k) == modifiers_set.end())
                allModifiers = false;

        if( allModifiers )
        {
            // add to vkeys array last character in input string as key code
            char c = hot_key[strlen(hot_key)-1];
            SHORT code = c-32;
            code = VkKeyScanA(c);
            vkeys.push_back(code);
        }
    }


    if(vkeys.size() == 2)
    {
       send_key2(vkeys, false);
       send_key2(vkeys, true);
    }
    if(vkeys.size() == 3)
    {
        send_key3(vkeys, false);
        send_key3(vkeys, true);
    }
    if(vkeys.size() == 1)
    {
        send_key2(vkeys, false);
    }
}


Delays InterpreterWin64::parseDelays(const QDomNode& node)
{
    Delays delays;

    delays.delay_fixed = node.toElement().attribute("delay_fixed", "1000").toFloat();
    delays.delay_random = node.toElement().attribute("delay_random", "1").toFloat();
    delays.repeat =  node.toElement().attribute("repeats", "1").toFloat();

    return delays;
}


QRect InterpreterWin64::parseRect(const QDomNode& node)
{
    QString value = node.toElement().attribute("area","QRect(1000,100,400,400)");
    QRegularExpression re("([\\d]+)");
    bool hasMatch = true;
    int pos = 0;
    QVector<int> args;
    while( hasMatch )
    {
        bool ok;
        QRegularExpressionMatch match = re.match(value, pos, QRegularExpression::NormalMatch);
        if (match.hasMatch()) {
            pos = match.capturedEnd(0);
            int i = match.captured(1).toInt(&ok);
            if (ok) args.push_back(i);
        }
        else hasMatch = false;
    }
    if( args.size() == 4)
        return QRect(args[0],args[1],args[2],args[3]);
    return  QRect();
}

QPoint GetMousePos()
{
    POINT mouse_pos;
    GetCursorPos(&mouse_pos);
    return QPoint(mouse_pos.x, mouse_pos.y);
}

void MouseClick(QPoint coordinates, Qt::MouseButton button)
{
    POINT mouse_pos;
    mouse_pos.x = coordinates.x();
    mouse_pos.y = coordinates.y();

    GetCursorPos(&mouse_pos);
    mouse_pos.x =  coordinates.x();
    mouse_pos.y =  coordinates.y();
    SetCursorPos(mouse_pos.x, mouse_pos.y);

    if( button == Qt::MouseButton::LeftButton )
    {
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN, mouse_pos.x, mouse_pos.y, 0, 0);
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP, mouse_pos.x, mouse_pos.y, 0, 0);
    }

    if( button == Qt::MouseButton::RightButton )
    {
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN, mouse_pos.x, mouse_pos.y, 0, 0);
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTUP, mouse_pos.x, mouse_pos.y, 0, 0);
    }

    if( button == Qt::MouseButton::MiddleButton )
    {
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MIDDLEDOWN, mouse_pos.x, mouse_pos.y, 0, 0);
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MIDDLEUP, mouse_pos.x, mouse_pos.y, 0, 0);
    }
}

void MouseClick(QRect rect, Qt::MouseButton button)
{
    int x = rect.left() + (float)rect.width() * ((float)rand())/RAND_MAX;
    int y = rect.top() + (float)rect.height() * ((float)rand())/RAND_MAX;
    MouseClick(QPoint(x,y), button);
}

/* Windows sleep in 100ns units */
BOOLEAN nanosleep(LONGLONG ns){
    /* Declarations */
    HANDLE timer;	/* Timer handle */
    LARGE_INTEGER li;	/* Time defintion */
    /* Create timer */
    if(!(timer = CreateWaitableTimer(NULL, TRUE, NULL)))
        return FALSE;
    /* Set timer properties */
    li.QuadPart = -ns;
    if(!SetWaitableTimer(timer, &li, 0, NULL, NULL, FALSE)){
        CloseHandle(timer);
        return FALSE;
    }
    /* Start & wait for timer */
    WaitForSingleObject(timer, INFINITE);
    /* Clean resources */
    CloseHandle(timer);
    /* Slept without problems */
    return TRUE;
}

void InterpreterWin64::MySleep(long delay)
{
    const auto MAX_DELAY_SEC = 20;

    this->elapsedTimer.restart();

    if(float(delay)/1000. > MAX_DELAY_SEC)
        return;
    while(1)
    {
        if( elapsedTimer.elapsed() > delay )
            return;
        nanosleep(1000*10); // sleep 10 microseconds
        QCoreApplication::processEvents(QEventLoop::AllEvents, MAX_DELAY_SEC);
    }

}

int InterpreterWin64::executeHotkey(const QDomNode& node)
{
    QString str;
    if( node.toElement().hasAttribute("hotkey") )
    {
        str = node.toElement().attribute("hotkey");
        str = str.replace(" ","");
        Key((char*)str.toLocal8Bit().toStdString().c_str());
    }


    return 1;
}

int InterpreterWin64::executeClick(const QDomNode& node)
{
    QString atr = node.toElement().attribute("button");
    Qt::MouseButton b;
    if (atr == "left")
        b = Qt::MouseButton::LeftButton;
    else
        b = Qt::MouseButton::RightButton;
    bool ok1,ok2;
    auto x = node.toElement().attribute("x").toInt(&ok1);
    auto y = node.toElement().attribute("y").toInt(&ok2);
    if(ok1 && ok2)
        MouseClick(QPoint(x,y), b);
    if( node.toElement().hasAttribute("area"))
    {
        QRect rect = parseRect(node);
        MouseClick(rect, b);
    }
    return 1;
}

QString removeTags(QString tag, QString withTags)
{
    QString tagEnd = "</" + tag + ">";
    //QRegularExpression re( QString("%1[\\w\\S\"]+ >").arg(tag) );
    int pos_end = withTags.indexOf(tagEnd);
    QString withoutTags = withTags.left(pos_end);
    int pos2 = withoutTags.indexOf(">") + 1;
    return withoutTags.mid(pos2, withoutTags.size() - pos2);
}

int InterpreterWin64::executeType(const QDomNode& node)
{

    QClipboard *clipboard = QGuiApplication::clipboard();
    //QString originalText = clipboard->text();
    QString text;
    if( node.toElement().hasAttribute("text") )
        text = node.toElement().attribute("text");
    else
        text = node.toElement().nodeValue();

    // COPY PASTE MODE
    if( node.toElement().hasAttribute("mode") )
    {
        auto mode = node.toElement().attribute("mode");
        if( mode == "copy_paste")
        {
            clipboard->setText(text);
            //clipboard->c
            Key("ctrl+v");
            return 0;
        }
    }
    // NORMAL TYPE SIMULATION MODE

    // get node value as text
    QString str;
    QTextStream ss(&str);
    ss << node;
    text = removeTags("type", ss.readAll());
    //show_message("node value", );

    for(auto c = text.begin(); c!=text.end(); c++)
    {
        char str[3];
        str[0] = (*c).toLatin1();
        str[1] = ' ';
        str[2] = '\0';

        Key(str);
        long delay = 1;
        MySleep(delay);

    }

    return 0;

}

void InterpreterWin64::stop()
{
    stopFlag = true;
}

// executeFunction NON RECURSIVE VERSION
void InterpreterWin64::executeFunction(QString function_name)
{
    if ( functionMap.find(function_name)!=functionMap.end())
    {
        QDomNode node = functionMap[function_name];
        if(node.hasChildNodes())
        {
            for(int i=0; i < node.childNodes().count(); i++)
            {
                QDomNode child = node.childNodes().at(i);
                execute(child);
                if( stopFlag )
                {
                    Log("EXIT executeFunction");
                    return;
                }
            }
        }
    }

}

void InterpreterWin64::resetStopFlag()
{
    stopFlag = false;
}

// executeFunction RECURSIVE VERSION
void InterpreterWin64::executeFunction(const QDomNode& rootNode, QDomNode funcNode, QString function_name)
{


    QDomNode domNode = rootNode.firstChild();
    QDomElement domElement;
    stopFlag = false;
    while(!(domNode.isNull()))
    {
        if(domNode.isElement())
        {
            domElement = domNode.toElement();
            if(!(domElement.isNull()))
            {
                QString name = domNode.nodeName();
                if(name == "func" && domElement.attribute("name") == function_name)
                   funcNode = domNode;
            }

        }
        if( stopFlag )
        {
            Log("EXIT executeFunction");
            return;
        }
        //getFunctionsList(domNode, outList);
        if( domNode.parentNode() == funcNode)
        {
            execute(domNode);
        }
        else
            executeFunction(domNode, funcNode, function_name);

        domNode = domNode.nextSibling();
    }


}

int InterpreterWin64::executeShellCommand(const QDomNode& node)
{
    QString cmd;
    QStringList args;
    if( node.toElement().hasAttribute("cmd") )
    {
        cmd = node.toElement().attribute("cmd");
        cmd = cmd.replace('`',"\"");
        args = cmd.split(" ");
            cmd = args[0];
        args.pop_front();
        ShellExecuteA(0, 0, (char*)cmd.toStdString().c_str(), (char*)args.join(" ").toStdString().c_str(), 0, SW_NORMAL);
    }
    return 0;
}

QString decodePath(QString filename)
{

    //$(UsefulClicker)/images/21.03.12.119.png
    QRegularExpression reVar("[$(]{2}([\\w_]+)[)]{1}");
    auto match = reVar.match(filename);
    QString clickerPath = QDir::currentPath();
    // change relative path ./ on absolute path
    auto pos = filename.indexOf("./")+1;
    if( pos > 0)
    {
        filename = clickerPath + filename.mid(pos,filename.size()-pos);
        return filename;
    }
    if( match.hasMatch() )
    {
        auto varname = match.capturedTexts()[1];
        filename = filename.replace("$(UsefulClicker)","");        
        clickerPath = qgetenv(varname.toStdString().c_str()).toStdString().c_str();
        if( qEnvironmentVariableIsEmpty(varname.toStdString().c_str()) )
            clickerPath = QDir::currentPath();
    }
    return clickerPath + filename;
}
//<clickimg area="Rect(330,645,229,56)" screenNum="0" targetImg="$(UsefulClicker)/images/21.03.12.119.png" button="left"> </clickimg>
int InterpreterWin64::executeClickImg(const QDomNode& node)
{
    QString targetImg_fn = decodePath(node.toElement().attribute("targetImg"));
    QString areaImg_path = QDir::currentPath() + "/images/";//decodePath(node.toElement().attribute("areaImg"));
    int screenNum = -1;
    if( node.toElement().hasAttribute("screenNum"))
        screenNum = node.toElement().attribute("screenNum").toInt();
    if( node.toElement().hasAttribute("kernel_size"))
       dsp->kernel_size = node.toElement().attribute("kernel_size").toInt();
    QString button = node.toElement().attribute("button");
    QString areImg_fn = areaImg_path + "areaImg.bmp";

    QFileInfo fi;
    if( !fi.exists(targetImg_fn) )
        return 0;


    /*
    QScreen* screen = QGuiApplication::screens()[screenNum];
    QImage screenshot = screen->grabWindow(0,0,0,screen->geometry().width(), screen->geometry().height()).toImage();
    cv::Mat areaImg(screenshot.height(), screenshot.width(),CV_8UC4, screenshot.bits());
    cvtColor( areaImg, areaImg, cv::COLOR_BGRA2BGR  );
    cv::imwrite(areImg_fn.toStdString(), areaImg);
    */

    //delete dsp;
    //dsp = new DspModule();

    dsp->searchImage(targetImg_fn.toStdString(), screenNum);
    if ( dsp->matchedRectangle.height() < 10 ) return 0;
    if ( dsp->matchedRectangle.width() < 10 ) return 0;

    if( button == "left" ||  button == "")
        MouseClick(dsp->matchedRectangle, Qt::MouseButton::LeftButton);
    if( button == "right")
        MouseClick(dsp->matchedRectangle, Qt::MouseButton::RightButton);

    return 0;
}

int InterpreterWin64::executeScrollUp(const QDomNode& node)
{
    ScrollUp();
    return 1;
}

int InterpreterWin64::executeScrollDown(const QDomNode& node)
{
    ScrollDown();
    return 1;
}


int InterpreterWin64::executeList(const QDomNode& node)
{
    QString filename = decodePath(node.toElement().attribute("filename"));
    QString name = node.toElement().attribute("name");
    QString sep = node.toElement().attribute("sep","\n");
    std::default_random_engine generator;

    QFile f(filename);
    std::vector<QString> str;
    str.reserve(1024*1024);

    // get node value as text
    QString str1;
    QTextStream ss(&str1);
    ss << node;
    QString tag_body = removeTags("list", ss.readAll());

    // load list from file
    if (f.open(QIODevice::ReadOnly))
    {
        QTextStream ts(&f);
        QStringList list;
        if(f.size() > 1024*1024)
        {
            std::uniform_int_distribution<int> distribution(0,f.size());
            int random_offset = distribution(generator);
            ts.seek(random_offset);
            ts.readLine(2000);
            str.push_back(ts.readLine(2000));
            random_offset = distribution(generator);
            ts.readLine(2000);
            str.push_back(ts.readLine(2000));
        }
        else
        {
            list = ts.readAll().split("\n");
            for( auto s: list)
                str.push_back(s);
            std::random_shuffle(str.begin(),str.end());
        }
        Globals::global_lists[name] = str;
        Globals::global_vars[name] = list;
    }
    else // load list from previous defined named lists (global_lists map)
    {
        QTextStream ts(&f);
        QStringList list = tag_body.split("\n");
        Globals::global_vars[name] = list;
        for( auto s: list)
            str.push_back(s);
        std::random_shuffle(str.begin(),str.end());
        if( Globals::global_lists.contains(name))
        {
            str = Globals::global_lists[name];
            //show_message("list found in global",name);
        }
        else
            Globals::global_lists[name] = str;
    }
    QString outputString;
    for( auto s: str)
        outputString+=s+"\n";
    QClipboard *clipboard = QGuiApplication::clipboard();
    QString function = node.toElement().attribute("f");
    if( function == "select_rand_word" )
    {
        if( str.size() > 0 )
        {
            std::uniform_int_distribution<int> distribution(0,str.size());
            int n = distribution(generator);  // generates number in the range 1..6
            outputString = str[n];
            Log("selecting " + outputString);
            Log2("list size = %d", str.size());
        }
    }
    clipboard->setText(outputString);
    //show_message("", filename);
    return 1;
}


int InterpreterWin64::executeDblClick(const QDomNode& node)
{
    executeClick(node);
    nanosleep(1000);
    executeClick(node);
}

int InterpreterWin64::executeCheck(const QDomNode& node)
{
    for(int i=0; i < node.attributes().count(); i++)
    {
        QDomNode attr = node.attributes().item(i);
        QString varName = attr.nodeName();
        if( Globals::global_vars.find(varName) != Globals::global_vars.end())
        {
            if ( Globals::global_vars[varName] == attr.nodeValue() )
            {
                QString str = "CHECK.... " + varName + "==" + attr.nodeValue();
                str += "........OK!";
                Log(str);
            }
            else
            {
                QString str = "CHECK.... " + varName + "!=" + attr.nodeValue() + "   ";
                str += varName + "=" + Globals::global_vars[varName].toString();
                str += "........FAIL!";
                Log(str);
            }
        }
    }
    return 0;
}

int InterpreterWin64::executeSet(const QDomNode& node)
{
    for(int i = 0; i < node.attributes().count(); i++)
    {
        QDomNode attr = node.attributes().item(i);
        QString varName = attr.nodeName();
        QString expression = attr.nodeValue();
        ExpressionCalculator calc;
        QString result;
        calc.compute(expression, result);
    }
    return 1;
}

// <foreach list="Thrillers_beetwen_1979-1989" range="10:100:1">
int InterpreterWin64::executeForeach(const QDomNode& node)
{
    QString list_name = node.toElement().attribute("list");
    QString range = node.toElement().attribute("range");
    QString do_fun = node.toElement().attribute("do");
    QStringList l = range.split(":");
    QStringList list = Globals::global_vars[list_name].toStringList();
    int from=0, to=list.size(), step=1;

    if( l.size() > 2 )
    {
        bool ok;
        from = l[0].toInt(&ok);
        if(!ok) return -1;
        to = l[1].toInt(&ok);
        if(!ok) return -1;
        if( l.size() == 3 )
            step = l[2].toInt(&ok);
        if(!ok) return -1;
    }

    for(int idx=from; idx < to; idx+=step)
    {
        QString val = list[idx];
        val = val.replace("\r","");
        val = val.replace("\n","");
        Globals::global_vars["i"] = val;
        executeFunction(do_fun);
    }
    return 1;
}


int InterpreterWin64::executeClickRect(const QDomNode& node)
{
    QString button;
    RectangleDescriptor d;

    d.fromDomNode(node);
    int kernel = node.toElement().attribute("kernel_size", "4").toInt();
    int screen = node.toElement().attribute("screen_num", "0").toInt();

    dsp->searchRect(screen, kernel, d);

    if ( dsp->matchedRectangle.height() < 10 ) return 0;
    if ( dsp->matchedRectangle.width() < 10 ) return 0;

    QString s = QString("executeClickRect %1 %2").arg(dsp->matchedRectangle.center().x())
                      .arg(dsp->matchedRectangle.center().y());
    //Log(s);

    if( button == "left" ||  button == "")
        MouseClick(dsp->matchedRectangle, Qt::MouseButton::LeftButton);
    if( button == "right")
        MouseClick(dsp->matchedRectangle, Qt::MouseButton::RightButton);


    return 0;
}

std::map<std::string, method_t> interpreter_func_map{{"click",&InterpreterWin64::executeClick},
                                {"type",&InterpreterWin64::executeType},
                                {"shell",&InterpreterWin64::executeShellCommand},
                                {"foreach",&InterpreterWin64::executeForeach},
                                {"list",&InterpreterWin64::executeList},
                                {"set",&InterpreterWin64::executeSet},
                                {"check",&InterpreterWin64::executeCheck},
                                {"clickrect",&InterpreterWin64::executeClickRect},
                                {"clickimg",&InterpreterWin64::executeClickImg},
                                {"dblclick",&InterpreterWin64::executeDblClick},
                                {"scrollup",&InterpreterWin64::executeScrollUp},
                                {"scrolldown",&InterpreterWin64::executeScrollDown},
                                {"hotkey",&InterpreterWin64::executeHotkey}};

int InterpreterWin64::execute(const QDomNode& node)
{
    QString name = node.toElement().tagName().toLocal8Bit();
   // if( !validNodes.contains( name  ) ) return -1;


    //
    int repeats = ATTR("repeats").toInt();
    int n = 0;
    QDomNode node_with_vars;

    while(n < repeats)
    {
       if( stopFlag )
       {
           return 0;
       }
       if(n == 0) node_with_vars = populateVars(node);
       // find method in table by name of xml node
       auto kv = interpreter_func_map.find(name.toStdString());
       QString str1, str2;
       QTextStream ss(&str1);
       ss << "EXEC --->" << node;
       ss << "EXEC with VARS--->" << node_with_vars;
       //ss << "PARENT NODE ----------------> ";
       //ss << node.parentNode();
       Log(ss.readAll());

       // call the method
       if( kv != interpreter_func_map.end())
       {

             (this->*(kv->second))(node_with_vars);

             // check that there is no no_delay flag
            if( !node.parentNode().toElement().hasAttribute("no_delay") )
            {
                 // make a delay
                 currentDelays = parseDelays(node);
                 long delay = currentDelays.delay_fixed + (currentDelays.delay_random * (float)rand()/RAND_MAX);
                 //qDebug() << "delay " << delay;
                 MySleep(delay);
            }
            //QThread::msleep(delay);
            //nanosleep(delay * 10e6);
            emit setCurrentNode(node, currentDelays);

       }
       else
       {
            Log("unknown tag at line 34: " + name);


       }

       n++;
    }

    return 0;
}
