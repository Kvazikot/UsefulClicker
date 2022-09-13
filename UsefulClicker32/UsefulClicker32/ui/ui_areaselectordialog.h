/********************************************************************************
** Form generated from reading UI file 'areaselectordialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AREASELECTORDIALOG_H
#define UI_AREASELECTORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_AreaSelectorDialog
{
public:

    void setupUi(QDialog *AreaSelectorDialog)
    {
        if (AreaSelectorDialog->objectName().isEmpty())
            AreaSelectorDialog->setObjectName(QString::fromUtf8("AreaSelectorDialog"));
        AreaSelectorDialog->setWindowModality(Qt::WindowModal);
        AreaSelectorDialog->resize(421, 376);
        AreaSelectorDialog->setWindowOpacity(0.800000000000000);
        AreaSelectorDialog->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(AreaSelectorDialog);

        QMetaObject::connectSlotsByName(AreaSelectorDialog);
    } // setupUi

    void retranslateUi(QDialog *AreaSelectorDialog)
    {
        AreaSelectorDialog->setWindowTitle(QCoreApplication::translate("AreaSelectorDialog", "Select screen area using this window", nullptr));
#if QT_CONFIG(tooltip)
        AreaSelectorDialog->setToolTip(QCoreApplication::translate("AreaSelectorDialog", "<html><head/><body><p>Select screen area using this window</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class AreaSelectorDialog: public Ui_AreaSelectorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AREASELECTORDIALOG_H
