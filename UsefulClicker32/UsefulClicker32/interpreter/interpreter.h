/*
+ - - - + - + - -
+ - + - + copyright by Vladimir Baranov (Kvazikot)  <br>
+ - + - + email: vsbaranov83@gmail.com  <br>
+ - + - + github: https:/images//github.com/Kvazikot/UsefulMacro/  <br>
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


#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <QThread>
#include <QObject>
#include <QDomDocument>
#include <QDomNode>
//#include <QModelIndex>
//#include "clickermodel.h"
//-----------------------------------------------------
// В этом файле реализация интерпретатора кликера под виндовс
// Позднее я сделаю абстрактный платформонезависимый интерфейс
// И вынесу платформозависимую часть в отдельный файл
//-----------------------------------------------------
void hotKey(char* hot_key);
void MouseClick(QPoint coordinates, Qt::MouseButton button);

struct Delays
{
    float delay_fixed;
    float delay_random;
    float repeat;
};


class AbstractInterpreter : public QObject
{
    Q_OBJECT
public:
    AbstractInterpreter()
    {}
    void MainLoop();
    virtual void init(QDomDocument& dom)=0;
    virtual void resetStopFlag()=0;
    virtual int execute(const QDomNode& node)=0;
    virtual Delays parseDelays(const QDomNode& node)=0;
    virtual int process(const QDomNode& domNode);
    void TraverseXmlNode(const QDomNode& node);
    virtual void executeFunction(QString function_name)=0;
signals:
    void setCurrentNode(QDomNode& currentNode);

public slots:
    virtual void stop()=0;

/*
    virtual void Play()=0;
    virtual void StepForward()=0;
    virtual void StepBackward()=0;
    virtual void Goto(QDomNode& node)=0;
    virtual void Pause()=0;
*/

};





#endif // INTERPRETER_H
