/********************************************************************************
** Form generated from reading UI file 'apocaliptolib.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APOCALIPTOLIB_H
#define UI_APOCALIPTOLIB_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApocaliptoLIB
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTableWidget *bookList;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *downloadZlibWithSurfshark;
    QProgressBar *progressBar;
    QPushButton *downloadWithoutVPN;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QListWidget *listWidget_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *tab;
    QListWidget *listWidget;
    QLabel *label_4;
    QPlainTextEdit *logWindow;
    QToolButton *stopButton;
    QLabel *label_5;
    QPushButton *pushButton_2;

    void setupUi(QDialog *ApocaliptoLIB)
    {
        if (ApocaliptoLIB->objectName().isEmpty())
            ApocaliptoLIB->setObjectName(QString::fromUtf8("ApocaliptoLIB"));
        ApocaliptoLIB->resize(1066, 707);
        gridLayout = new QGridLayout(ApocaliptoLIB);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(ApocaliptoLIB);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        pushButton = new QPushButton(tab_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 30, 121, 41));
        label = new QLabel(tab_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 931, 301));
        label->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Segoe UI\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 41, 4, 255), stop:0.085 rgba(2, 79, 0, 255), stop:0.19 rgba(50, 147, 22, 255), stop:0.275 rgba(236, 191, 49, 255), stop:0.39 rgba(243, 61, 34, 255), stop:0.555 rgba(135, 81, 60, 255), stop:0.667 rgba(121, 75, 255, 255), stop:0.825 rgba(164, 255, 244, 255), stop:0.885 rgba(104, 222, 71, 255), stop:1 rgba(93, 128, 0, 255));\n"
""));
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(530, 20, 191, 21));
        label_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: rgb(0, 0, 0);"));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 290, 621, 20));
        bookList = new QTableWidget(tab_4);
        if (bookList->columnCount() < 3)
            bookList->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        bookList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        bookList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        bookList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        bookList->setObjectName(QString::fromUtf8("bookList"));
        bookList->setGeometry(QRect(320, 50, 611, 241));
        layoutWidget = new QWidget(tab_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 330, 931, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        downloadZlibWithSurfshark = new QPushButton(layoutWidget);
        downloadZlibWithSurfshark->setObjectName(QString::fromUtf8("downloadZlibWithSurfshark"));

        horizontalLayout_2->addWidget(downloadZlibWithSurfshark);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setStyleSheet(QString::fromUtf8(""));
        progressBar->setValue(55);

        horizontalLayout_2->addWidget(progressBar);

        downloadWithoutVPN = new QPushButton(layoutWidget);
        downloadWithoutVPN->setObjectName(QString::fromUtf8("downloadWithoutVPN"));

        horizontalLayout_2->addWidget(downloadWithoutVPN);

        tabWidget_2 = new QTabWidget(tab_4);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 400, 331, 241));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        listWidget_2 = new QListWidget(tab_2);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setEnabled(true);
        listWidget_2->setGeometry(QRect(20, 81, 281, 121));
        radioButton = new QRadioButton(tab_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 10, 241, 26));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(tab_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 40, 211, 26));
        tabWidget_2->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        listWidget = new QListWidget(tab);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 291, 192));
        tabWidget_2->addTab(tab, QString());
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(470, 400, 461, 20));
        label_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 41, 4, 255), stop:0.085 rgba(2, 79, 0, 255), stop:0.19 rgba(50, 147, 22, 255), stop:0.275 rgba(236, 191, 49, 255), stop:0.39 rgba(243, 61, 34, 255), stop:0.555 rgba(135, 81, 60, 255), stop:0.667 rgba(121, 75, 255, 255), stop:0.825 rgba(164, 255, 244, 255), stop:0.885 rgba(104, 222, 71, 255), stop:1 rgba(93, 128, 0, 255));"));
        label_4->setAlignment(Qt::AlignCenter);
        logWindow = new QPlainTextEdit(tab_4);
        logWindow->setObjectName(QString::fromUtf8("logWindow"));
        logWindow->setGeometry(QRect(470, 430, 461, 211));
        stopButton = new QToolButton(tab_4);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(350, 480, 111, 101));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/stop-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon);
        stopButton->setIconSize(QSize(256, 256));
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(350, 430, 101, 41));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 17, 191, 24));
        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(ApocaliptoLIB);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        listWidget_2->setCurrentRow(0);
        listWidget->setCurrentRow(0);


        QMetaObject::connectSlotsByName(ApocaliptoLIB);
    } // setupUi

    void retranslateUi(QDialog *ApocaliptoLIB)
    {
        ApocaliptoLIB->setWindowTitle(QCoreApplication::translate("ApocaliptoLIB", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ApocaliptoLIB", "D", nullptr));
        label->setText(QCoreApplication::translate("ApocaliptoLIB", "<html><head/><body><p><span style=\" font-size:18pt; color:#000000;\">________ApocaliptoLIB is a</span></p><p><span style=\" font-size:18pt; color:#000000;\">________list of books that </span></p><p><span style=\" font-size:18pt; color:#000000;\">________help humans to </span></p><p><span style=\" font-size:18pt; color:#000000;\">________recreate civilization </span></p><p><span style=\" font-size:18pt; color:#000000;\">________after collapse </span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("ApocaliptoLIB", "<html><head/><body><p><a href=\"https://github.com/Kvazikot/site-apocaliptoLib\"><span style=\" text-decoration: underline; color:#007af4;\">URL of the project on github</span></a></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("ApocaliptoLIB", "<html><head/><body><p><span style=\" font-weight:700;\">downloading &quot;The knowledge how to ... &quot;</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = bookList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ApocaliptoLIB", "\342\204\226", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = bookList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ApocaliptoLIB", "Book title", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = bookList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ApocaliptoLIB", "Author", nullptr));
        downloadZlibWithSurfshark->setText(QCoreApplication::translate("ApocaliptoLIB", "Download books from zlib \n"
" with VPN ", nullptr));
        progressBar->setFormat(QCoreApplication::translate("ApocaliptoLIB", "34 book from 144  Downloaded", nullptr));
        downloadWithoutVPN->setText(QCoreApplication::translate("ApocaliptoLIB", "Download books from zlib \n"
" without VPN ", nullptr));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_2->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("ApocaliptoLIB", "chrome", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_2->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("ApocaliptoLIB", "edge", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_2->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("ApocaliptoLIB", "firefox", nullptr));
        listWidget_2->setSortingEnabled(__sortingEnabled);

        radioButton->setText(QCoreApplication::translate("ApocaliptoLIB", "download using UsefulClicker", nullptr));
        radioButton_2->setText(QCoreApplication::translate("ApocaliptoLIB", "download using browser", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QCoreApplication::translate("ApocaliptoLIB", "Settings", nullptr));

        const bool __sortingEnabled1 = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(0);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("ApocaliptoLIB", "no VPN", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(1);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("ApocaliptoLIB", "surfshark VPN", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(2);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("ApocaliptoLIB", "openVPN", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(3);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("ApocaliptoLIB", "SoftEther", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(4);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("ApocaliptoLIB", "Zen chrome extension", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled1);

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QCoreApplication::translate("ApocaliptoLIB", "VPN", nullptr));
        label_4->setText(QCoreApplication::translate("ApocaliptoLIB", "<html><head/><body><p><span style=\" font-weight:700;\">LOG</span></p></body></html>", nullptr));
        logWindow->setPlainText(QCoreApplication::translate("ApocaliptoLIB", "message\n"
"book xyz is downloaded OK\n"
"start downloding from zlib org  date 25 may 2022................\n"
"resuming download from 32 book...............\n"
"searching book on zlib cloud service\n"
"book is found! quenue download.\n"
"[5/25/2022 2:28] start downloading time 2:28 PM", nullptr));
        stopButton->setText(QCoreApplication::translate("ApocaliptoLIB", "...", nullptr));
#if QT_CONFIG(shortcut)
        stopButton->setShortcut(QCoreApplication::translate("ApocaliptoLIB", "Ctrl+F6", nullptr));
#endif // QT_CONFIG(shortcut)
        label_5->setText(QCoreApplication::translate("ApocaliptoLIB", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">CTRL+F6</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ApocaliptoLIB", "Update list of books from github", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("ApocaliptoLIB", "ApocalyptoLIB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApocaliptoLIB: public Ui_ApocaliptoLIB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APOCALIPTOLIB_H
