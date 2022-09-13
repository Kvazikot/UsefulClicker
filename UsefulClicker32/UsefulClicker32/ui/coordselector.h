#ifndef COORDSELECTOR_H
#define COORDSELECTOR_H

#include <QDialog>
#include <QMap>
#include <QElapsedTimer>
#include <QVector2D>
#include <QSoundEffect>

namespace Ui {
class CoordSelector;
}

class CoordSelector : public QDialog
{
    Q_OBJECT

public:
    int screenNum=0;
    explicit CoordSelector(QWidget *parent = nullptr, bool withEasterEgg=false);
    ~CoordSelector();
    QPoint mpos;
    QRectF hit_rect;
    QCursor cursor;
    QSoundEffect bullet_sound;
    QPixmap cursor_pixmap;
    QElapsedTimer timeSinceHit;
    QPoint hitPoint;
    int n_rects = 10;
    int score = 10;
    int frame;
    int n_hited;
    bool hit;
    bool showEasterEgg;
    void animate();
    bool setScreenNumber(int n);
    void generate_rects();
    void showEvent(QShowEvent* event) override;
    void timerEvent(QTimerEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void paintEvent( QPaintEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
public slots:
    void on_doneButton_clicked();
    void closeDelaySlot();
    void clickDelay();
signals:
    void sigSetAttrs(QMap<QString, QString> attrs);


private:
    Ui::CoordSelector *ui;
};

#endif // COORDSELECTOR_H
