/********************************************************************************
** Form generated from reading UI file 'dimensionswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIMENSIONSWIDGET_H
#define UI_DIMENSIONSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DimensionsWidget
{
public:

    void setupUi(QWidget *DimensionsWidget)
    {
        if (DimensionsWidget->objectName().isEmpty())
            DimensionsWidget->setObjectName(QString::fromUtf8("DimensionsWidget"));
        DimensionsWidget->resize(492, 431);

        retranslateUi(DimensionsWidget);

        QMetaObject::connectSlotsByName(DimensionsWidget);
    } // setupUi

    void retranslateUi(QWidget *DimensionsWidget)
    {
        DimensionsWidget->setWindowTitle(QCoreApplication::translate("DimensionsWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DimensionsWidget: public Ui_DimensionsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIMENSIONSWIDGET_H
