/********************************************************************************
** Form generated from reading UI file 'imagesearchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESEARCHDIALOG_H
#define UI_IMAGESEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ImageSearchDialog
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *screenAreaButton;
    QLabel *label;
    QPushButton *testClickButton;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QLabel *iconTargetSelected;
    QLabel *label_6;
    QLabel *iconSearchArea;
    QLabel *label_8;
    QPushButton *pushButton_5;
    QLabel *label_9;
    QPushButton *findButton;
    QComboBox *screenSelector;

    void setupUi(QDialog *ImageSearchDialog)
    {
        if (ImageSearchDialog->objectName().isEmpty())
            ImageSearchDialog->setObjectName(QString::fromUtf8("ImageSearchDialog"));
        ImageSearchDialog->resize(794, 556);
        ImageSearchDialog->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(46, 47, 48);"));
        buttonBox = new QDialogButtonBox(ImageSearchDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(false);
        buttonBox->setGeometry(QRect(310, 490, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        screenAreaButton = new QPushButton(ImageSearchDialog);
        screenAreaButton->setObjectName(QString::fromUtf8("screenAreaButton"));
        screenAreaButton->setGeometry(QRect(330, 140, 191, 51));
        label = new QLabel(ImageSearchDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 0, 691, 101));
        testClickButton = new QPushButton(ImageSearchDialog);
        testClickButton->setObjectName(QString::fromUtf8("testClickButton"));
        testClickButton->setEnabled(true);
        testClickButton->setGeometry(QRect(360, 380, 101, 51));
        testClickButton->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(ImageSearchDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 150, 261, 181));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setLineWidth(3);
        label_2->setMidLineWidth(2);
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../../Images to Search On Screen/search_area.bmp")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(ImageSearchDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 200, 171, 171));
        pushButton_4 = new QPushButton(ImageSearchDialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(170, 70, 191, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 11pt \"Segoe UI\";"));
        label_4 = new QLabel(ImageSearchDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 350, 241, 121));
        iconTargetSelected = new QLabel(ImageSearchDialog);
        iconTargetSelected->setObjectName(QString::fromUtf8("iconTargetSelected"));
        iconTargetSelected->setGeometry(QRect(40, 490, 41, 31));
        iconTargetSelected->setPixmap(QPixmap(QString::fromUtf8(":/red_check_mark.png")));
        iconTargetSelected->setScaledContents(true);
        label_6 = new QLabel(ImageSearchDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(110, 490, 191, 21));
        iconSearchArea = new QLabel(ImageSearchDialog);
        iconSearchArea->setObjectName(QString::fromUtf8("iconSearchArea"));
        iconSearchArea->setGeometry(QRect(720, 490, 41, 31));
        iconSearchArea->setPixmap(QPixmap(QString::fromUtf8(":/red_check_mark.png")));
        iconSearchArea->setScaledContents(true);
        label_8 = new QLabel(ImageSearchDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(520, 490, 181, 21));
        pushButton_5 = new QPushButton(ImageSearchDialog);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(480, 70, 191, 51));
        label_9 = new QLabel(ImageSearchDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(410, 80, 51, 31));
        findButton = new QPushButton(ImageSearchDialog);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        findButton->setEnabled(false);
        findButton->setGeometry(QRect(590, 220, 141, 101));
        findButton->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"color: rgb(81, 81, 81);\n"
""));
        findButton->setCheckable(false);
        screenSelector = new QComboBox(ImageSearchDialog);
        screenSelector->addItem(QString());
        screenSelector->addItem(QString());
        screenSelector->setObjectName(QString::fromUtf8("screenSelector"));
        screenSelector->setGeometry(QRect(610, 370, 101, 24));

        retranslateUi(ImageSearchDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ImageSearchDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ImageSearchDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ImageSearchDialog);
    } // setupUi

    void retranslateUi(QDialog *ImageSearchDialog)
    {
        ImageSearchDialog->setWindowTitle(QCoreApplication::translate("ImageSearchDialog", "Dialog", nullptr));
        screenAreaButton->setText(QCoreApplication::translate("ImageSearchDialog", "Select Screen Area", nullptr));
        label->setText(QCoreApplication::translate("ImageSearchDialog", "<html><head/><body><p align=\"center\">Image Search Tool</p><p align=\"center\"><span style=\" font-size:10pt; font-weight:700;\">Screen Resolution is 1920x1024</span></p><p align=\"center\"><span style=\" font-size:10pt; font-weight:700;\"><br/></span></p></body></html>", nullptr));
        testClickButton->setText(QCoreApplication::translate("ImageSearchDialog", "Test Click", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("ImageSearchDialog", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">Search Area Rectangle: </span></p><p>x0 = %1</p><p>y0 = %2</p><p>width = %3</p><p>height = %4</p></body></html>", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ImageSearchDialog", "Select Target \n"
"From Image  File", nullptr));
        label_4->setText(QCoreApplication::translate("ImageSearchDialog", "<html><head/><body><p><span style=\" font-weight:700;\">Coordinates found.</span></p><p><span style=\" font-weight:700;\">X = 345 Y = 456</span></p><p><br/></p></body></html>", nullptr));
        iconTargetSelected->setText(QString());
        label_6->setText(QCoreApplication::translate("ImageSearchDialog", "<html><head/><body><p>TARGET IMAGE  SELECTED!</p></body></html>", nullptr));
        iconSearchArea->setText(QString());
        label_8->setText(QCoreApplication::translate("ImageSearchDialog", "<html><head/><body><p>SEARCH AREA SELECTED!</p></body></html>", nullptr));
        pushButton_5->setText(QCoreApplication::translate("ImageSearchDialog", "Select Target \n"
"From Screen", nullptr));
        label_9->setText(QCoreApplication::translate("ImageSearchDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">OR</span></p></body></html>", nullptr));
        findButton->setText(QCoreApplication::translate("ImageSearchDialog", "Find", nullptr));
        screenSelector->setItemText(0, QCoreApplication::translate("ImageSearchDialog", "screen 0", nullptr));
        screenSelector->setItemText(1, QCoreApplication::translate("ImageSearchDialog", "screen 1", nullptr));

    } // retranslateUi

};

namespace Ui {
    class ImageSearchDialog: public Ui_ImageSearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESEARCHDIALOG_H
