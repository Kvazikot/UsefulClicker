#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include "xml/clickerdocument.h"
#include "interpreter/interpreterwin64.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //singleton instance
    static MainWindow* getInstance();
    static MainWindow* instance;
    void   setLogWindow(QPlainTextEdit* wnd);
    void   log(QString msg);
    void   loadDocument(QString filename);
    void    setDoc(ClickerDocument* _doc);
    ClickerDocument* getDoc();
    // flags indicated that UsefulClicker is paused, otherwise its running
    bool   pauseFlag;
    ClickerDocument* doc;
    ClickerDocument defaultDoc;
    QString current_filename;
    InterpreterWin64* interpreter;

private:
    // log window
    QPlainTextEdit*  logWindow;
    QVector<QString> cached_messages;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
