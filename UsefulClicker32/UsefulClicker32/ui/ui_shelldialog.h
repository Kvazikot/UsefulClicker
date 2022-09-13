/********************************************************************************
** Form generated from reading UI file 'shelldialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHELLDIALOG_H
#define UI_SHELLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include "ui/widgets/qconsole.h"

QT_BEGIN_NAMESPACE

class Ui_ShellDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *commandEdit;
    QDialogButtonBox *buttonBox;
    QConsole *console;

    void setupUi(QDialog *ShellDialog)
    {
        if (ShellDialog->objectName().isEmpty())
            ShellDialog->setObjectName(QString::fromUtf8("ShellDialog"));
        ShellDialog->resize(743, 459);
        ShellDialog->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));"));
        gridLayout = new QGridLayout(ShellDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ShellDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 170, 127,0);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(ShellDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 170, 127,0);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        commandEdit = new QPlainTextEdit(ShellDialog);
        commandEdit->setObjectName(QString::fromUtf8("commandEdit"));
        commandEdit->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(commandEdit->sizePolicy().hasHeightForWidth());
        commandEdit->setSizePolicy(sizePolicy);
        commandEdit->setMaximumSize(QSize(16777215, 80));
        commandEdit->setAutoFillBackground(false);
        commandEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(126, 91, 162);\n"
"color: rgb(115, 255, 73);\n"
"font: 700 9pt \"Segoe UI\";\n"
"border-color: rgb(85, 0, 0);\n"
""));
        commandEdit->setFrameShape(QFrame::Box);
        commandEdit->setFrameShadow(QFrame::Sunken);
        commandEdit->setLineWidth(5);
        commandEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        gridLayout->addWidget(commandEdit, 1, 0, 1, 2);

        buttonBox = new QDialogButtonBox(ShellDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 9pt \"Segoe UI\";"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 0, 1, 1, 1);

        console = new QConsole(ShellDialog);
        console->setObjectName(QString::fromUtf8("console"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(console->sizePolicy().hasHeightForWidth());
        console->setSizePolicy(sizePolicy1);
        console->setMinimumSize(QSize(0, 300));
        console->setMouseTracking(false);
        console->setFocusPolicy(Qt::ClickFocus);
        console->setStyleSheet(QString::fromUtf8("background-color: rgb(126, 91, 162);\n"
"color: rgb(115, 255, 73);\n"
"font: 700 9pt \"Segoe UI\";"));

        gridLayout->addWidget(console, 2, 0, 1, 2);


        retranslateUi(ShellDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ShellDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ShellDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ShellDialog);
    } // setupUi

    void retranslateUi(QDialog *ShellDialog)
    {
        ShellDialog->setWindowTitle(QCoreApplication::translate("ShellDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ShellDialog", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:700; vertical-align:super;\">Shell command editor</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("ShellDialog", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:700; vertical-align:super;\">Command history (see settings.ini) </span></p></body></html>", nullptr));
        commandEdit->setPlainText(QCoreApplication::translate("ShellDialog", "start /B python start.py\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShellDialog: public Ui_ShellDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHELLDIALOG_H
