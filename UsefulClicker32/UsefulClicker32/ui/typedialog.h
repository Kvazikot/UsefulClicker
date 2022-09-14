#ifndef TYPEDIALOG_H
#define TYPEDIALOG_H

#include <QDialog>
#include <QMap>

namespace Ui {
class TypeDialog;
}

class TypeDialog : public QDialog
{
    Q_OBJECT
public:
    QMap<QString,QString> attrs;
    explicit TypeDialog(QWidget *parent = nullptr);
    explicit TypeDialog(QString mode);
    //void mousePressEvent(QMouseEvent *ev) override;
    //void timerEvent(QTimerEvent* event) override;

    ~TypeDialog();

signals:
    void sigSetAttrs(QMap<QString,QString>);

private slots:
    void on_buttonBox_accepted();
    void click();

private:
    Ui::TypeDialog *ui;
};

#endif // TYPEDIALOG_H
