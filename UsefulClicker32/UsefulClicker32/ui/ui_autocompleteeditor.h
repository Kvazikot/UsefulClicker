/********************************************************************************
** Form generated from reading UI file 'autocompleteeditor.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOCOMPLETEEDITOR_H
#define UI_AUTOCOMPLETEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutocompleteEditor
{
public:

    void setupUi(QWidget *AutocompleteEditor)
    {
        if (AutocompleteEditor->objectName().isEmpty())
            AutocompleteEditor->setObjectName(QString::fromUtf8("AutocompleteEditor"));
        AutocompleteEditor->resize(287, 117);

        retranslateUi(AutocompleteEditor);

        QMetaObject::connectSlotsByName(AutocompleteEditor);
    } // setupUi

    void retranslateUi(QWidget *AutocompleteEditor)
    {
        AutocompleteEditor->setWindowTitle(QCoreApplication::translate("AutocompleteEditor", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AutocompleteEditor: public Ui_AutocompleteEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOCOMPLETEEDITOR_H
