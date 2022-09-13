#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>
#include "settings/clickersettings.h"
#include "clickerdocument.h"

ClickerDocument::ClickerDocument()
{

}

ClickerDocument::ClickerDocument(QString fullpath)
    : QDomDocument()
{
    load(fullpath);
}

bool ClickerDocument::load(QString fn)
{
    QString filename = fn;

    QDomDocument doc(filename);
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "cannot open " << filename;
        isLoaded = false;
        return false;
    }
    if (!doc.setContent(&file)) {
        file.close();
        qDebug() << "xml error";
        isLoaded = false;
        return false;
    }
    file.close();

    QDomDocument& this_reference = *this;
    this_reference = doc;
    original_document = doc;
    isLoaded = true;


    if( _F("hideAllNonClickerTags") )
    {
        filters = {"shell", "code", "include"};
        filters.push_back("shell");
        filters.push_back("code");



    }
    return true;
}

QString ClickerDocument::getFunction(QString funcname)
{
    QDomNode domNode = findNodeByName(this->documentElement(), funcname);
    if(domNode.isNull()) return "";
    QString str;
    QTextStream stream(&str);
    domNode.save(stream, 0);
    return str;
}

QDomNode ClickerDocument::createNodeFromString(QString xml)
{
    QDomDocument* doc = new QDomDocument();
    //xml = "<?xml version='1.0'?><xml>" + xml + "</xml>";
    if( doc->setContent( xml ) )
    {
        QDomElement root = doc->documentElement();
        return root.firstChild();
    }
    return  QDomNode();
}

bool ClickerDocument::checkXmlSyntax(QString xml )
{
    QDomNode node;
    return node.toDocument().setContent(xml);
}

bool ClickerDocument::setFunction(QString funcname, QString new_function_body)
{
    QString content_of_all_document = this->toString(4);

    if( !checkXmlSyntax(new_function_body))
        return false;

    //1. replace function body from content_of_all_document on new_function_body
    //2. create dom document from that string
    QString substring = "name=\"" + funcname + "\"";
    int pos = content_of_all_document.indexOf(substring);
    if( pos!=-1 )
    {
        // !!! this solution do not work with matryoshka functions
        auto content_before = content_of_all_document.mid(0, pos);
        auto tagBegin = content_before.lastIndexOf("<func");
        auto tagEnd = content_of_all_document.indexOf("</func>", pos) + 7;
        auto tmp = content_of_all_document.mid(tagBegin, tagEnd - tagBegin);
        content_before = content_of_all_document.left(tagBegin);
        int n = content_of_all_document.size() - tagEnd;
        auto content_after =  content_of_all_document.right(n);
        tmp = content_before + new_function_body + content_after;
        show_message("inserted function!", tmp);
        setContent(*this, tmp);
        return true;
    }
    return false;
}

QDomNode ClickerDocument::findNodeByName(const QDomNode& rootNode, QString name)
{
    QDomNode domNode = rootNode.firstChild();
    QDomElement domElement;
    while(!(domNode.isNull()))
    {
        if(domNode.isElement())
        {
            domElement = domNode.toElement();
            if(!(domElement.isNull()))
            {
                if( name == domElement.attribute("name"))
                    return domNode;
            }

        }
        findNodeByName(domNode, name);
        domNode = domNode.nextSibling();
    }
    return domNode;
}

void ClickerDocument::getFunctionsList(const QDomNode& rootNode, QStringList& outList)
{
    QDomNode domNode = rootNode.firstChild();
    QDomElement domElement;
    while(!(domNode.isNull()))
    {
        if(domNode.isElement())
        {
            domElement = domNode.toElement();
            if(!(domElement.isNull()))
            {
                QString name = domNode.nodeName();
                if(name == "func")
                    outList.push_back(domElement.attribute("name"));
            }

        }
        getFunctionsList(domNode, outList);
        domNode = domNode.nextSibling();
    }
}

QString ClickerDocument::getContent(QDomDocument& document)
{
    return document.toString();
}

bool ClickerDocument::setContent(QDomDocument& document, QString& text)
{
    format_document(text);
    return document.setContent(text);
}

void ClickerDocument::Save(QTextStream& ts)
{
    format_document(ts);
    ts <<  getContent(original_document);
}

bool ClickerDocument::save(QString fn)
{
    QDomDocument* dom_doc = static_cast<QDomDocument*>(this);
    QFile file(fn);
    if( file.open(QFile::WriteOnly) )
    {
        QTextStream ts(&file);
        dom_doc->save(ts, 4);
        return true;
    }
    return false;
}


void Fix_line(QString& line)
{
    QMap<QString, QString> key_value;
    QRegularExpression re("[\\s]{0,1}([\\w]+)(=)([\"]{0,1}[\\w\\s\\d(,).]+[\"]{0,1})");
    //
    int n_attrs = 0;
    int pos = 0;
    bool hasMatch = true;
    while( hasMatch )
    {
        QRegularExpressionMatch match = re.match(line, pos, QRegularExpression::NormalMatch);
        if (match.hasMatch()) {
            pos = match.capturedEnd(0);
            QStringList lst = match.capturedTexts();
            int i = 0;
            for(auto s : lst)
            {
                //qDebug() << "________" << lst.join(" ").replace(QChar('"'),QChar(' '));
                qDebug() << i << " " <<  s ;
                i++;
            }
            n_attrs++;
            hasMatch = true;
            QString key = lst[1];
            key.replace(QChar('"'),QChar(' ')).replace(" ","");
            QString value1 = lst[3];
            value1.replace(QChar('"'),QChar(' ')).replace(" ","");
            key_value[key] = value1;
            //line.remove(match.capturedStart(1), match.capturedLength(1));
            //line.remove(match.capturedStart(2), match.capturedLength(2));
            //line = line.replace(key,"");
            //qDebug() << line;
        }
        else
            hasMatch = false;
    }

    for( auto k : key_value)
    {
        qDebug() << k << " " << key_value[k];
    }
}

void ClickerDocument::format_document(QTextStream& ts)
{
    while(!ts.atEnd())
    {
        QString line  = ts.readLine();
        Fix_line(line);
    }
}

void ClickerDocument::reload()
{
    QString text = getContent(original_document);
    // pass xml to a custom parser to check that everything
    // satisfies UsefulClicker notation
    auto doc_ref = static_cast<QDomDocument*>(this);
    setContent(*doc_ref, text);
}


void ClickerDocument::format_document(QString& text)
{
    //This uses a C++11 raw string literal to create a regex that matches all three possibilities:
    //CR only (Mac)
    //CR+LF (Win)
    //LF (Unix)
    QRegularExpression re{R"-((\r\n?|\n))-"};

    //split text by line endings
    QStringList lines = text.split(re);

    for(QString& line : lines)
        Fix_line(line);
    text = lines.join("\n");
}

QDomNode ClickerDocument::filter(QDomNode rootNode)
{
    QDomDocument& this_reference = *this;
    this_reference = original_document;
    QDomNode n = rootNode;
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {
            for(QString& f: filters)
            {
                if(e.tagName().contains(f))
                {
                    qDebug() << qPrintable(e.tagName()) << "filtered out \n"; // the node really is an element.
                    //delete e;
                }
            }
            for(int i=0; i <  e.childNodes().count(); i++)
                filter(e.childNodes().at(i));
        }
        n = n.nextSibling();
    }
    return n;
}


ClickerDocument::~ClickerDocument()
{

}
