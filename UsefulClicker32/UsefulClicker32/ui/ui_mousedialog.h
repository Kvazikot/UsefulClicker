/********************************************************************************
** Form generated from reading UI file 'mousedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOUSEDIALOG_H
#define UI_MOUSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include "widgets/delaywidget.h"

QT_BEGIN_NAMESPACE

class Ui_MouseDialog
{
public:
    QLabel *keySequenceLabel;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    DelayWidget *delayWidget;
    QLabel *tipLabel;

    void setupUi(QDialog *MouseDialog)
    {
        if (MouseDialog->objectName().isEmpty())
            MouseDialog->setObjectName(QString::fromUtf8("MouseDialog"));
        MouseDialog->resize(1450, 811);
        MouseDialog->setWindowOpacity(0.300000000000000);
        keySequenceLabel = new QLabel(MouseDialog);
        keySequenceLabel->setObjectName(QString::fromUtf8("keySequenceLabel"));
        keySequenceLabel->setGeometry(QRect(190, 170, 371, 61));
        keySequenceLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(MouseDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 160, 131, 91));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/images/keyboard_icon.png")));
        label_8->setScaledContents(true);
        label_4 = new QLabel(MouseDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(590, 10, 281, 61));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(MouseDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1050, 10, 261, 61));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(MouseDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(12, 12, 100, 100));
        label->setMaximumSize(QSize(100, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/mouse_left_click.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(MouseDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(119, 12, 261, 61));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(MouseDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(454, 20, 100, 100));
        label_3->setMaximumSize(QSize(100, 100));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/mouse_right_click.png")));
        label_3->setScaledContents(true);
        label_5 = new QLabel(MouseDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(903, 20, 100, 100));
        label_5->setMaximumSize(QSize(100, 100));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/mouse_scroll.png")));
        label_5->setScaledContents(true);
        delayWidget = new DelayWidget(MouseDialog);
        delayWidget->setObjectName(QString::fromUtf8("delayWidget"));
        delayWidget->setGeometry(QRect(290, 360, 641, 411));
        tipLabel = new QLabel(MouseDialog);
        tipLabel->setObjectName(QString::fromUtf8("tipLabel"));
        tipLabel->setGeometry(QRect(40, 310, 391, 261));
        tipLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tipLabel->setAlignment(Qt::AlignCenter);
        tipLabel->setWordWrap(true);

        retranslateUi(MouseDialog);

        QMetaObject::connectSlotsByName(MouseDialog);
    } // setupUi

    void retranslateUi(QDialog *MouseDialog)
    {
        MouseDialog->setWindowTitle(QCoreApplication::translate("MouseDialog", "Dialog", nullptr));
        keySequenceLabel->setText(QCoreApplication::translate("MouseDialog", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700; color:#00007f;\">Press keysequence</span></p></body></html>", nullptr));
        label_8->setText(QString());
        label_4->setText(QCoreApplication::translate("MouseDialog", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700; color:#ff0000;\">Press right buton</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MouseDialog", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700; color:#ff0000;\">Scroll wheel </span></p></body></html>", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MouseDialog", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700; color:#ff0000;\">Press left buton</span></p></body></html>", nullptr));
        label_3->setText(QString());
        label_5->setText(QString());
        tipLabel->setText(QCoreApplication::translate("MouseDialog", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700; color:#00007f;\">Press F2 to set delay</span></p><p><span style=\" font-size:24pt; font-weight:700; color:#00007f;\">Press F3 to set area</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MouseDialog: public Ui_MouseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUSEDIALOG_H
