#include "typedialog.h"
#include "log/logger.h"
#include "ui/widgets/keyboardbutton.h"
#include "ui_typedialog.h"

TypeDialog::TypeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TypeDialog)
{
    ui->setupUi(this);
}

TypeDialog::TypeDialog(QString mode) :
    QDialog(0),
    ui(new Ui::TypeDialog)
{
    ui->setupUi(this);

}

void TypeDialog::click()
{
    Log("click cliker");
}



TypeDialog::~TypeDialog()
{
    delete ui;
}

void TypeDialog::on_buttonBox_accepted()
{
    attrs["text"] = ui->plainTextEdit->toPlainText();
    if( ui->checkBox->isChecked() )
        attrs["mode"] = "copy_paste";
    emit sigSetAttrs(attrs);
}

