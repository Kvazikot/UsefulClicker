#ifndef INTERPRETERWIN64_H
#define INTERPRETERWIN64_H

#include <QObject>
#include <QDomNode>
#include <QMap>
#include <QElapsedTimer>
#include "interpreter/interpreter.h"



template <typename T, typename U>
class create_map
{
private:
    std::map<T, U> m_map;
public:
    create_map(const T& key, const U& val)
    {
        m_map[key] = val;
    }

    create_map<T, U>& operator()(const T& key, const U& val)
    {
        m_map[key] = val;
        return *this;
    }

    operator std::map<T, U>()
    {
        return m_map;
    }
};


template<typename T, typename U>
class map_add_values
{
private:
    std::map<T,U>& m_map;
public:
    map_add_values(std::map<T, U>& _map):m_map(_map){}
    map_add_values& operator()(char* _key, int _val)
    {
        m_map[_key] = _val;
        return *this;
    }
};

QString decodePath(QString filename);

class InterpreterWin64 : public AbstractInterpreter
{
    Q_OBJECT    
public:
    QMap<QString, QDomNode> functionMap;
    QStringList validNodes = {"hotkey","click","dblclick","shell","dblclick","type",
                              "keydown","list","keyup","scrollup","scrolldown","clickimg",
                              "func"};

    bool stopFlag;
    QElapsedTimer elapsedTimer;
    Delays currentDelays;
    InterpreterWin64();
    Delays parseDelays(const QDomNode& node)  override;
    QRect parseRect(const QDomNode& node);
    void MySleep(long delay);
    QVariant get_var(QString varname);

    void init(QDomDocument& dom);

    void MainLoop();
    QDomNode populateVars(QDomNode node);
    static void ExecuteXmlString(QString xml);
    void resetStopFlag();
    int execute(const QDomNode& node) override;
    int executeHotkey(const QDomNode& node);
    int executeCheck(const QDomNode& node);
    int executeSet(const QDomNode& node);
    int executeClick(const QDomNode& node);
    int executeDblClick(const QDomNode& node);
    int executeType(const QDomNode& node);
    int executeShellCommand(const QDomNode& node);
    int executeClickImg(const QDomNode& node);
    int executeClickRect(const QDomNode& node);
    int executeScrollUp(const QDomNode& node);
    int executeScrollDown(const QDomNode& node);
    int executeList(const QDomNode& node);
    void executeFunction(const QDomNode& rootNode, QDomNode funcNode, QString function_name);
    void executeFunction(QString function_name);
    int executeForeach(const QDomNode& node);
signals:
    void setCurrentNode(const QDomNode& currentNode, Delays delays);

public slots:
    void stop();
    /*
    void Play() override;
    void StepForward() override;
    void StepBackward() override;
    void Goto(QDomNode& node) override;
    void Pause() override;
    */


};

typedef int (InterpreterWin64::*method_t)(const QDomNode& n);
typedef std::map<std::string, method_t> func_map_t;


#endif // INTERPRETERWIN64_H
