#include <QPainter>
#include <QGridLayout>
#include <QDir>
#include <QPainterPath>
#include <QPen>
#include <QGuiApplication>
#include <QLabel>
#include "delaywidget.h"
#include "ui/widgets/svgwidget.h"

static SvgWidget* widget;
static QLabel* label;

DelayWidget::DelayWidget(QWidget *parent)
    : QWidget{parent}
{
    setWindowFlags(Qt::Widget );
    setAttribute(Qt::WA_MouseTracking, true);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_WState_WindowOpacitySet);
    setAttribute(Qt::WA_PaintOnScreen);
    setCursor(Qt::CrossCursor);
    frame = 0;
    repeats = 0;
    setMouseTracking(true);
    //setWindowOpacity(0.3);
//    setTra

    QString filename = QDir::currentPath() + "/ui/widgets/delay_widget.svg";
    widget = new SvgWidget(this);
    if( widget->SvgLoad(filename) )
    {
        widget->LoadDocument(filename);
        QGridLayout* layout = new QGridLayout();
        layout->addWidget(widget);
        setLayout(layout);
        widget->show();

    }
    startTimer(10);
}

void DelayWidget::mouseReleaseEvent(QMouseEvent* event)
{
    event->accept();

}


void DelayWidget::showEvent(QShowEvent* event)
{
    showFullScreen();
    QScreen* screen = QGuiApplication::screens()[0];
    QRect r(0,0,500,500);
    r.moveTopLeft(screen->geometry().center() - QPoint(250,250));
    screenshot = screen->grabWindow(0,0,0,screen->geometry().width(), screen->geometry().height());
    screenshot.save("pixm.png");
    setGeometry(r);
}

#define rnd(a,b) ((((float)rand() /RAND_MAX) - 0.5f) * a + b)

void DelayWidget::timerEvent(QTimerEvent* event)
{
    QRectF elipse = widget->getEllipse("path1042-1-5");
    //qDebug() << "read elipse " << elipse;

    c = elipse.center();
    double dist = QVector2D(mlocalPos).distanceToPoint(QVector2D(c));
    double r = dist/2 + rnd(10,10);

    elipse.setCoords(c.x()-r,c.y()-r,c.x()+r,c.y()+r);
    widget->setEllipse("path1042-1-5", elipse);


    QRectF elipse2 = widget->getEllipse("path1042");
    //qDebug() << "read elipse " << elipse;

    c = elipse2.center();
    r = dist + rnd(10,10);
    elipse2.setCoords(c.x()-r,c.y()-r,c.x()+r,c.y()+r);
    widget->setEllipse("path1042", elipse2);

    QRadialGradient g = widget->getRadialGradient("radialGradient1451");
    double r1 = dist;
    g.setRadius(r1);
    //g.setFocalRadius(r1);
    widget->setRadialGradient("radialGradient1451", g);

    //qDebug() << "dist " << dist;

    // set fixed delay text
    QPointF d = c - mlocalPos;
    float angle;
    if(d.y() > 0)
    {
        if(d.x() > 0)
            angle = 270 + qRadiansToDegrees(atan2(d.y(),d.x()));
        else
            angle = qRadiansToDegrees(atan2(d.y(),d.x())-M_PI_2);
    }
    else
        angle = qRadiansToDegrees(M_PI_2 + M_PI - atan2(-d.y(),d.x()));

    static char num[100];
    sprintf(num,"%3.1f",angle);
    delay_fixed = angle;
    widget->setText("text12424-4", QString(num));

    // set random delay text
    sprintf(num,"%3.1f",dist/10);
    delay_random = (dist/10);
    widget->setText("text12424", QString(num));

    // set repeats
    sprintf(num,"%03d",repeats);
    widget->setText("text12424-7", QString(num));



    widget->LoadRenderDOM();

    //qDebug() << "frame " << frame;
    //qDebug() << "r " << r;
    //qDebug() << "r1 " << r1;

    //qDebug() << "write elipse " << elipse;
    repaint();


    frame++;
}
void DelayWidget::mouseMoveEvent(QMouseEvent* event)
{    
    mpos = QPointF(event->globalPos());
    mlocalPos = event->localPos();
    //qDebug() << __FUNCTION__ << mlocalPos;
}
void DelayWidget::mousePressEvent(QMouseEvent* event)
{
}
void DelayWidget::paintEvent( QPaintEvent* event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(rect(),Qt::red);
    QScreen* screen = QGuiApplication::screens()[0];
    QRect r(0,0,500,500);
    r.moveTopLeft(screen->geometry().center() - QPoint(250,250));
    painter.drawPixmap(rect(), screenshot, r);
    event->accept();

    //draw mouse point
    QPainterPath path;
    path.addEllipse(mlocalPos, 10, 10);
    QPen pen;
    pen.setWidth(20);
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.drawLine(mlocalPos, c);
    painter.fillPath(path, Qt::green);
    painter.drawText(mlocalPos.toPoint(), QString::number(22));
    //painter.drawLine(mlocalPos, c);

    /*
    QPainter painter;
    QRect rect(0,0,bigTimerRadius,bigTimerRadius);
    rect.moveCenter(this->rect().center());
    painter.setPen(Qt::black);

    painter.drawEllipse(rect);
    */

}

void DelayWidget::keyPressEvent(QKeyEvent* event)
{
    event->accept();
    if( event->key() == Qt::Key_Return )
    {
        emit ready();
        close();
    }
}

void DelayWidget::wheelEvent(QWheelEvent* event)
{
    if( event->angleDelta().y() > 0 )
        repeats++;
    else
        repeats--;

    qDebug() << repeats;
}

