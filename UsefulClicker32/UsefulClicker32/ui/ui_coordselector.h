/********************************************************************************
** Form generated from reading UI file 'coordselector.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COORDSELECTOR_H
#define UI_COORDSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CoordSelector
{
public:
    QLabel *label;

    void setupUi(QDialog *CoordSelector)
    {
        if (CoordSelector->objectName().isEmpty())
            CoordSelector->setObjectName(QString::fromUtf8("CoordSelector"));
        CoordSelector->resize(400, 300);
        CoordSelector->setMouseTracking(true);
        CoordSelector->setWindowOpacity(0.300000000000000);
        label = new QLabel(CoordSelector);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 291, 121));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(5, 17, 255, 111);"));

        retranslateUi(CoordSelector);

        QMetaObject::connectSlotsByName(CoordSelector);
    } // setupUi

    void retranslateUi(QDialog *CoordSelector)
    {
        CoordSelector->setWindowTitle(QCoreApplication::translate("CoordSelector", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CoordSelector", "<html><head/><body><p align=\"center\">Select screen area using this window</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CoordSelector: public Ui_CoordSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COORDSELECTOR_H
