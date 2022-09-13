#include <QPainter>
#include <QGridLayout>
#include <QDir>
#include <QPainterPath>
#include <QPen>
#include <QGuiApplication>
#include <QLabel>
#include "ui/widgets/svgwidget.h"
#include "ui/widgets/dimensionswidget.h"
#include "ui_dimensionswidget.h"

static SvgWidget* widget;
static QLabel* label;


DimensionsWidget::DimensionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DimensionsWidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget );
    setAttribute(Qt::WA_MouseTracking, true);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_WState_WindowOpacitySet);
    setAttribute(Qt::WA_PaintOnScreen);
    setCursor(Qt::CrossCursor);
    frame = 0;
    wheels = 0;
    setMouseTracking(true);
    //setWindowOpacity(0.3);
//    setTra

    QString filename = QDir::currentPath() + "/ui/widgets/rect_widget.svg";
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

DimensionsWidget::~DimensionsWidget()
{
    delete ui;
}


void DimensionsWidget::mouseReleaseEvent(QMouseEvent* event)
{
    event->accept();

}


void DimensionsWidget::showEvent(QShowEvent* event)
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

void DimensionsWidget::timerEvent(QTimerEvent* event)
{

    QRectF width_ruler_rect = widget->getRect("width_ruler_rect");
    QRectF height_ruler_rect = widget->getRect("height_ruler_rect");

    float sx = 0.23458333 * wheels;
    float sy = 0.26458333;
    float tx = width_ruler_rect.width()/2;
    QString transform = QString("scale(%1,%2),translate(%3)")
                                .arg(sx).arg(sy).arg(tx);

    widget->setTransform("width_ruler_rect", transform);

            //scale(0.23458333,0.26458333),translate(11)

    static char num[100];
    sprintf(num,"%3.1f",1);
    widget->setText("text12424-4", QString(num));


    widget->LoadRenderDOM();

    repaint();


    frame++;
}
void DimensionsWidget::mouseMoveEvent(QMouseEvent* event)
{
    mpos = QPointF(event->globalPos());
    mlocalPos = event->localPos();
    //qDebug() << __FUNCTION__ << mlocalPos;
}
void DimensionsWidget::mousePressEvent(QMouseEvent* event)
{
}
void DimensionsWidget::paintEvent( QPaintEvent* event)
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

void DimensionsWidget::keyPressEvent(QKeyEvent* event)
{
    event->accept();
    if( event->key() == Qt::Key_Return )
    {
        emit ready();
        close();
    }
}

void DimensionsWidget::wheelEvent(QWheelEvent* event)
{
    if( event->angleDelta().y() > 0 )
        wheels++;
    else
        wheels--;

    qDebug() << wheels;
}

