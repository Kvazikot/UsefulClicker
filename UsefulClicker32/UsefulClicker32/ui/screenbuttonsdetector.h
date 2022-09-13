#ifndef SCREENBUTTONSDETECTOR_H
#define SCREENBUTTONSDETECTOR_H

#include <vector>
#include <QDialog>
#include <QShowEvent>
#include <QVector2D>
#include <set>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainterPath>
#include <QPaintEvent>
#include <QWheelEvent>
#include "ui/dialogtype.h"
#include "cv/rectangle_descriptor.h"

namespace Ui {
class ScreenButtonsDetector;
}

typedef std::map<int, std::set<int> > t_rectmap;

struct Wagon
{
    float d[4];
    QPoint junction_point;
    QRect  bounds;

    Wagon(){}

    Wagon(QRect  bounds, QPoint junction_point) :
        bounds(bounds), junction_point(junction_point)
    {
        calcDistances();
    }

    void calcDistances()
    {
        d[0] = QVector2D(junction_point - bounds.topLeft()).length();
        d[1] = QVector2D(junction_point - bounds.topRight()).length();
        d[2] = QVector2D(junction_point - bounds.bottomLeft()).length();
        d[3] = QVector2D(junction_point - bounds.bottomRight()).length();
    }

    QString toString()
    {
        QString out;
        out+=QString::number(junction_point.x())+",";
        out+=QString::number(junction_point.y())+",";
        for(int i=0; i < 4; i++ )
            out+=QString::number(d[i])+",";
        return out;
    }
};

struct Train
{
    t_rectmap xMap, yMap;
    std::vector<Wagon> Wagons;
    Train()
    {
    }
    void computeRectangleMaps(std::vector<QRect>& in_rects, t_rectmap& out_xMap, t_rectmap& out_yMap);
    void Generate(int n_Wagons, int startingRect, std::vector<QRect>& in_rects);
    void GenerateSpiral(int n_Wagons, int startingRect, std::vector<QRect>& in_rects);
    QString toString()
    {
        QString out;
        for(auto w : Wagons) out+=w.toString();
        return out;
    }
};


class ScreenButtonsDetector : public QDialog
{
    Q_OBJECT

public:
    explicit ScreenButtonsDetector(QWidget *parent = nullptr, int screenNumber=0);

    std::vector<Train* > trains;
    const int max_trains = 4;
    QPainterPath path;

    QWidget* parent_dialog;
    QMap<QString, QString> attrs;
    std::vector<QRect> rects;
    QPoint mpos;
    QRect selected_rect;
    int screenNum;
    RectangleDescriptor rectangle_descriptor;
    void Hide();
    void Show();
    void drawTrain(QPainter& painter, Train& train, QColor boarder_color=Qt::black, QColor fill_color=Qt::yellow);
    void keyPressEvent(QKeyEvent* event);
    bool setScreenNumber(int n);
    void showEvent(QShowEvent* event);
    void timerEvent(QTimerEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void paintEvent( QPaintEvent* event);
    void wheelEvent(QWheelEvent* event);
    void drawTrain(Train& train);
    ~ScreenButtonsDetector();

public slots:
    void on_doneButton_clicked();
    void setImage();
    void init();

signals:
    void sigSetAttrs(QMap<QString, QString> attrs);

private:
    Ui::ScreenButtonsDetector *ui;
};

#endif // SCREENBUTTONSDETECTOR_H
