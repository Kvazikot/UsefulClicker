#include <QTimer>
#include <QScreen>
#include <QGuiApplication>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include <QDir>
#include <QDebug>
#include <QSoundEffect>
#include "coordselector.h"
#include "ui_coordselector.h"

static std::vector<QRectF> rects;
static std::vector<QVector2D> velocitys;
static std::vector<QPoint> offsets;
static std::vector<int> sprite_indexes;
static QImage sprite[10];
static QImage bullet_sprite ;
static QMap<QString, QString> attrs;

#define rnd ((float)rand()/RAND_MAX)

CoordSelector::CoordSelector(QWidget *parent, bool withEasterEgg) :
    QDialog(0),
    ui(new Ui::CoordSelector)
{
    setWindowFlags(Qt::Widget );
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_AlwaysStackOnTop, true);
    setAttribute(Qt::WA_WState_WindowOpacitySet);
    setAttribute(Qt::WA_PaintOnScreen); // not needed in Qt 5.2 and up
    setCursor(Qt::CrossCursor);
    showEasterEgg = withEasterEgg;
    ui->setupUi(this);

    QImage bg_image(300,300,QImage::Format_ARGB32);
    bg_image.fill(QColor(100,100,100,0));
    hit = false;
    sprite[0] = QImage(":/images/putler.jpg");
    sprite[1] = QImage(":/images/hitler_face.png");
    sprite[2] = QImage(":/images/stalin.jpg");
    bullet_sprite =QImage(":/images/bullet.png");
    bullet_sound.setSource(QUrl::fromLocalFile(":/sounds/shot.wav"));

    for(int i=0; i < n_rects+11; i++)
    {
        rects.push_back(QRect(1,1,100,100));
        velocitys.push_back(QVector2D(1,1));
        offsets.push_back(QPoint(rnd*30,rnd*30));
        sprite_indexes.push_back(0);
    }
    generate_rects();
    frame = 0;

    startTimer(10);
    QTimer::singleShot(10000, this, SLOT(clickDelay()));

}


void CoordSelector::generate_rects()
{
    for(int i=0; i < n_rects; i++)
    {
        float x,y,w,h;
        x =  rnd * (float)rect().width();
        y =  rnd * (float)rect().height();
        w = 10 + 200. * rnd;
        h = w;
        QRectF r(x,y,w,h);
        rects[i] = r;
        float scale = rnd * 10;
        velocitys[i] = QVector2D(scale*rnd,scale*rnd);
        sprite_indexes[i] = qRound(rnd * 3);
    }

}

CoordSelector::~CoordSelector()
{
    delete ui;
}


void CoordSelector::mousePressEvent(QMouseEvent* event)
{

    //process selected rectangle

    attrs["x"] = QString::number(mpos.x());
    attrs["y"] = QString::number(mpos.y());

    if(!showEasterEgg)
    {
        emit sigSetAttrs(attrs);
        done(1);
        return;
    }
    hit = false;
    for(int i=0; i < n_rects; i++)
    {
        QRectF r = rects[i];
        if( r.contains(mpos) )
        {
            hit_rect = r;
            n_hited = i;
            hitPoint = mpos;
            hit = true;
            bullet_sound.play();
            QTimer::singleShot(70, this, SLOT(clickDelay()));

            qDebug() << " n_hited " << n_hited;
            //velocitys[i] = QVector2D(rnd*10, rnd*10);
            //velocitys[i].setX(velocitys[i].x()*100);
            //velocitys[i].setY(velocitys[i].y()*100);
            int j = sprite_indexes[i];
            if( j==0 )
                score+=100;
            else
                score+=10000;
        }
    }



    event->accept();
}

void CoordSelector::clickDelay()
{
    hit = false;
    for(int i=0; i < n_rects; i++)
    {
        QRectF r = rects[i];
        if( r.contains(mpos) )
        {
            velocitys[i] = QVector2D(rnd*10, rnd*10);
            velocitys[i].setX(velocitys[i].x()*100);
            velocitys[i].setY(velocitys[i].y()*100);
        }
    }
    QTimer::singleShot(2000, this, SLOT(closeDelaySlot()));


}

void CoordSelector::mouseMoveEvent(QMouseEvent* event)
{
    mpos = QPoint(event->x(),event->y());
    for(int i=0; i < n_rects; i++)
    {
        QRectF r = rects[i];
        if( r.contains(mpos) )
        {
            hit_rect = r;
            n_hited = i;
        }
    }

    repaint();
    event->accept();
}

void CoordSelector::wheelEvent(QWheelEvent* event)
{

}


void CoordSelector::animate()
{
    if( !showEasterEgg) return;

    QPainter painter(this);
    QRect r4(mpos.x(), mpos.y(),100,100);
    //qDebug() << __FUNCTION__ << r;
    r4.moveCenter(mpos);

    if( frame > n_rects )
        frame = 0;

    QFont f;
    f.setBold(true);
    f.setPixelSize(36);
    painter.setFont(f);
    painter.setPen(Qt::red);

    // draw rects
    //int i = frame;
    for(int i=0; i < n_rects; i++)
    {
        QRectF r = rects[i];
        float x = r.left() + velocitys[i].x() ;
        float y = r.top() + velocitys[i].y();


        rects[i] = QRectF(x,y,r.width(),r.height());
        painter.fillRect(rects[i], Qt::red);
        int j = sprite_indexes[i];
        painter.drawImage(rects[i], sprite[j]);
        if( j==0 )
            painter.drawText(rects[i].topLeft(),"pathetic looser");
        else
            painter.drawText(rects[i].topLeft(),"looser");
        if(i == n_hited && hit)
        {
           painter.drawImage(hitPoint, bullet_sprite);
        }

    }

    //painter.fillRect(r4, QColor());

    f.setBold(true);
    f.setPixelSize(24);
    painter.setFont(f);
    painter.setPen(Qt::red);


    //QString s = QString("Left click to select coordinates. Score").arg(score);
    //painter.drawText(0,1000, s);
    QString s = QString("Score = %1").arg(score);
    painter.drawText(0,1000, s);

}


bool CoordSelector::setScreenNumber(int n)
{
    if( QGuiApplication::screens().size() < n)
    {
        //setScreen(QGuiApplication::screens()[0]);
        return false;
    }
    screenNum = n;
    auto scr = QGuiApplication::screens()[screenNum];
    //setScreen(scr);
    setGeometry(scr->geometry());
    qDebug() << __FUNCTION__ << scr->geometry();
    return true;
}

void CoordSelector::paintEvent( QPaintEvent* event)
{
    animate();
    event->accept();
    frame++;
}

void CoordSelector::timerEvent(QTimerEvent* event)
{
    repaint();
    event->accept();
}

void CoordSelector::on_doneButton_clicked()
{

}

void CoordSelector::showEvent(QShowEvent* event)
{    
    //setWindowState(Qt::WindowFullScreen);
    //QTimer::singleShot(500, this, SLOT(slotFullScreen()));
    if( screenNum > QGuiApplication::screens().size() ) return;
    QScreen* screen = QGuiApplication::screens()[screenNum];
    setGeometry(screen->geometry());
    setCursor(Qt::CrossCursor);
    event->accept();
    showFullScreen();
}

void CoordSelector::closeDelaySlot()
{
    emit sigSetAttrs(attrs);
    close();

}
