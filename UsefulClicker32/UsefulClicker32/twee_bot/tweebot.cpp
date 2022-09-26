#include "tweebot.h"
#include "ui_tweebot.h"

TweeBot::TweeBot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TweeBot)
{
    ui->setupUi(this);
}

TweeBot::~TweeBot()
{
    delete ui;
}
