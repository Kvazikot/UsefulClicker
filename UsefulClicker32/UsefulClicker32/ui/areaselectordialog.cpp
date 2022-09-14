/*
+ - - - + - + - -
+ - + - + copyright by Vladimir Baranov (Kvazikot)  <br>
+ - + - + email: vsbaranov83@gmail.com  <br>
+ - + - + github: https://github.com/Kvazikot/UsefulMacro/  <br>
```
                          )            (
                         /(   (\___/)  )\
                        ( #)  \ ('')| ( #
                         ||___c\  > '__||
                         ||**** ),_/ **'|
                   .__   |'* ___| |___*'|
                    \_\  |' (    ~   ,)'|
                     ((  |' /(.  '  .)\ |
                      \\_|_/ <_ _____> \______________
                       /   '-, \   / ,-'      ______  \
              b'ger   /      (//   \\)     __/     /   \
                                          './_____/
```
*/

#include <QPainter>
#include <QPushButton>
#include <QScreen>
#include <QTimer>
#include <QDateTime>
#include <QPainterPath>
#include <QDir>
#include "windows.h"
#include "areaselectordialog.h"
#include "ui_areaselectordialog.h"
#include <opencv2/opencv.hpp>

using namespace cv;

AreaSelectorDialog::AreaSelectorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AreaSelectorDialog)
{
    setWindowFlags(Qt::Widget );
    setParent(0); // Create TopLevel-Widget
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_WState_WindowOpacitySet);
    setAttribute(Qt::WA_PaintOnScreen); // not needed in Qt 5.2 and up
    ui->setupUi(this);
    QImage bg_image(300,300,QImage::Format_ARGB32);
    bg_image.fill(QColor(100,100,100,200));
    //ui->label->setPixmap(QPixmap::fromImage(bg_image));
    screenNum = 0;
    fullscreenMode = false;

    QPushButton* done_button = new QPushButton(this);
    done_button->setGeometry(0,0,100,100);
    QSizePolicy pol;
    pol.setHorizontalPolicy(QSizePolicy::Minimum);
    done_button->setSizePolicy(pol);
    done_button->setText("done!");
    done_button->show();
    connect(done_button, SIGNAL(clicked()), this, SLOT(on_doneButton_clicked()));

    startTimer(100);

}

void AreaSelectorDialog::setScreen(int n)
{
    screenNum = n;
}

void AreaSelectorDialog::selectByWindow()
{

}

void AreaSelectorDialog::slotFullScreen()
{

    QScreen* screen = QGuiApplication::screens()[screenNum];
    setGeometry(screen->geometry());
    rect_image = QImage(screen->geometry().width(),screen->geometry().height(), QImage::Format_ARGB32);
    //ui->label->setGeometry(screen->geometry());
    setCursor(Qt::CrossCursor);

}

void AreaSelectorDialog::fullScreen()
{
    fullscreenMode = true;
    show();
    //ui->label->setVisible(false);

    QTimer::singleShot(500, this, SLOT(slotFullScreen()));
}


QPixmap AreaSelectorDialog::makeScreenshot()
{
    //makeScreenshot();
    QScreen* screen = QGuiApplication::screens()[screenNum];
    screenshot = screen->grabWindow(0,0,0,screen->geometry().width(), screen->geometry().height());
    return screenshot;
    //screenshot.save("screenshot.png");

}

void AreaSelectorDialog::selectTargetImage()
{
    //QDesktopWidget* desktop = QApplication::desktop();
    int screenNum = 0;
    fullscreenMode = false;
    QScreen* screen = QGuiApplication::screens()[screenNum];
    setGeometry(screen->geometry());
    rect_image = QImage(screen->geometry().width(),screen->geometry().height(), QImage::Format_ARGB32);

}

void AreaSelectorDialog::showEvent(QShowEvent* event)
{
    return;
    SetWindowPos
    (
        (HWND)winId(),
        HWND_TOPMOST,
        geometry().top(),
        geometry().left(),
        geometry().width(),
        geometry().height(),
        SWP_SHOWWINDOW
    );
    event->accept();
}

void AreaSelectorDialog::mouseReleaseEvent(QMouseEvent *event)
{
    if(!fullscreenMode) return;
    dragStarted = false;
    event->accept();
    QPoint p = startWndCoords - prevMouseCoords;

    //selectedRect.setTopLeft(startWndCoords);
    //selectedRect.setBottomRight(prevMouseCoords);
    selectedRect = QRect();
    // 1 case
     if( (startWndCoords.x() - prevMouseCoords.x()) < 0 )
         if( (prevMouseCoords.y() - startWndCoords.y()) > 0 )
         {
             selectedRect.setTopLeft(startWndCoords);
             selectedRect.setBottomRight(prevMouseCoords);
         }

     // 2 case
     if( (startWndCoords.x() - prevMouseCoords.x()) < 0 )
         if( (prevMouseCoords.y() - startWndCoords.y()) < 0 )
         {
             selectedRect.setBottomLeft(startWndCoords);
             selectedRect.setTopRight(prevMouseCoords);
         }

     // 3 case
     if( (startWndCoords.x() - prevMouseCoords.x()) > 0 )
         if( (startWndCoords.y() - prevMouseCoords.y()) < 0 )
         {
             selectedRect.setTopRight(startWndCoords);
             selectedRect.setBottomLeft(prevMouseCoords);
         }

     // 4 case
     if( (startWndCoords.x() - prevMouseCoords.x()) < 0 )
         if( (startWndCoords.y() - prevMouseCoords.y()) > 0 )
         {
             selectedRect.setBottomLeft(startWndCoords);
             selectedRect.setTopRight(prevMouseCoords);
         }

    QPointF p1 = geometry().topLeft();
    emit sigSetRect(selectedRect, p1);
    emit sigSetImageRect(selectedRect, rect_image);
    if(fullscreenMode) close();
}

void AreaSelectorDialog::mousePressEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton )
    {
        dragStarted = true;
        prevMouseCoords = QPoint(event->x(),event->y());
        startWndCoords = prevMouseCoords;
    }
}

void AreaSelectorDialog::mouseMoveEvent(QMouseEvent *event)
{
    event->accept();
    if(  dragStarted )
    {
        //QPoint delta = prevMouseCoords - event->pos();
        if(!fullscreenMode)
          move( QPoint(event->x(),event->y())  - QPoint(rect().width() / 2,rect().height() / 2));
    }
    prevMouseCoords = event->pos();
    repaint();
}

AreaSelectorDialog::~AreaSelectorDialog()
{
    delete ui;
}

void AreaSelectorDialog::resizeEvent(QResizeEvent* event)
{
    //repaint();
    event->accept();
}

void AreaSelectorDialog::timerEvent(QTimerEvent* event)
{
    event->accept();
    repaint();
}

void AreaSelectorDialog::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    selectedRect.setTopLeft(startWndCoords);
    selectedRect.setBottomRight(prevMouseCoords);

    painter.fillRect(rect(), QColor(200,200,200,255));

    if( fullscreenMode )
      painter.fillRect(selectedRect, QColor(100,255,100,255));
    else
    {
        QRectF center_rect = rect();
        QTransform trns;
        trns.scale(0.5,0.5);

        QPointF p[5];
        p[0] = rect().topLeft();
        p[1] = rect().bottomRight();
        p[0] = p[0] * trns + center_rect.center()/2;
        p[1] = p[1] * trns + center_rect.center()/2;
        p[2] = p[0] * trns + center_rect.center()/2;
        p[3] = p[1] * trns + center_rect.center()/2;

        //painter.drawRect()
        rectangles.clear();
        QPainterPath path(QPointF(0,0));
        center_rect = QRectF(p[0], p[1]);
        rectangles.append(center_rect);
        path.addRect(center_rect);
        center_rect = QRectF(p[2], p[3]);
        rectangles.append(center_rect);
        path.addRect(center_rect);
        rectangles.append(rect());
        path.addRect(rect());
        QPoint pos = prevMouseCoords;// QCursor::pos();
        //find witch rect is highlighted
        float minArea=12121211211;
        QRectF highlighted_rect;
        for(auto r : rectangles)
        {
            if (r.contains(pos))
            {
                if( (r.width()*r.height()) < minArea)
                {
                    minArea = r.width()*r.height();
                    highlighted_rect = r;
                }
            }
        }

        //path.translate()
        QPen pen;
        pen.setWidth(5);
        pen.setStyle(Qt::PenStyle::DashDotDotLine);
        painter.setPen(pen);
        painter.drawLine(center_rect.center().x(), p[0].y(),
                         center_rect.center().x(), p[1].y());
        painter.drawLine(p[0].x(),center_rect.center().y(),
                         p[1].x(),center_rect.center().y());
        painter.drawPath(path);
        painter.fillPath(path, Qt::red);

        painter.fillRect(highlighted_rect, Qt::green);

    }

    painter.end();

    //QPainter painter2(this);
    //painter2.drawImage(rect(), rect_image);

    event->accept();

}

void AreaSelectorDialog::on_doneButton_clicked()
{
   selectedRect = geometry();
   QPointF p = geometry().topLeft();
   emit sigSetAreaRect(selectedRect, p);
   QMap<QString, QString> attrs;
   QString v = QString("QRect(%1,%2,%3,%4)").arg(selectedRect.left())
                                            .arg(selectedRect.top())
                                            .arg(selectedRect.width())
                                            .arg(selectedRect.height());
   attrs["area"] = v;
   attrs["filename"] = filename;
   emit sigSetAreaRect(attrs);
   close();

}

