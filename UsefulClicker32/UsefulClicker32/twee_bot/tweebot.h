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

private slots:
    void on_pushButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::TweeBot *ui;
};

#endif // TWEEBOT_H
