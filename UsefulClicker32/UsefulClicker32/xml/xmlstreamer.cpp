
#include <QDebug>
#include <QDomDocument>
#include <QRegularExpression>
#include <QRect>
#include "xmlstreamer.h"

XmlStreamer::XmlStreamer()
{
    QDomDocument* doc = new QDomDocument("testDocument");
    QString content = "<xml><mouse area=\"QRect(1,2,3,4)\"/></xml>";
    doc->setContent(content, false);
    setCurrentNode(doc->firstChild().firstChild());
    currentNode.toElement().setAttribute("area", "QRect(1,2,3,4)");
    // some hot tests
    write("area", QRect(1,2,3,4));
    QRect r = read("QRect(1,2,3,4)");
    qDebug() << r;

}

void XmlStreamer::setCurrentNode(QDomNode node)
{
    currentNode = node;
}

QRect XmlStreamer::read(QString key)
{
    QString value = currentNode.toElement().attribute(key,"QRect(1000,100,400,400)");
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
            qDebug() << i;
            if (ok) args.push_back(i);
        }
        else hasMatch = false;
    }
    if( args.size() == 4)
        return QRect(args[0],args[1],args[2],args[3]);
    return  QRect();
}

void XmlStreamer::write(QString key, QRect r)
{
    currentKey = key;
    QString value =  QString::asprintf("QRect(%d,%d,%d,%d)", r.left(), r.right(), r.width(), r.height());
    qDebug() << " XmlStreamer::write " << value;
    currentNode.toElement().setAttribute(key, value);
}

int XmlStreamer::parseAttributes(QString attr_str)
{
    QRegularExpression re("([\\S]+)[=]([\\S]+)");

    QString& value = attr_str;

    int pos = 0;
    int n_attrs = 0;
    bool hasMatch = true;
    while( hasMatch )
    {
        QRegularExpressionMatch match = re.match(value, pos, QRegularExpression::NormalMatch);
        if (match.hasMatch()) {
            pos = match.capturedEnd(0);
            n_attrs++;
            hasMatch = true;
            QString key = match.captured(1);
            QString value1 = match.captured(2);
            if(value1.contains("\""))
               value1 = value1.mid(1, value1.size()-2);
            if(key.contains("\""))
                key = key.mid(1, value1.size()-2);

            qDebug() << "readed " << key << " " << currentNode.toElement().attribute(key);
            currentNode.toElement().setAttribute(key, value1);
            qDebug() << key << " " <<  value1 << ",";
        }
        else
            hasMatch = false;
    }
    return n_attrs;
}



