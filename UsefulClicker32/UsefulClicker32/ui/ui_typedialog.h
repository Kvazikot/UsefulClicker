/********************************************************************************
** Form generated from reading UI file 'typedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TYPEDIALOG_H
#define UI_TYPEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_TypeDialog
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *plainTextEdit;
    QDialogButtonBox *buttonBox;
    QCheckBox *checkBox;

    void setupUi(QDialog *TypeDialog)
    {
        if (TypeDialog->objectName().isEmpty())
            TypeDialog->setObjectName(QString::fromUtf8("TypeDialog"));
        TypeDialog->resize(779, 512);
        gridLayout = new QGridLayout(TypeDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plainTextEdit = new QPlainTextEdit(TypeDialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 0, 0, 1, 2);

        buttonBox = new QDialogButtonBox(TypeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        checkBox = new QCheckBox(TypeDialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 1, 1, 1, 1);


        retranslateUi(TypeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TypeDialog, &QDialog::accept);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TypeDialog, &QDialog::reject);

        QMetaObject::connectSlotsByName(TypeDialog);
    } // setupUi

    void retranslateUi(QDialog *TypeDialog)
    {
        TypeDialog->setWindowTitle(QCoreApplication::translate("TypeDialog", "<type> tag text", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("TypeDialog", "Text that is inserted in the window. Simulating keydown event for every symbol with delay.", nullptr));
        checkBox->setText(QCoreApplication::translate("TypeDialog", "do paste from clipboard (ctrl+v)\n"
" instead of typing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TypeDialog: public Ui_TypeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TYPEDIALOG_H
