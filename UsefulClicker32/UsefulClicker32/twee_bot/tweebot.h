#ifndef TWEEBOT_H
#define TWEEBOT_H

#include <QMainWindow>

namespace Ui {
class TweeBot;
}

class TweeBot : public QMainWindow
{
    Q_OBJECT

public:
    explicit TweeBot(QWidget *parent = 0);
    ~TweeBot();

private:
    Ui::TweeBot *ui;
};

#endif // TWEEBOT_H
