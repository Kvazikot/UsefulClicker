#ifndef SHELLDIALOG_H
#define SHELLDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QMap>

namespace Ui {
class ShellDialog;
}

class ShellDialog : public QDialog
{
    Q_OBJECT

public:
    QMap<QString,QString> attrs;
    explicit ShellDialog(QWidget *parent = nullptr);
    ~ShellDialog();

signals:
    void sigSetAttrs(QMap<QString,QString> attrs);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ShellDialog *ui;
};

#endif // SHELLDIALOG_H
