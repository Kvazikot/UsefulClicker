/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "xml/xmleditor.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *exitAction;
    QAction *insertRowAction;
    QAction *removeRowAction;
    QAction *insertColumnAction;
    QAction *removeColumnAction;
    QAction *insertChildAction;
    QAction *actionAbout;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionOpen;
    QAction *actionhideCodeTags;
    QAction *actionhideAllNonClickerTags;
    QAction *actionRun_tests;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QTextEdit *commentEditor;
    QGroupBox *groupBox_5;
    QToolButton *leftClick;
    QToolButton *keyboardClick;
    QToolButton *areaClick;
    QToolButton *imageClick;
    QToolButton *typeTag;
    QToolButton *toolButton_7;
    QToolButton *rectClick;
    QToolButton *PlayButton;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    XmlEditor *xmlEditor;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    XmlEditor *xmlEditor_2;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *menuAbout;
    QMenu *menuTests;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1273, 752);
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QStringLiteral("exitAction"));
        insertRowAction = new QAction(MainWindow);
        insertRowAction->setObjectName(QStringLiteral("insertRowAction"));
        removeRowAction = new QAction(MainWindow);
        removeRowAction->setObjectName(QStringLiteral("removeRowAction"));
        insertColumnAction = new QAction(MainWindow);
        insertColumnAction->setObjectName(QStringLiteral("insertColumnAction"));
        removeColumnAction = new QAction(MainWindow);
        removeColumnAction->setObjectName(QStringLiteral("removeColumnAction"));
        insertChildAction = new QAction(MainWindow);
        insertChildAction->setObjectName(QStringLiteral("insertChildAction"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionhideCodeTags = new QAction(MainWindow);
        actionhideCodeTags->setObjectName(QStringLiteral("actionhideCodeTags"));
        actionhideCodeTags->setCheckable(true);
        actionhideAllNonClickerTags = new QAction(MainWindow);
        actionhideAllNonClickerTags->setObjectName(QStringLiteral("actionhideAllNonClickerTags"));
        actionhideAllNonClickerTags->setCheckable(true);
        actionhideAllNonClickerTags->setChecked(true);
        actionRun_tests = new QAction(MainWindow);
        actionRun_tests->setObjectName(QStringLiteral("actionRun_tests"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(300, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        commentEditor = new QTextEdit(groupBox_3);
        commentEditor->setObjectName(QStringLiteral("commentEditor"));

        gridLayout_2->addWidget(commentEditor, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(130, 0));
        leftClick = new QToolButton(groupBox_5);
        leftClick->setObjectName(QStringLiteral("leftClick"));
        leftClick->setGeometry(QRect(10, 40, 23, 23));
        leftClick->setMouseTracking(true);
        leftClick->setToolTipDuration(2000);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/mouse_left_click.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftClick->setIcon(icon);
        leftClick->setToolButtonStyle(Qt::ToolButtonIconOnly);
        keyboardClick = new QToolButton(groupBox_5);
        keyboardClick->setObjectName(QStringLiteral("keyboardClick"));
        keyboardClick->setGeometry(QRect(40, 40, 23, 23));
        keyboardClick->setToolTipDuration(2000);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/keyboard_color.png"), QSize(), QIcon::Normal, QIcon::Off);
        keyboardClick->setIcon(icon1);
        keyboardClick->setCheckable(true);
        areaClick = new QToolButton(groupBox_5);
        areaClick->setObjectName(QStringLiteral("areaClick"));
        areaClick->setGeometry(QRect(70, 40, 23, 23));
        areaClick->setToolTipDuration(2000);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/area_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        areaClick->setIcon(icon2);
        imageClick = new QToolButton(groupBox_5);
        imageClick->setObjectName(QStringLiteral("imageClick"));
        imageClick->setGeometry(QRect(100, 40, 23, 23));
        imageClick->setToolTipDuration(2000);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/image.png"), QSize(), QIcon::Normal, QIcon::Off);
        imageClick->setIcon(icon3);
        typeTag = new QToolButton(groupBox_5);
        typeTag->setObjectName(QStringLiteral("typeTag"));
        typeTag->setGeometry(QRect(10, 70, 23, 23));
        typeTag->setToolTipDuration(2000);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/type.png"), QSize(), QIcon::Normal, QIcon::Off);
        typeTag->setIcon(icon4);
        toolButton_7 = new QToolButton(groupBox_5);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setGeometry(QRect(40, 70, 23, 23));
        toolButton_7->setToolTipDuration(2000);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/clock-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon5);
        rectClick = new QToolButton(groupBox_5);
        rectClick->setObjectName(QStringLiteral("rectClick"));
        rectClick->setGeometry(QRect(70, 70, 23, 23));
        rectClick->setToolTipDuration(2000);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/rect_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectClick->setIcon(icon6);
        PlayButton = new QToolButton(groupBox_5);
        PlayButton->setObjectName(QStringLiteral("PlayButton"));
        PlayButton->setGeometry(QRect(10, 110, 111, 121));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlayButton->setIcon(icon7);
        PlayButton->setIconSize(QSize(128, 128));

        horizontalLayout->addWidget(groupBox_5);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setMinimumSize(QSize(300, 0));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        xmlEditor = new XmlEditor(groupBox_4);
        xmlEditor->setObjectName(QStringLiteral("xmlEditor"));

        gridLayout_4->addWidget(xmlEditor, 1, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_4);


        gridLayout_6->addWidget(groupBox_2, 1, 0, 1, 1);

        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        xmlEditor_2 = new XmlEditor(tab_3);
        xmlEditor_2->setObjectName(QStringLiteral("xmlEditor_2"));
        xmlEditor_2->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        gridLayout_5->addWidget(xmlEditor_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout_6->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1273, 21));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QStringLiteral("fileMenu"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuTests = new QMenu(menubar);
        menuTests->setObjectName(QStringLiteral("menuTests"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(fileMenu->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menubar->addAction(menuTests->menuAction());
        fileMenu->addAction(actionOpen);
        fileMenu->addAction(actionSave);
        fileMenu->addAction(actionSave_as);
        menuAbout->addAction(actionAbout);
        menuTests->addAction(actionRun_tests);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UsefulClicker", Q_NULLPTR));
        exitAction->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        exitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        insertRowAction->setText(QApplication::translate("MainWindow", "Insert Row", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        insertRowAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+I, R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        removeRowAction->setText(QApplication::translate("MainWindow", "Remove Row", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        removeRowAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+R, R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        insertColumnAction->setText(QApplication::translate("MainWindow", "Insert Column", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        insertColumnAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+I, C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        removeColumnAction->setText(QApplication::translate("MainWindow", "Remove Column", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        removeColumnAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+R, C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        insertChildAction->setText(QApplication::translate("MainWindow", "Insert Child", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        insertChildAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save (ctrl+s)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save (ctrl+s)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open (ctrl+o)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionhideCodeTags->setText(QApplication::translate("MainWindow", "hideCodeTags", Q_NULLPTR));
        actionhideAllNonClickerTags->setText(QApplication::translate("MainWindow", "hideAllNonClickerTags", Q_NULLPTR));
        actionRun_tests->setText(QApplication::translate("MainWindow", "Run tests ", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Xml tree view", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "XML", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Function description and comments", Q_NULLPTR));
        commentEditor->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:696;\">This function is cooking eggs and mix them with wiskey</span></p></body></html>", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Available Tags", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        leftClick->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Click tag (F1)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        leftClick->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Click tag</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        leftClick->setText(QApplication::translate("MainWindow", "Left click", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        leftClick->setShortcut(QApplication::translate("MainWindow", "F1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        keyboardClick->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Hotkey (F1)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        keyboardClick->setText(QApplication::translate("MainWindow", "Hotkey", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        keyboardClick->setShortcut(QApplication::translate("MainWindow", "F2", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        areaClick->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Area click (F3)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        areaClick->setText(QApplication::translate("MainWindow", "Area click", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        areaClick->setShortcut(QApplication::translate("MainWindow", "F3", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        imageClick->setToolTip(QApplication::translate("MainWindow", "Image click (F4)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        imageClick->setText(QApplication::translate("MainWindow", "Click on image", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        imageClick->setShortcut(QApplication::translate("MainWindow", "F4", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        typeTag->setToolTip(QApplication::translate("MainWindow", "Type click", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        typeTag->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButton_7->setToolTip(QApplication::translate("MainWindow", "Delay", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButton_7->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        rectClick->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Area click (F3)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        rectClick->setText(QApplication::translate("MainWindow", "Rectangle click", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        rectClick->setShortcut(QApplication::translate("MainWindow", "F3", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        PlayButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Function editor", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Xml Document", Q_NULLPTR));
        fileMenu->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        menuTests->setTitle(QApplication::translate("MainWindow", "Tests", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
