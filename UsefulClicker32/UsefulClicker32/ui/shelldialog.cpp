#include "shelldialog.h"
#include "ui_shelldialog.h"

ShellDialog::ShellDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShellDialog)
{
    ui->setupUi(this);
}

ShellDialog::~ShellDialog()
{
    ui->console->closeThread();
    delete ui;
}

void ShellDialog::on_buttonBox_accepted()
{
    ui->console->closeThread();
    QString cmd = ui->commandEdit->toPlainText();
    QStringList list = cmd.split("\n");
    if( list.length() > 0 )
        attrs["cmd"] = "\"" + list[0] + "\"";
    else
        attrs["cmd"] = "\"" + cmd + "\"";
    emit sigSetAttrs(attrs);
}


void ShellDialog::on_buttonBox_rejected()
{
    on_buttonBox_accepted();
}

