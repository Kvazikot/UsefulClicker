/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
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
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QTreeView *view;
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
    XmlEditor *xmlEditor_2;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *actionsMenu;
    QMenu *menuAbout;
    QMenu *menuView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1273, 752);
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        insertRowAction = new QAction(MainWindow);
        insertRowAction->setObjectName(QString::fromUtf8("insertRowAction"));
        removeRowAction = new QAction(MainWindow);
        removeRowAction->setObjectName(QString::fromUtf8("removeRowAction"));
        insertColumnAction = new QAction(MainWindow);
        insertColumnAction->setObjectName(QString::fromUtf8("insertColumnAction"));
        removeColumnAction = new QAction(MainWindow);
        removeColumnAction->setObjectName(QString::fromUtf8("removeColumnAction"));
        insertChildAction = new QAction(MainWindow);
        insertChildAction->setObjectName(QString::fromUtf8("insertChildAction"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionhideCodeTags = new QAction(MainWindow);
        actionhideCodeTags->setObjectName(QString::fromUtf8("actionhideCodeTags"));
        actionhideCodeTags->setCheckable(true);
        actionhideAllNonClickerTags = new QAction(MainWindow);
        actionhideAllNonClickerTags->setObjectName(QString::fromUtf8("actionhideAllNonClickerTags"));
        actionhideAllNonClickerTags->setCheckable(true);
        actionhideAllNonClickerTags->setChecked(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        view = new QTreeView(groupBox);
        view->setObjectName(QString::fromUtf8("view"));
        view->setGeometry(QRect(820, 60, 201, 311));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(view->sizePolicy().hasHeightForWidth());
        view->setSizePolicy(sizePolicy);
        view->setMouseTracking(true);
        view->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        view->setDragEnabled(true);
        view->setAlternatingRowColors(true);
        view->setSelectionMode(QAbstractItemView::SingleSelection);
        view->setSelectionBehavior(QAbstractItemView::SelectRows);
        view->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        view->setIndentation(22);
        view->setSortingEnabled(false);
        view->setAnimated(false);
        view->setAllColumnsShowFocus(true);
        view->header()->setCascadingSectionResizes(true);
        view->header()->setMinimumSectionSize(44);
        view->header()->setDefaultSectionSize(44);
        view->header()->setHighlightSections(true);
        view->header()->setProperty("showSortIndicator", QVariant(false));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(14, 355, 756, 294));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(300, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        commentEditor = new QTextEdit(groupBox_3);
        commentEditor->setObjectName(QString::fromUtf8("commentEditor"));

        gridLayout_2->addWidget(commentEditor, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(130, 0));
        leftClick = new QToolButton(groupBox_5);
        leftClick->setObjectName(QString::fromUtf8("leftClick"));
        leftClick->setGeometry(QRect(10, 40, 23, 23));
        leftClick->setMouseTracking(true);
        leftClick->setToolTipDuration(2000);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/mouse_left_click.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftClick->setIcon(icon);
        leftClick->setToolButtonStyle(Qt::ToolButtonIconOnly);
        keyboardClick = new QToolButton(groupBox_5);
        keyboardClick->setObjectName(QString::fromUtf8("keyboardClick"));
        keyboardClick->setGeometry(QRect(40, 40, 23, 23));
        keyboardClick->setToolTipDuration(2000);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/keyboard_color.png"), QSize(), QIcon::Normal, QIcon::Off);
        keyboardClick->setIcon(icon1);
        keyboardClick->setCheckable(true);
        areaClick = new QToolButton(groupBox_5);
        areaClick->setObjectName(QString::fromUtf8("areaClick"));
        areaClick->setGeometry(QRect(70, 40, 23, 23));
        areaClick->setToolTipDuration(2000);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/area_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        areaClick->setIcon(icon2);
        imageClick = new QToolButton(groupBox_5);
        imageClick->setObjectName(QString::fromUtf8("imageClick"));
        imageClick->setGeometry(QRect(100, 40, 23, 23));
        imageClick->setToolTipDuration(2000);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/image.png"), QSize(), QIcon::Normal, QIcon::Off);
        imageClick->setIcon(icon3);
        typeTag = new QToolButton(groupBox_5);
        typeTag->setObjectName(QString::fromUtf8("typeTag"));
        typeTag->setGeometry(QRect(10, 70, 23, 23));
        typeTag->setToolTipDuration(2000);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/type.png"), QSize(), QIcon::Normal, QIcon::Off);
        typeTag->setIcon(icon4);
        toolButton_7 = new QToolButton(groupBox_5);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setGeometry(QRect(40, 70, 23, 23));
        toolButton_7->setToolTipDuration(2000);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/clock-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon5);
        rectClick = new QToolButton(groupBox_5);
        rectClick->setObjectName(QString::fromUtf8("rectClick"));
        rectClick->setGeometry(QRect(70, 70, 23, 23));
        rectClick->setToolTipDuration(2000);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/rect_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectClick->setIcon(icon6);
        PlayButton = new QToolButton(groupBox_5);
        PlayButton->setObjectName(QString::fromUtf8("PlayButton"));
        PlayButton->setGeometry(QRect(10, 110, 111, 121));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/play_123.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlayButton->setIcon(icon7);
        PlayButton->setIconSize(QSize(128, 128));

        horizontalLayout->addWidget(groupBox_5);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        groupBox_4->setMinimumSize(QSize(300, 0));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        xmlEditor = new XmlEditor(groupBox_4);
        xmlEditor->setObjectName(QString::fromUtf8("xmlEditor"));

        gridLayout_4->addWidget(xmlEditor, 1, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_4);

        xmlEditor_2 = new XmlEditor(groupBox);
        xmlEditor_2->setObjectName(QString::fromUtf8("xmlEditor_2"));
        xmlEditor_2->setGeometry(QRect(50, 50, 731, 281));
        sizePolicy1.setHeightForWidth(xmlEditor_2->sizePolicy().hasHeightForWidth());
        xmlEditor_2->setSizePolicy(sizePolicy1);
        xmlEditor_2->setStyleSheet(QString::fromUtf8("border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 0, 0, 255), stop:0.479904 rgba(255, 0, 0, 255), stop:0.522685 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));

        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1273, 25));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
        actionsMenu = new QMenu(menubar);
        actionsMenu->setObjectName(QString::fromUtf8("actionsMenu"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(fileMenu->menuAction());
        menubar->addAction(actionsMenu->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menubar->addAction(menuView->menuAction());
        fileMenu->addAction(actionOpen);
        fileMenu->addAction(actionSave);
        fileMenu->addAction(actionSave_as);
        actionsMenu->addAction(insertRowAction);
        actionsMenu->addSeparator();
        actionsMenu->addAction(removeRowAction);
        actionsMenu->addSeparator();
        menuAbout->addAction(actionAbout);
        menuView->addAction(actionhideCodeTags);
        menuView->addAction(actionhideAllNonClickerTags);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Editable Tree Model", nullptr));
        exitAction->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        exitAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        insertRowAction->setText(QCoreApplication::translate("MainWindow", "Insert Row", nullptr));
#if QT_CONFIG(shortcut)
        insertRowAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I, R", nullptr));
#endif // QT_CONFIG(shortcut)
        removeRowAction->setText(QCoreApplication::translate("MainWindow", "Remove Row", nullptr));
#if QT_CONFIG(shortcut)
        removeRowAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R, R", nullptr));
#endif // QT_CONFIG(shortcut)
        insertColumnAction->setText(QCoreApplication::translate("MainWindow", "Insert Column", nullptr));
#if QT_CONFIG(shortcut)
        insertColumnAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I, C", nullptr));
#endif // QT_CONFIG(shortcut)
        removeColumnAction->setText(QCoreApplication::translate("MainWindow", "Remove Column", nullptr));
#if QT_CONFIG(shortcut)
        removeColumnAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R, C", nullptr));
#endif // QT_CONFIG(shortcut)
        insertChildAction->setText(QCoreApplication::translate("MainWindow", "Insert Child", nullptr));
#if QT_CONFIG(shortcut)
        insertChildAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as...", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionhideCodeTags->setText(QCoreApplication::translate("MainWindow", "hideCodeTags", nullptr));
        actionhideAllNonClickerTags->setText(QCoreApplication::translate("MainWindow", "hideAllNonClickerTags", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Xml tree view", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "XML", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Function description and comments", nullptr));
        commentEditor->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">This function is cooking eggs and mix them with wiskey</span></p></body></html>", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Available Tags", nullptr));
#if QT_CONFIG(tooltip)
        leftClick->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Click tag (F1)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        leftClick->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Click tag</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        leftClick->setText(QCoreApplication::translate("MainWindow", "Left click", nullptr));
#if QT_CONFIG(shortcut)
        leftClick->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        keyboardClick->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Hotkey (F1)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        keyboardClick->setText(QCoreApplication::translate("MainWindow", "Hotkey", nullptr));
#if QT_CONFIG(shortcut)
        keyboardClick->setShortcut(QCoreApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        areaClick->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Area click (F3)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        areaClick->setText(QCoreApplication::translate("MainWindow", "Area click", nullptr));
#if QT_CONFIG(shortcut)
        areaClick->setShortcut(QCoreApplication::translate("MainWindow", "F3", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        imageClick->setToolTip(QCoreApplication::translate("MainWindow", "Image click (F4)", nullptr));
#endif // QT_CONFIG(tooltip)
        imageClick->setText(QCoreApplication::translate("MainWindow", "Click on image", nullptr));
#if QT_CONFIG(shortcut)
        imageClick->setShortcut(QCoreApplication::translate("MainWindow", "F4", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        typeTag->setToolTip(QCoreApplication::translate("MainWindow", "Type click", nullptr));
#endif // QT_CONFIG(tooltip)
        typeTag->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_7->setToolTip(QCoreApplication::translate("MainWindow", "Delay", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_7->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        rectClick->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Area click (F3)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rectClick->setText(QCoreApplication::translate("MainWindow", "Rectangle click", nullptr));
#if QT_CONFIG(shortcut)
        rectClick->setShortcut(QCoreApplication::translate("MainWindow", "F3", nullptr));
#endif // QT_CONFIG(shortcut)
        PlayButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Xml editor", nullptr));
        fileMenu->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        actionsMenu->setTitle(QCoreApplication::translate("MainWindow", "&Actions", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
