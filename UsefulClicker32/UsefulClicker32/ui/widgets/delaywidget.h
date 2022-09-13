#ifndef DELAYWIDGET_H
#define DELAYWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QShowEvent>
#include <QKeyEvent>
#include <QWheelEvent>



class DelayWidget : public QWidget
{
    Q_OBJECT
public:
    QPixmap screenshot;
    QPointF mpos, mlocalPos, c;

    int bigTimerRadius = 150;
    int frame=0;
    int repeats=0;
    int delay_fixed;
    int delay_random;
    explicit DelayWidget(QWidget *parent = nullptr);
    void showEvent(QShowEvent* event);
    void timerEvent(QTimerEvent* event);
    void keyPressEvent(QKeyEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;


signals:
    void sigSetAttrs(QMap<QString,QString> attrs);
    void ready();

};

#endif // DELAYWIDGET_H
