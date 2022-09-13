/********************************************************************************
** Form generated from reading UI file 'cool_tests_form.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COOL_TESTS_FORM_H
#define UI_COOL_TESTS_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CoolTestsForm
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *stopTest;
    QPushButton *runFunction;
    QComboBox *functionsList;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QTextEdit *xmlEditor;
    QPlainTextEdit *logEdit;
    QLabel *testStatusLabel;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_7;
    QPushButton *createTestXml;
    QPushButton *setFunctionTest;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *scrollTest;
    QPushButton *pushButton_3;
    QPushButton *typeTest;
    QPushButton *typeTest2;
    QPushButton *changeFontWindows11;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QPushButton *pickPoint;
    QPushButton *areaButton;
    QPushButton *shellDialog;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_10;
    QLabel *buttonImage;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QPushButton *clickimgTest;
    QSpinBox *spinBox;
    QPushButton *buttonsDetector1;
    QPushButton *imageSearch;
    QPushButton *clickrectTest;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout;
    QRadioButton *allScreens;
    QRadioButton *screen0;
    QRadioButton *screen1;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QWidget *tab_3;
    QGroupBox *groupBox_13;
    QGroupBox *groupBox_12;
    QPushButton *foreachTest1;
    QPushButton *foreachTest2;
    QPushButton *foreachTest3;
    QPushButton *foreachTest4;
    QGroupBox *groupBox_14;
    QPushButton *expressionTest12;
    QPushButton *generatorsTest;
    QGroupBox *groupBox_15;
    QPushButton *pirateBayTest;
    QWidget *tab_2;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;

    void setupUi(QDialog *CoolTestsForm)
    {
        if (CoolTestsForm->objectName().isEmpty())
            CoolTestsForm->setObjectName(QString::fromUtf8("CoolTestsForm"));
        CoolTestsForm->setWindowModality(Qt::NonModal);
        CoolTestsForm->resize(998, 1020);
        buttonBox = new QDialogButtonBox(CoolTestsForm);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(1330, 30, 81, 61));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(CoolTestsForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 261, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stopTest = new QPushButton(layoutWidget);
        stopTest->setObjectName(QString::fromUtf8("stopTest"));

        horizontalLayout->addWidget(stopTest);

        runFunction = new QPushButton(layoutWidget);
        runFunction->setObjectName(QString::fromUtf8("runFunction"));

        horizontalLayout->addWidget(runFunction);

        functionsList = new QComboBox(layoutWidget);
        functionsList->addItem(QString());
        functionsList->setObjectName(QString::fromUtf8("functionsList"));

        horizontalLayout->addWidget(functionsList);

        groupBox_5 = new QGroupBox(CoolTestsForm);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 498, 961, 521));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        xmlEditor = new QTextEdit(groupBox_5);
        xmlEditor->setObjectName(QString::fromUtf8("xmlEditor"));

        gridLayout_5->addWidget(xmlEditor, 1, 0, 1, 1);

        logEdit = new QPlainTextEdit(groupBox_5);
        logEdit->setObjectName(QString::fromUtf8("logEdit"));
        logEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_5->addWidget(logEdit, 0, 0, 1, 1);

        testStatusLabel = new QLabel(CoolTestsForm);
        testStatusLabel->setObjectName(QString::fromUtf8("testStatusLabel"));
        testStatusLabel->setGeometry(QRect(360, 16, 291, 16));
        testStatusLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 900 9pt \"Segoe UI\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 41, 4, 255), stop:0.085 rgba(2, 79, 0, 255), stop:0.19 rgba(50, 147, 22, 255), stop:0.275 rgba(236, 191, 49, 255), stop:0.39 rgba(243, 61, 34, 255), stop:0.555 rgba(135, 81, 60, 255), stop:0.667 rgba(121, 75, 255, 255), stop:0.825 rgba(164, 255, 244, 255), stop:0.885 rgba(104, 222, 71, 255), stop:1 rgba(93, 128, 0, 255));"));
        testStatusLabel->setAlignment(Qt::AlignCenter);
        tabWidget = new QTabWidget(CoolTestsForm);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 41, 961, 461));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(190, 190, 161, 101));
        gridLayout_7 = new QGridLayout(groupBox_7);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        createTestXml = new QPushButton(groupBox_7);
        createTestXml->setObjectName(QString::fromUtf8("createTestXml"));

        gridLayout_7->addWidget(createTestXml, 0, 0, 1, 1);

        setFunctionTest = new QPushButton(groupBox_7);
        setFunctionTest->setObjectName(QString::fromUtf8("setFunctionTest"));

        gridLayout_7->addWidget(setFunctionTest, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 150, 171, 211));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollTest = new QPushButton(groupBox_2);
        scrollTest->setObjectName(QString::fromUtf8("scrollTest"));

        gridLayout_2->addWidget(scrollTest, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 3, 0, 1, 1);

        typeTest = new QPushButton(groupBox_2);
        typeTest->setObjectName(QString::fromUtf8("typeTest"));

        gridLayout_2->addWidget(typeTest, 0, 0, 1, 1);

        typeTest2 = new QPushButton(groupBox_2);
        typeTest2->setObjectName(QString::fromUtf8("typeTest2"));

        gridLayout_2->addWidget(typeTest2, 1, 0, 1, 1);

        changeFontWindows11 = new QPushButton(groupBox_2);
        changeFontWindows11->setObjectName(QString::fromUtf8("changeFontWindows11"));

        gridLayout_2->addWidget(changeFontWindows11, 4, 0, 1, 1);

        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(190, 10, 141, 141));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pickPoint = new QPushButton(groupBox_6);
        pickPoint->setObjectName(QString::fromUtf8("pickPoint"));

        gridLayout_6->addWidget(pickPoint, 1, 0, 1, 1);

        areaButton = new QPushButton(groupBox_6);
        areaButton->setObjectName(QString::fromUtf8("areaButton"));

        gridLayout_6->addWidget(areaButton, 0, 0, 1, 1);

        shellDialog = new QPushButton(groupBox_6);
        shellDialog->setObjectName(QString::fromUtf8("shellDialog"));

        gridLayout_6->addWidget(shellDialog, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(190, 300, 141, 61));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_3->addWidget(pushButton_4, 0, 0, 1, 1);

        groupBox_11 = new QGroupBox(tab);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(360, 200, 281, 151));
        gridLayout_10 = new QGridLayout(groupBox_11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        buttonImage = new QLabel(groupBox_11);
        buttonImage->setObjectName(QString::fromUtf8("buttonImage"));
        buttonImage->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        buttonImage->setFrameShape(QFrame::Panel);

        gridLayout_10->addWidget(buttonImage, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(360, 10, 191, 181));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        clickimgTest = new QPushButton(groupBox_4);
        clickimgTest->setObjectName(QString::fromUtf8("clickimgTest"));

        gridLayout_4->addWidget(clickimgTest, 2, 0, 1, 1);

        spinBox = new QSpinBox(groupBox_4);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(1000);
        spinBox->setValue(100);

        gridLayout_4->addWidget(spinBox, 4, 0, 1, 1);

        buttonsDetector1 = new QPushButton(groupBox_4);
        buttonsDetector1->setObjectName(QString::fromUtf8("buttonsDetector1"));

        gridLayout_4->addWidget(buttonsDetector1, 0, 0, 1, 1);

        imageSearch = new QPushButton(groupBox_4);
        imageSearch->setObjectName(QString::fromUtf8("imageSearch"));

        gridLayout_4->addWidget(imageSearch, 1, 0, 1, 1);

        clickrectTest = new QPushButton(groupBox_4);
        clickrectTest->setObjectName(QString::fromUtf8("clickrectTest"));

        gridLayout_4->addWidget(clickrectTest, 3, 0, 1, 1);

        groupBox_10 = new QGroupBox(tab);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(559, 10, 81, 181));
        verticalLayout = new QVBoxLayout(groupBox_10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        allScreens = new QRadioButton(groupBox_10);
        allScreens->setObjectName(QString::fromUtf8("allScreens"));
        allScreens->setChecked(true);

        verticalLayout->addWidget(allScreens);

        screen0 = new QRadioButton(groupBox_10);
        screen0->setObjectName(QString::fromUtf8("screen0"));
        screen0->setChecked(false);
        screen0->setAutoRepeat(true);

        verticalLayout->addWidget(screen0);

        screen1 = new QRadioButton(groupBox_10);
        screen1->setObjectName(QString::fromUtf8("screen1"));
        screen1->setAutoRepeat(true);

        verticalLayout->addWidget(screen1);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 40, 141, 101));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupBox_13 = new QGroupBox(tab_3);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(10, 0, 541, 311));
        groupBox_12 = new QGroupBox(groupBox_13);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(20, 30, 141, 241));
        foreachTest1 = new QPushButton(groupBox_12);
        foreachTest1->setObjectName(QString::fromUtf8("foreachTest1"));
        foreachTest1->setGeometry(QRect(10, 30, 121, 31));
        foreachTest2 = new QPushButton(groupBox_12);
        foreachTest2->setObjectName(QString::fromUtf8("foreachTest2"));
        foreachTest2->setGeometry(QRect(10, 70, 121, 31));
        foreachTest3 = new QPushButton(groupBox_12);
        foreachTest3->setObjectName(QString::fromUtf8("foreachTest3"));
        foreachTest3->setGeometry(QRect(10, 110, 121, 31));
        foreachTest4 = new QPushButton(groupBox_12);
        foreachTest4->setObjectName(QString::fromUtf8("foreachTest4"));
        foreachTest4->setGeometry(QRect(10, 150, 121, 31));
        groupBox_14 = new QGroupBox(groupBox_13);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(180, 30, 171, 241));
        expressionTest12 = new QPushButton(groupBox_14);
        expressionTest12->setObjectName(QString::fromUtf8("expressionTest12"));
        expressionTest12->setGeometry(QRect(10, 30, 151, 29));
        generatorsTest = new QPushButton(groupBox_14);
        generatorsTest->setObjectName(QString::fromUtf8("generatorsTest"));
        generatorsTest->setGeometry(QRect(10, 80, 151, 29));
        groupBox_15 = new QGroupBox(groupBox_13);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setGeometry(QRect(370, 30, 161, 241));
        pirateBayTest = new QPushButton(groupBox_15);
        pirateBayTest->setObjectName(QString::fromUtf8("pirateBayTest"));
        pirateBayTest->setGeometry(QRect(20, 30, 121, 29));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_8 = new QGroupBox(tab_2);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(20, 20, 161, 97));
        gridLayout_9 = new QGridLayout(groupBox_8);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        pushButton_2 = new QPushButton(groupBox_8);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_9->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox_8);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_9->addWidget(pushButton_5, 1, 0, 1, 1);

        groupBox_9 = new QGroupBox(tab_2);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(220, 30, 164, 131));
        gridLayout_8 = new QGridLayout(groupBox_9);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        pushButton_9 = new QPushButton(groupBox_9);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout_8->addWidget(pushButton_9, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(groupBox_9);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout_8->addWidget(pushButton_8, 0, 0, 1, 1);

        pushButton_10 = new QPushButton(groupBox_9);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout_8->addWidget(pushButton_10, 2, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        retranslateUi(CoolTestsForm);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CoolTestsForm, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CoolTestsForm, qOverload<>(&QDialog::reject));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CoolTestsForm);
    } // setupUi

    void retranslateUi(QDialog *CoolTestsForm)
    {
        CoolTestsForm->setWindowTitle(QCoreApplication::translate("CoolTestsForm", "UsefulClicker Tests Form", nullptr));
        stopTest->setText(QCoreApplication::translate("CoolTestsForm", "STOP TEST", nullptr));
        runFunction->setText(QCoreApplication::translate("CoolTestsForm", "Run Function", nullptr));
        functionsList->setItemText(0, QCoreApplication::translate("CoolTestsForm", "func1", nullptr));

        groupBox_5->setTitle(QCoreApplication::translate("CoolTestsForm", "TEST LOG", nullptr));
        logEdit->setPlainText(QCoreApplication::translate("CoolTestsForm", "x=\"\" y=\"\"", nullptr));
        testStatusLabel->setText(QCoreApplication::translate("CoolTestsForm", "<html><head/><body><p>SELECT THE TEST</p></body></html>", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("CoolTestsForm", "5 Group. Xml Tests", nullptr));
        createTestXml->setText(QCoreApplication::translate("CoolTestsForm", "Create Document (#8)", nullptr));
        setFunctionTest->setText(QCoreApplication::translate("CoolTestsForm", "SetFunction Test (#9)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CoolTestsForm", "1. Notepad tests", nullptr));
        scrollTest->setText(QCoreApplication::translate("CoolTestsForm", "Scroll test (#3)", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CoolTestsForm", "Change font (#4)", nullptr));
        typeTest->setText(QCoreApplication::translate("CoolTestsForm", " Type test (#1)", nullptr));
        typeTest2->setText(QCoreApplication::translate("CoolTestsForm", "Type test 2 (#2)", nullptr));
        changeFontWindows11->setText(QCoreApplication::translate("CoolTestsForm", "Change font Windows 11", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("CoolTestsForm", "Pick point from screen", nullptr));
        pickPoint->setText(QCoreApplication::translate("CoolTestsForm", "Coord selector (#6)", nullptr));
        areaButton->setText(QCoreApplication::translate("CoolTestsForm", "Area selector (#5)", nullptr));
        shellDialog->setText(QCoreApplication::translate("CoolTestsForm", "Shell Dialog (#7)", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("CoolTestsForm", "3. Twitter tests", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CoolTestsForm", "Post Twit (#10)", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("CoolTestsForm", "Button image", nullptr));
        buttonImage->setText(QCoreApplication::translate("CoolTestsForm", "TextLabel", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("CoolTestsForm", "4. CV tests", nullptr));
        clickimgTest->setText(QCoreApplication::translate("CoolTestsForm", "clickimg test (#13)", nullptr));
        spinBox->setPrefix(QCoreApplication::translate("CoolTestsForm", "cannyThreshold = ", nullptr));
        buttonsDetector1->setText(QCoreApplication::translate("CoolTestsForm", "Buttons Detector 1 (#11)", nullptr));
        imageSearch->setText(QCoreApplication::translate("CoolTestsForm", "Image Search (#12)", nullptr));
        clickrectTest->setText(QCoreApplication::translate("CoolTestsForm", "clickrect test (#14)", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("CoolTestsForm", "Screen", nullptr));
        allScreens->setText(QCoreApplication::translate("CoolTestsForm", "All", nullptr));
        screen0->setText(QCoreApplication::translate("CoolTestsForm", " 0", nullptr));
        screen1->setText(QCoreApplication::translate("CoolTestsForm", "1", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CoolTestsForm", "2. Gmail tests", nullptr));
        pushButton_7->setText(QCoreApplication::translate("CoolTestsForm", "Compose Message ", nullptr));
        pushButton_6->setText(QCoreApplication::translate("CoolTestsForm", "Compose Message ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CoolTestsForm", "Main tests (13)", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("CoolTestsForm", "Language tests", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("CoolTestsForm", "foreach loop tests", nullptr));
        foreachTest1->setText(QCoreApplication::translate("CoolTestsForm", "Foreach_test1", nullptr));
        foreachTest2->setText(QCoreApplication::translate("CoolTestsForm", "Foreach_test2", nullptr));
        foreachTest3->setText(QCoreApplication::translate("CoolTestsForm", "Foreach_test3", nullptr));
        foreachTest4->setText(QCoreApplication::translate("CoolTestsForm", "Foreach_test4", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("CoolTestsForm", "Expression calculator", nullptr));
        expressionTest12->setText(QCoreApplication::translate("CoolTestsForm", "12 Expressions test", nullptr));
        generatorsTest->setText(QCoreApplication::translate("CoolTestsForm", "Generators test", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("CoolTestsForm", "Torrent downloader tests", nullptr));
        pirateBayTest->setText(QCoreApplication::translate("CoolTestsForm", "PirateBay test", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("CoolTestsForm", "Test page 2", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("CoolTestsForm", "Painter tests", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CoolTestsForm", "Area click test", nullptr));
        pushButton_5->setText(QCoreApplication::translate("CoolTestsForm", "Drawing Face Test", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("CoolTestsForm", "MicroRecorder tests", nullptr));
        pushButton_9->setText(QCoreApplication::translate("CoolTestsForm", "Record mouse trajectory ", nullptr));
        pushButton_8->setText(QCoreApplication::translate("CoolTestsForm", "Interactive cv test", nullptr));
        pushButton_10->setText(QCoreApplication::translate("CoolTestsForm", "Play mouse trajectory", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CoolTestsForm", "Test page 3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CoolTestsForm: public Ui_CoolTestsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COOL_TESTS_FORM_H
