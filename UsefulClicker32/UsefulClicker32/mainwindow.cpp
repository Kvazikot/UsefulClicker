/*
+ - - - + - + - -
+ - + - + copyright by Vladimir Baranov (Kvazikot)  <br>
+ - + - + email: vsbaranov83@gmail.com  <br>
+ - + - + github: https:/images//github.com/Kvazikot/UsefulClicker/  <br>
```
                          )            (
                         /(   (\___/)  )\
                        ( #)  \ ('')| ( #
                         ||___c\  > '__||
                         ||**** ),_/ **'|
                   .__   |'* ___| |___*'|
                    \_\  |' (    ~   ,)'|
                     ((  |' /(.  '  .)\ |
                      \\_|_/ <_ _____> \______________
                       /   '-, \   / ,-'      ______  \
              b'ger   /      (//   \\)     __/     /   \
                                          './_____/
```
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings/clickersettings.h"
#include "xml/clickerdocument.h"
#include "interpreter/interpreter.h"
#include "interpreter/interpreterwin64.h"
#include "ui/aboutbox.h"
#include "ui/dialogtype.h"
//#include "log/logger.h"

#include <QDateTime>
#include <QDebug>
#include <QPushButton>
#include <QComboBox>
#include <QToolBar>
#include <QLabel>
#include <QInputDialog>
#include <QFileDialog>

MainWindow* MainWindow::instance;
static QPushButton* applyButton = 0;
static QPushButton* apply_button2 = 0;
static QLabel* errorLabel = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("UsefulClicker");
    instance = this;
    logWindow = 0;
    pauseFlag = false;
    startTimer(50);
    current_filename = DEFAULT("last_sheme").toString();

    //----------------------------------------------------
    // setting up default xml doc
    QString xml = "<?xml version='1.0'?> <xml error=\"This is default document. Make sure you load right xml.\">  </xml>";
    bool ok  = (*(QDomDocument*)&defaultDoc).setContent(xml);
    qDebug() << "defaultDoc.setContent " << ok;
    setDoc(&defaultDoc);
    disableCursorMove = false;

    loadDocument(current_filename);
    //--------------------------------------------------------------------
    ClickerSettings::getInstance()->reload();
    interpreter = new InterpreterWin64();
    interpreter->init(*getDoc());

    //--------------------------------------------------------------------

    QToolBar* toolbar = new QToolBar(this);
    playAction =  toolbar->addAction(QIcon(":/images/play.png"), "Play");
    pauseFlag = true;

    QAction* refreshAction =  toolbar->addAction(QIcon(":/images/refresh-icon.png"), "Refresh");
    connect(refreshAction, &QAction::triggered, this, &MainWindow::reload);

    QLabel* label = new QLabel(this);
    label->setText("<b>Fucntion List</b>-->");

    functionSelector = new QComboBox(this);
    QStringList list;
    getDoc()->getFunctionsList(doc->documentElement(),list);
    functionSelector->addItems(list);
    functionSelector->setMinimumWidth(200);
    toolbar->addWidget(label);
    toolbar->addWidget(functionSelector);
    connect(functionSelector, SIGNAL(currentTextChanged(const QString&)), this, SLOT(functionSelected(const QString&)));

    QAction* newFunAction =  toolbar->addAction(QIcon(":/images/new_fun.png"), "New fun");
    connect(newFunAction, &QAction::triggered, this, &MainWindow::new_fun);

    QLabel* xmlEditorStatus = new QLabel(this);
    connect(ui->xmlEditor, SIGNAL(updateStatusBar(const QString&, bool)), this, SLOT(updateStatus(const QString&, bool)));
    connect(ui->xmlEditor_2, SIGNAL(updateStatusBar(const QString&, bool)), this, SLOT(updateStatus(const QString&, bool)));
    //connect(xmlEditor, SIGNAL(textChanged()), this, SLOT(updateFunctionEditor()));
    //updateStatusBar
    statusBar()->addWidget(xmlEditorStatus);

    connect(ui->xmlEditor, SIGNAL(textChanged()), this, SLOT(xmlChanged()));

    connect(ui->xmlEditor_2, SIGNAL(cursorPositionChanged()), this, SLOT(xml2CursorChanged()));

    ui->xmlEditor_2->setReadOnly(false);

    connect(playAction, &QAction::triggered, this, &MainWindow::pause);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openXml);
    addToolBar(toolbar);
    //connect(ui->exitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    //connect(ui->actionsMenu, &QMenu::aboutToShow, this, &MainWindow::updateActions);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    //connect(ui->actionSave, &QAction::triggered, this, &MainWindow::save);

}

void MainWindow::openXml()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setDirectory(QDir::currentPath() + "/xml");
    QStringList fileNames;
    if (dialog.exec())
    {
        fileNames = dialog.selectedFiles();
        if( fileNames.size()>0 )
          loadDocument(fileNames[0]);
    }

}

void MainWindow::xmlChanged()
{
    qDebug() << "xml changed!";
}

void MainWindow::updateStatus(const QString& text, bool applyChangesFlag)
{
    if( text.contains("error"))
    {
        if(errorLabel!=0)
        {
            statusBar()->removeWidget(errorLabel);
            delete errorLabel;
            errorLabel = 0;
        }
        errorLabel = new QLabel(this);
        errorLabel->setText(text);
        errorLabel->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255, 255, 255);");
        statusBar()->addWidget(errorLabel, width()-errorLabel->width());

    }
    else
    {
        if(errorLabel!=0)
        {
            statusBar()->removeWidget(errorLabel);
            delete errorLabel;
            errorLabel = 0;
        }
        if( applyChangesFlag && applyButton == 0 )
        {
            applyButton = new QPushButton(this);
            applyButton->setText("Apply changes");
            connect(applyButton, SIGNAL(clicked()), this, SLOT(applyChangesXml()));
            statusBar()->addWidget(applyButton, width()-applyButton->width());

        }
    }


}

void MainWindow::applyChangesXml()
{
    // update model from main XML editor
    if( ui->xmlEditor_2->iamChanged )
    {
        if( current_filename.isNull() || current_filename.contains(":/tests") )
            current_filename = "temp.xml";
        QFile f( current_filename );
        if( !f.open( QFile::WriteOnly | QFile::Truncate ) )
        {
            qDebug() << "Cannot open file " + current_filename;
            return ;
        }
        QTextStream ts(&f);
        ts << ui->xmlEditor_2->toPlainText();
        f.close();
        QString xml = ui->xmlEditor_2->toPlainText();

        if( !doc->checkXmlSyntax(xml) )
            emit ui->xmlEditor->updateStatusBar("Xml error!", false);
        else
        {
            emit ui->xmlEditor->updateStatusBar("Xml OK!", true);
            reloadFromFile(current_filename);
        }


    }
    // remove button from status Bar
    statusBar()->removeWidget((QWidget*)applyButton);
    applyButton = 0;

}

void MainWindow::xml2CursorChanged()
{
    QTextCursor cursor = ui->xmlEditor_2->textCursor();
    cursor.select(QTextCursor::LineUnderCursor);
    QString searchLine = cursor.selectedText();
    QStringList lines  = ui->xmlEditor_2->toPlainText().split("\n");
    int line_number = 0;
    foreach(QString l, lines)
    {
        if( l.contains(searchLine) )
        {
            int n_max = line_number;
            while(--n_max > 0)
            {
                if( lines[n_max].contains("<func ") )
                {
                    // QRegularExpression re("[<]{0,1}func.*name=(.*)[>]{1}");
                     QRegularExpression re("<func name=\"([\\w _\\d]+)\"");
                     QRegularExpressionMatch match = re.match(lines[n_max]);
                     if( match.hasMatch() )
                     {
                         QString name = match.capturedTexts()[1];
                         name = name.replace("\"","");
                         //qDebug() << name;
                         n_max = -5;
                         disableCursorMove = true;
                         int index = functionSelector->findText(name);
                         if ( index != -1 ) { // -1 for not found
                             functionSelector->setCurrentIndex(index);
                         }
                         disableCursorMove = true;
                         break;
                     }
                }
            }
            if( n_max == -5) break;

            break;
        }
        line_number++;
    }
}

void MainWindow::updateFunctionEditor()
{
    auto func_body_text = getDoc()->getFunction(functionSelector->currentText());
    ui->xmlEditor->clear();
    ui->xmlEditor->setText(func_body_text);
}

void MainWindow::XmlStringFromUniversalDialog(QMap<QString,QString> attrs_map)
{
    QString xml_string;
    auto event = attrs_map["event"];
    bool withDelayFlag = attrs_map["withDelayFlag"].toInt();
    if(withDelayFlag)
    {
        if(event == "hotkey")
            xml_string = QString("<hotkey hotkey=\"%1\" delay_fixed=\"%2\" delay_random=\"%3\" repeats=\"%4\" />")
                        .arg(attrs_map["hotkey"])
                        .arg(attrs_map["delay_fixed"])
                        .arg(attrs_map["delay_random"])
                        .arg(attrs_map["repeats"]);
        if(event == "click")
            xml_string = QString("<click button=\"%1\" x=\"%2\" y=\"%3\" delay_fixed=\"%4\" delay_random=\"%5\" repeats=\"%6\"/>")
                                .arg(attrs_map["button"])
                                .arg(attrs_map["x"])
                                .arg(attrs_map["y"])
                                .arg(attrs_map["delay_fixed"])
                                .arg(attrs_map["delay_random"])
                                .arg(attrs_map["repeats"]);
        if(event == "area")
            xml_string = QString("<click button=\"%1\" area=\"%2\" delay_fixed=\"%3\" delay_random=\"%4\" repeats=\"%5\"/>")
                                .arg(attrs_map["button"])
                                .arg(attrs_map["area"])
                                .arg(attrs_map["delay_fixed"])
                                .arg(attrs_map["delay_random"])
                                .arg(attrs_map["repeats"]);

        if(event == "scroll")
        {
            if( attrs_map["delta"].toInt() > 0)
                xml_string = QString("<scrollup delta=\"%1\" delay_fixed=\"%2\" delay_random=\"%3\" repeats=\"%4\"/>")
                             .arg(attrs_map["delta"])
                             .arg(attrs_map["delay_fixed"])
                             .arg(attrs_map["delay_random"])
                             .arg(attrs_map["repeats"]);

            else
                xml_string = QString("<scrolldown delta=\"%1\" delay_fixed=\"%2\" delay_random=\"%3\" repeats=\"%4\"/>")
                             .arg(attrs_map["delta"])
                             .arg(attrs_map["delay_fixed"])
                             .arg(attrs_map["delay_random"])
                             .arg(attrs_map["repeats"]);


        }
    }
    else // without delay attributes (default delay)
    {
        if(event == "hotkey")
            xml_string = QString("<hotkey hotkey=\"%1\" />")
                        .arg(attrs_map["hotkey"]);
        if(event == "click")
            xml_string = QString("<click button=\"%1\" x=\"%2\" y=\"%3\" />")
                                .arg(attrs_map["button"])
                                .arg(attrs_map["x"])
                                .arg(attrs_map["y"]);
        if(event == "area")
            xml_string = QString("<click button=\"%1\" area=\"%2\" />")
                                .arg(attrs_map["button"])
                                .arg(attrs_map["area"]);
        if(event == "scroll")
        {
            if( attrs_map["delta"].toInt() > 0)
                xml_string = QString("<scrollup delta=\"%1\" />")
                             .arg(attrs_map["delta"]);

            else
                xml_string = QString("<scrolldown delta=\"%1\" />")
                             .arg(attrs_map["delta"]);

            if( attrs_map["wheel_repeats"] != "0" )
            {
                if( attrs_map["delta"].toInt() > 0)
                    xml_string = QString("<scrollup delta=\"%1\"  repeats=\"%2\" />")
                                 .arg(attrs_map["delta"])
                                 .arg(attrs_map["wheel_repeats"]);

                else
                    xml_string = QString("<scrolldown delta=\"%1\"  repeats=\"%2\" />")
                                 .arg(attrs_map["delta"])
                                 .arg(attrs_map["wheel_repeats"]);
               modifyXmlString(xml_string);
               return;
            }

        }

    }

    insertXmlString(xml_string);
}

void MainWindow::insertXmlString(QString xml_string)
{
    QString xml = ui->xmlEditor->toPlainText();
    xml = xml.replace("\n</func>","\n"+xml_string+"\n</func>");
    ui->xmlEditor->setText(xml);
}

void MainWindow::modifyXmlString(QString xml_string)
{
    QString xml = ui->xmlEditor->toPlainText();
    QStringList lines = xml.split("\n");
    int idx = lines.size()-3;
    if(idx>0)
      lines[idx] = xml_string;
    ui-> xmlEditor->setText(lines.join("\n"));
}

void replaceLines(QStringList& lines, QStringList new_lines, int start, int end)
{
    int line_number = 0;
    foreach( QString l, lines)
    {
        if(line_number >= start && line_number <=end)
        {
            int i = line_number - start;
            if ( i < new_lines.size() )
                lines[line_number] = new_lines[i];
        }
        line_number++;

    }

}

void locateFunction(QStringList lines, QString func_name, int& out_start_line, int& out_end_line)
{
    int line_number = 0;
    out_start_line = -1;
    out_end_line = -1;
    foreach(QString l, lines)
    {
        QRegularExpression re("<func name=\"([\\w _\\d]+)\"");
        QRegularExpressionMatch match = re.match(l);
        if( match.hasMatch() )
        {
            QString name = match.capturedTexts()[1];
            name = name.replace("\"","");
            if( name == func_name)
                out_start_line = line_number;
        }
        if (l.contains("</func>") && out_start_line!=-1)
        {
            out_end_line = line_number;
            break;
        }
        line_number++;
    }
}

void getFunctionName(QStringList lines, QString& out_function_name)
{
    foreach(QString l, lines)
    {
        QRegularExpression re("<func name=\"([\\w _\\d]+)\"");
        QRegularExpressionMatch match = re.match(l);
        if( match.hasMatch() )
        {
            out_function_name = match.capturedTexts()[1];
            return;
        }
    }
}

void MainWindow::applyFunctionChanges()
{
    QStringList original_lines = ui->xmlEditor_2->toPlainText().split("\n");
    QStringList function_lines = ui->xmlEditor->toPlainText().split("\n");
    QString func_name;
    int start_line, end_line;
    getFunctionName(function_lines, func_name);
    func_name = func_name.replace("\"","");
    locateFunction(original_lines, func_name, start_line, end_line);
    replaceLines(original_lines, function_lines, start_line, end_line);
    qDebug() << "func_name is " <<  func_name;
    qDebug() << "located at " << start_line << ", " <<  end_line;

}

void MainWindow::slotSetAttrs(QMap<QString,QString> attrs_map)
{
    QString xml_string;
    //for()

    if( attrs_map.contains("event") )
    {
        XmlStringFromUniversalDialog(attrs_map);
        return;
    }

    QString act = last_action_triggered;
    if( act.contains("left click") )
    {
        xml_string = QString("<click button=\"left\" x=\"%1\" y=\"%2\" />")
                            .arg(attrs_map["x"])
                            .arg(attrs_map["y"]);
    }
    if( act.contains("right click") )
    {
        xml_string = QString("<click button=\"right\" x=\"%1\" y=\"%2\" />")
                            .arg(attrs_map["x"])
                            .arg(attrs_map["y"]);
    }

    if( act.contains("scroll down") )
    {
        xml_string = QString("<scrolldown repeats=\"5\" />");
    }

    if( act.contains("scroll up") )
    {
        xml_string = QString("<scrollup repeats=\"5\" />");
    }

    if( act.contains("Add keydown") )
    {
        xml_string = QString("<hotkey hotkey=\"ctrl + v\" delay_fixed=\"450\" repeats=\"6\" />");
    }

    if( act.contains("Area") )
    {
        xml_string = QString("<click button=\"left\" area=\"%1\" />").arg(attrs_map["area"]);
    }

    if( act.contains("image click") )
    {
        xml_string = QString("<clickimg targetImg=\"%1\" button=\"left\" delay_fixed=\"1000\"> </clickimg>").arg(attrs_map["targetImg"]);
    }


    if( act.contains("rectangle click") )
    {
        xml_string = QString("<clickrectn=\"%1\" button=\"left\" n=\"%2\" rect=\"200x140\" area_tolerance=\"5%%\" ratio_tolerance=\"2%%\"  /> ")
                     .arg(attrs_map["targetImg"])
                     .arg(attrs_map["targetImg"]);
    }

    if( act.contains("Add type") )
    {
        if(!attrs_map.contains("mode"))
            xml_string = QString("<type> %1 </type>").arg(attrs_map["text"]);
        else
            xml_string = QString("<type mode=\"%2\"> %1 </type>").arg(attrs_map["text"]).arg(attrs_map["mode"]);

    }

    if( act.contains("keydown") )
    {
        xml_string = QString("<hotkey hotkey=\"%1\" />").arg(attrs_map["hotkey"]);
    }


    insertXmlString(xml_string);


}


void MainWindow::functionSelected(const QString&)
{

    updateFunctionEditor();
    if( !disableCursorMove )
    {
        // select text in xmlEditor_2
        QTextDocument *document = ui->xmlEditor_2->document();
        QTextCursor c_start(document);
        c_start.setPosition(0, QTextCursor::MoveAnchor);
        c_start.setPosition(0, QTextCursor::KeepAnchor);
        QTextCursor c = document->find( functionSelector->currentText(), c_start);
        //c.movePosition(QTextCursor::Start);
        //show_message("",QString::number(c.position()) );
        ui->xmlEditor_2->moveCursor(QTextCursor::End);
        int start = c.selectionStart();
        int end   = c.selectionEnd();
        c.setPosition(end, QTextCursor::MoveAnchor);
        c.setPosition(start, QTextCursor::KeepAnchor);
        ui->xmlEditor_2->setTextCursor(c);

    }
    /*

    QList<QTextEdit::ExtraSelection> selections;
    auto cursor = xmlEditor_2->textCursor();
    int _startIndex = xmlEditor_2->toPlainText().indexOf(functionSelector->currentText());
    show_message("", QString::number(_startIndex));
    cursor.setPosition(_startIndex);
    //cursor.
    //cursor.select(QTextCursor::LineUnderCursor);
    xmlEditor_2->moveCursor(QTextCursor::End);

    QTextFormat format;
    QTextEdit::ExtraSelection es;
    es.format.setBackground(Qt::red);
    es.cursor = cursor;
    selections.push_back(es);
    xmlEditor_2->setExtraSelections(selections);

*/

}

void MainWindow::pause()
{
    pauseFlag = ! pauseFlag;

    if( pauseFlag )
    {
       playAction->setIcon(QIcon(":/images/play.png"));
       ui->PlayButton->setIcon(QIcon(":/images/play.png"));
    }
    else
    {
       playAction->setIcon(QIcon(":/images/pause.jpg"));
       ui->PlayButton->setIcon(QIcon(":/images/pause.jpg"));
       MainWindow* window = MainWindow::getInstance();
       QDomDocument* doc = static_cast<QDomDocument*>(window->getDoc());
       InterpreterWin64*  interpreter = (InterpreterWin64*)window->getInterpreter();
       connect(interpreter, SIGNAL(setCurrentNode(const QDomNode&,Delays)), this, SLOT(currentStep(const QDomNode&,Delays)));
       connect(this, SIGNAL(pause()), interpreter, SLOT(stop()));
       QString func_name = functionSelector->currentText();
       interpreter->executeFunction(doc->documentElement(), doc->documentElement(), func_name);
       playAction->setIcon(QIcon(":/images/play.png"));
       ui->PlayButton->setIcon(QIcon(":/images/play.png"));
       pauseFlag = ! pauseFlag;
    }

}

AbstractInterpreter* MainWindow::getInterpreter()
{
    return interpreter;
}

void MainWindow::new_fun()
{
    qDebug() << __FUNCTION__;
    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                         tr("Function name:"), QLineEdit::Normal,
                                         ui->xmlEditor->genFunName(), &ok);
    if (ok && !text.isEmpty())
        ui->xmlEditor->newFun(text);

}

ClickerDocument* MainWindow::getDoc()
{
    return doc;
}

void MainWindow::setDoc(ClickerDocument* _doc)
{
    doc = _doc;
    ui->xmlEditor->setDoc(doc);
    ui->xmlEditor_2->setDoc(doc);
}

void MainWindow::loadDocument(QString filename)
{
    current_filename = filename;
    if( !filename.contains("temp") )
        SAVE_DEFAULT("last_sheme", filename);
_load:
    ClickerDocument* doc = new ClickerDocument(filename);
    if( doc->isLoaded )
    {
        setDoc(doc);
        // set full text of documentt to XmlEditor_2
        QFile f(filename);
        if( !f.open( QFile::ReadOnly ) )
            qDebug() << "Cannot open file " + filename;
        QTextStream ts(&f);
        ts.setCodec("UTF-8");
        QString xml_text = ts.readAll();
        ui->xmlEditor_2->enableChangeEvent(true);
        QTextCursor cur = ui->xmlEditor_2->textCursor();
        int p = cur.position();
        ui->xmlEditor_2->setText(xml_text);
        // set cursor at last pos
        QTextCursor c(ui->xmlEditor_2->document());
        int start = c.selectionStart();
        int end   = c.selectionEnd();
        c.setPosition(end + p  ,QTextCursor::MoveAnchor);
        c.setPosition(start + p,QTextCursor::KeepAnchor);
        ui->xmlEditor_2->setTextCursor(c);
        ui->xmlEditor_2->moveCursor(QTextCursor::End);
    }
    else
    {
        QString filename = ".\\tests\\UsefulClicker_tests.xml";
        QFile f(filename);
        if ( f.exists() )
        {
            ClickerDocument* doc = new ClickerDocument(filename);
            if( doc->isLoaded )
            {
                setDoc(doc);
                // set full text of documentt to XmlEditor_2
                QFile f(filename);
                if( !f.open( QFile::ReadOnly ) )
                    qDebug() << "Cannot open file " + filename;
                QTextStream ts(&f);
                ts.setCodec("UTF-8");
                QString xml_text = ts.readAll();
                ui->xmlEditor_2->enableChangeEvent(true);
                QTextCursor cur = ui->xmlEditor_2->textCursor();
                int p = cur.position();
                ui->xmlEditor_2->setText(xml_text);
                // set cursor at last pos
                QTextCursor c(ui->xmlEditor_2->document());
                int start = c.selectionStart();
                int end   = c.selectionEnd();
                c.setPosition(end + p  ,QTextCursor::MoveAnchor);
                c.setPosition(start + p,QTextCursor::KeepAnchor);
                ui->xmlEditor_2->setTextCursor(c);
                ui->xmlEditor_2->moveCursor(QTextCursor::End);
            }

        }

    }
}

void MainWindow::about()
{
    AboutBox* aboutbox = new AboutBox(this);
    aboutbox->show();
}


void MainWindow::reload()
{

    reloadFromFile(current_filename);
}


// reload from file
void MainWindow::reloadFromFile(QString& filename)
{
    ClickerSettings::getInstance()->reload();
    current_filename = filename;
    loadDocument(current_filename);
}

MainWindow* MainWindow::getInstance()
{
    return instance;
}

void MainWindow::setLogWindow(QPlainTextEdit* wnd)
{
    logWindow = wnd;
}

void MainWindow::log(QString msg)
{
   if( logWindow )
   {
       //insertPlainText
       auto cursor = logWindow->textCursor();
       cursor.movePosition(QTextCursor::Start);
       QString time = QDateTime::currentDateTime().toString("[hh:mm:ss.zzz] ");
       cursor.insertText(time + msg + "\n");
       cursor.movePosition(QTextCursor::Start);
       logWindow->setTextCursor(cursor);
   }
   else
       cached_messages.push_back(msg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_leftClick_clicked()
{
    last_action_triggered = "left click";
    createDialog(this, DialogType::MOUSE_DIALOG, "click");
}

void MainWindow::on_keyboardClick_clicked()
{
    last_action_triggered = "hotkey";
    createDialog(this, DialogType::MOUSE_DIALOG, "hotkey");
}


void MainWindow::on_areaClick_clicked()
{
    last_action_triggered = "Area click";
    createDialog(this, DialogType::AREA_SELECTOR);
}

void MainWindow::on_imageClick_clicked()
{
    last_action_triggered = "Add image click";
    createDialog(this, DialogType::SCREEN_BUTTONS_DETECTOR);
}


void MainWindow::on_typeTag_clicked()
{
    last_action_triggered =  "Add type";
    createDialog(this, DialogType::TYPE_DIALOG);
}


void MainWindow::on_rectClick_clicked()
{
    last_action_triggered = "Add rectangle click";
    createDialog(this, DialogType::SCREEN_BUTTONS_DETECTOR, "rect_mode");
}




void MainWindow::on_PlayButton_clicked()
{
    //applyChangesXml();
    applyFunctionChanges();
    //pause();
}
