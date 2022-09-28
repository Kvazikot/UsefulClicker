#ifndef TWEEBOT_H
#define TWEEBOT_H

#include <QMainWindow>
#include <QTimerEvent>

namespace Ui {
class TweeBot;
}

class TweeBot : public QMainWindow
{
    Q_OBJECT

public:
    int step;
    explicit TweeBot(QWidget *parent = 0);
    void timerEvent(QTimerEvent* event);
    ~TweeBot();

private:
    Ui::TweeBot *ui;
};

#endif // TWEEBOT_H
