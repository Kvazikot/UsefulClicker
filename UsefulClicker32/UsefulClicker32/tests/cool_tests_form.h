#ifndef COOL_TESTS_FORM_H
#define COOL_TESTS_FORM_H

#include <QDialog>
#include <QMap>
#include <QDomNode>
#include <QElapsedTimer>
#include <QTimerEvent>
#include "interpreter.h"
#include "cv/rectangle_descriptor.h"

namespace Ui {
class CoolTestsForm;
}

class CoolTestsForm : public QDialog
{
    Q_OBJECT

public:
    int screenNum=0;
    double totalTime=0;
    int  kernel_size;
    bool saved;
    bool testIsRunningFlag;
    RectangleDescriptor targetDescriptor;
    QString currentStepText;
    QElapsedTimer lastBlinkTimer;
    QElapsedTimer lastNodeTimer;
    explicit CoolTestsForm(QWidget *parent = nullptr);
    void runFunction(QString func_name);
    void fullScreen();
    void createButtons();
    void timerEvent(QTimerEvent* event);
    void showEvent(QShowEvent* event);

    ~CoolTestsForm();

private slots:
    void on_buttonsDetector1_clicked();
    void on_runNotepadFullscreen_clicked();
    void on_imageSearch_clicked();


    void on_runFunction_clicked();

    void on_pushButton_3_clicked();

    void on_pickPoint_clicked();

    void on_areaButton_clicked();

    void on_functionsList_currentIndexChanged(int index);

    void on_shellDialog_clicked();

    void on_pushButton_4_clicked();

    void on_createTestXml_clicked();

    void on_setFunctionTest_clicked();

    void on_scrollTest_clicked();

    void on_stopTest_clicked();

    void on_typeTest2_clicked();

    void on_typeTest_clicked(bool checked);

    void on_clickimgTest_clicked();

    void on_foreachTest1_clicked();

    void on_foreachTest2_clicked();

    void on_foreachTest3_clicked();

    void on_foreachTest4_clicked();

    void on_expressionTest12_clicked();

    void on_generatorsTest_clicked();

    void on_pirateBayTest_clicked();

    void on_changeFontWindows11_clicked();

    void on_clickrectTest_clicked();

    void on_rectangleDescriptorTest_clicked();

    void on_histCompressionTest_clicked();

signals:
    void stopExecutionSignal();

public slots:    
    void currentStep(const QDomNode& currentNode, Delays delays);
    void slotSetAttrs(QMap<QString,QString> attrs);
    void buttonDetectorOut(QMap<QString, QString> attrs);
    void slotFullScreen();
    void textChanged();
    void cursorPositionChanged();
private:
    Ui::CoolTestsForm *ui;
};

#endif // COOL_TESTS_FORM_H
