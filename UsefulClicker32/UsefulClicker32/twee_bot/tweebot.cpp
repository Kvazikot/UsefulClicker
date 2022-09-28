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

    TestTwitterActivity test1;
    test1.run();
}

void TweeBot::timerEvent(QTimerEvent* event)
{
    QDateTime dt = QDateTime::currentDateTime();

    QString s = "<html><head/><body><p>now " + dt.toString("hh:mm:ss") + "</p></body></html>";
    ui->timerLabel->setText(s);
}

TweeBot::~TweeBot()
{
    delete ui;
}
