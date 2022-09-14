#ifndef DIMENSIONSWIDGET_H
#define DIMENSIONSWIDGET_H

#include <QWidget>
#include <QMap>
namespace Ui {
class DimensionsWidget;
}

class DimensionsWidget : public QWidget
{
    Q_OBJECT

public:
    ~DimensionsWidget();
    QPixmap screenshot;
    QPointF mpos, mlocalPos, c;

    int bigTimerRadius = 150;
    int wheels;
    int frame=0;
    explicit DimensionsWidget(QWidget *parent = nullptr);
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

private:
    Ui::DimensionsWidget *ui;
};

#endif // DIMENSIONSWIDGET_H
