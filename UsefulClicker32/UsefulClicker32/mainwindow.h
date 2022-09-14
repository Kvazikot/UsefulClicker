#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QComboBox>
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
    AbstractInterpreter* getInterpreter();

    ClickerDocument* getDoc();
    // flags indicated that UsefulClicker is paused, otherwise its running
    bool   pauseFlag;
    ClickerDocument* doc;
    ClickerDocument defaultDoc;
    QString current_filename;
    InterpreterWin64* interpreter;
    QAction* playAction;
    bool     disableCursorMove;

    void insertXmlString(QString xml_string);
    void modifyXmlString(QString xml_string);
    void applyFunctionChanges();

public slots:
    void reload();
    void reloadFromFile(QString& filename);
    void new_fun();
    void pause();
    void openXml();
    void about();
    void updateFunctionEditor();
    void functionSelected(const QString&);
    void slotSetAttrs(QMap<QString,QString> attrs_map);
    void XmlStringFromUniversalDialog(QMap<QString,QString> attrs_map);
    void xmlChanged();

private slots:
    void on_leftClick_clicked();

    void on_keyboardClick_clicked();

    void on_areaClick_clicked();

    void on_imageClick_clicked();

    void on_typeTag_clicked();

    //void on_toolButton_7_clicked();
    void xml2CursorChanged();
    void on_rectClick_clicked();

    void on_PlayButton_clicked();
    void applyChangesXml();
    void updateStatus(const QString& text, bool applyChangesFlag);
private:
    // log window
    QPlainTextEdit*  logWindow;
    QVector<QString> cached_messages;
    QString last_action_triggered;
    QComboBox* functionSelector;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
