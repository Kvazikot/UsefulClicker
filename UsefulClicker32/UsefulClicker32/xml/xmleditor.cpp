#include <QTextStream>
#include <QRegularExpression>
#include "xmleditor.h"
#include "settings/clickersettings.h"
#include "tests/highlighter.h"

static Highlighter* highlighter;

XmlEditor::XmlEditor(QWidget *parent)
    : QTextEdit{parent}
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);
    //connect(editor, SIGNAL(textChanged()), this, SLOT(textChanged()));
    setFont(font);
    setReadOnly(false);

    highlighter = new Highlighter(document());
    connect(this, SIGNAL(textChanged()), this, SLOT(onTextChange()));

}

void XmlEditor::keyPressEvent(QKeyEvent* event)
{
    event->accept();
    QTextEdit::keyPressEvent(event);

    // swap neibour text lines
    if( event->key() == Qt::Key::Key_Up
            && event->modifiers().testFlag( Qt::ControlModifier ) )
    {
        QString xml = toPlainText();
        auto lines = xml.split("\n");
        int sum=0, i=0;
        int cursorPos = textCursor().position();
        for(auto l : lines)
        {
            sum+=l.size();
            if( sum > cursorPos )
            {
                cursorPos = xml.indexOf(l);
                //mark line
                //textCursor().beginEditBlock()
                //textCursor().removeSelectedText();
                //selectAll()
                QList<QTextEdit::ExtraSelection> selections;
                auto cursor = textCursor();
                cursor.select(QTextCursor::LineUnderCursor);
                QTextFormat format;
                QTextEdit::ExtraSelection es;
                es.format.setBackground(Qt::red);
                es.cursor = cursor;
                selections.push_back(es);
                setExtraSelections(selections);
                break;
            }
            i++;
        }
        //swap 2 adjacment lines
        //qSwap(lines[i],lines[i-1]);
        textCursor().insertText(lines[i-1]+"\n");
        cursorPos = textCursor().position();
        textCursor().setPosition(cursorPos+lines[i-1].size());
        textCursor().insertText(lines[i]+"\n");
        //textCursor().setPosition(cursorPos);
    }

    if( event->key() == Qt::Key::Key_Z
            && event->modifiers().testFlag( Qt::ControlModifier ) )
        document()->undo();

}

void XmlEditor::enableChangeEvent(bool enableFlag)
{
   enableChangeFlag = enableFlag;
}

void XmlEditor::setFuncNode(const QDomNode& node)
{
    currentNode = node;
    original_xml = "";
    QTextStream ts(&original_xml);
    node.save(ts, 0);
    funcname = cutFunctionName(original_xml);
}

void XmlEditor::applyChanges()
{
    funcname = cutFunctionName(original_xml);
    doc->setFunction(funcname, toPlainText());
}

QString XmlEditor::cutFunctionName(QString& xml)
{
   // QRegularExpression re("[<]{0,1}func.*name=(.*)[>]{1}");
    QRegularExpression re("<func name=\"([\\w _\\d]+)\"");
    QRegularExpressionMatch match = re.match(xml);
    if( match.hasMatch() )
    {
        QString name = match.capturedTexts()[1];
        name = name.replace("\"","");
        return name;
    }
    else
        emit updateStatusBar("Function name error!", false);
    return genFunName();
}


void XmlEditor::setXml(QString xml)
{
    if( xml.size() > 0 )
    {
        setText(xml);
        //show_message("original_xml", original_xml);
        //show_message("xml", xml);
    }

}

void XmlEditor::onTextChange()
{
    iamChanged = true;
    bool applyChangesFlag=true;
    QString str;

    if( !enableChangeFlag )
        return;

    QTextStream ts(&str);
    currentNode.save(ts, 0);
    if (str != toPlainText())
        applyChangesFlag = true;

    QString xml = toPlainText();

    if( !doc->checkXmlSyntax(xml) )
        emit updateStatusBar("Xml error!", applyChangesFlag);
    else
        emit updateStatusBar("Xml OK!", applyChangesFlag);


}

void XmlEditor::newFun(QString name)
{
    QString initialXml = QString("<func name=\"%1\">\n</func>").arg(name);
    setText(initialXml);
}

QString XmlEditor::genFunName()
{
    QString randFunctionName = QString("func%1").arg(rand()%10000);
    return randFunctionName;
}

void XmlEditor::setDoc(ClickerDocument* doc)
{
    this->doc = doc;
}
