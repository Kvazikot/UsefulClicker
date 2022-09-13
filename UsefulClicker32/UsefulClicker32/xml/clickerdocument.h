#ifndef CLICKERDOCUMENT_H
#define CLICKERDOCUMENT_H

#include <QDomDocument>
#include <QStringList>
// -------------------------------------------------------------------------------

class ClickerDocument : public QDomDocument
{
public:
    bool isLoaded;
    QStringList filters;
    QDomDocument original_document;
    explicit ClickerDocument(QString filename);
    explicit ClickerDocument();
    QDomNode filter(QDomNode rootNode);
    QString getContent(QDomDocument& document);
    QDomNode createNodeFromString(QString xml);
    void getFunctionsList(const QDomNode& rootNode, QStringList& outList);
    QDomNode findNodeByName(const QDomNode& rootNode, QString name);
    QString getFunction(QString funcname);
    bool checkXmlSyntax(QString xml );
    bool setFunction(QString funcname, QString text);
    bool setContent(QDomDocument& document, QString& text);
    void format_document(QTextStream& ts);
    void format_document(QString& text);
    void Save(QTextStream& ts);
    void reload();
    bool load(QString fn);
    bool save(QString fn);
    ~ClickerDocument();

};



#endif // CLICKERDOCUMENT_H
