#include <QPlainTextEdit>
#include "tweebot.h"
#include "ui_tweebot.h"

#include "twee_bot/regularactivity.h"

QPlainTextEdit* mainInstance;

void print(QString s)
{
    mainInstance->appendPlainText(s);
}

TweeBot::TweeBot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TweeBot)
{
    ui->setupUi(this);
    mainInstance = ui->consoleEdit;
    startTimer(100);

}

void TweeBot::timerEvent(QTimerEvent* event)
{
    QDateTime dt = QDateTime::currentDateTime();

    QString s = "<html><head/><body><p>now " + dt.toString("hh:mm:ss") + "</p></body></html>";
    ui->timerLabel->setText(s);
    event->accept();
}

TweeBot::~TweeBot()
{
    delete ui;
}

void TweeBot::on_pushButton_clicked()
{

}

void TweeBot::on_toolButton_2_clicked()
{
    TestTwitterActivity test1;
    test1.run();
}
