#ifndef XMLEDITOR_H
#define XMLEDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QKeyEvent>
#include <QDomNode>
#include "clickerdocument.h"
#include "tests/highlighter.h"

class XmlEditor : public QTextEdit
{
    Q_OBJECT
public:
    explicit XmlEditor(QWidget *parent = nullptr);
    void setDoc(ClickerDocument* doc);
    void setFuncNode(const QDomNode& node);
    void setXml(QString xml);
    QString genFunName();
    void newFun(QString name);
    void applyChanges();
    void enableChangeEvent(bool enableFlag);
    void keyPressEvent(QKeyEvent* event) override;
    QString cutFunctionName(QString& xml);
public slots:
    void onTextChange();

signals:
    void updateStatusBar(const QString& xmlErrorMessage, bool applyChangesFlag);

public:
   bool iamChanged;
   Highlighter* highlighter;

private:
   ClickerDocument* doc;   
   QString funcname;
   QDomNode currentNode;
   bool enableChangeFlag;
   QString original_xml;

};

#endif // XMLEDITOR_H
