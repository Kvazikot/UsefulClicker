#ifndef XMLSTREAMER_H
#define XMLSTREAMER_H

#include <QObject>
#include <QDomNode>

class XmlStreamerKey : public QString
{
public:
    XmlStreamerKey(){}
    XmlStreamerKey(QString key)
        : QString(key)
    {}
};

class XmlStreamer
{
public:

    XmlStreamer();
    QRect read(QString key);
    void write(QString key, QRect r);
    void setCurrentNode(QDomNode node);
    int parseAttributes(QString attr_str);

    XmlStreamer& operator<<(QString value);
    XmlStreamer& operator<<(QRect r);
    XmlStreamer& operator<<(XmlStreamerKey k);

private:
    QDomNode currentNode;
    XmlStreamerKey  currentKey;

};

#endif // XMLSTREAMER_H
