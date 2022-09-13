#include <QKeyEvent>
#include <QCoreApplication>
#include <QTimer>
#include "keyboardbutton.h"

//---------------------------------------------------------------------------------

KeyboardButton::KeyboardButton(QWidget *parent)
    : QLabel(parent)
{
    mouseOverFlag = false;
    state = false;
    setScaledContents(true);
    setGeometry(width()-10,0,50,20);
    startTimer(101);
}

void KeyboardButton::setIcon(QString filename, bool invert_pixels, bool init_state)
{
    icon_enabled = QImage(filename);
    icon_enabled = icon_enabled.scaled(50,height());
    icon_disabled = icon_enabled;
    if(invert_pixels)
        icon_disabled.invertPixels();
    if(init_state)
        setPixmap(QPixmap::fromImage(icon_enabled));
    else
        setPixmap(QPixmap::fromImage(icon_disabled));
}

void KeyboardButton::mousePressEvent(QMouseEvent *ev)
{
    state = !state;
    mouseOverFlag = true;
    if( state )
        emit clicked();
    else
    {
        //emit accept();
        QKeyEvent keyEvent(QEvent::KeyPress, Qt::Key_Return, Qt::NoModifier);
        QCoreApplication::sendEvent(this, &keyEvent);

    }
    emit clicked();
    ev->accept();
}

void KeyboardButton::timerEvent(QTimerEvent* event)
{
    event->accept();
    if( mouseOverFlag )
        setPixmap(QPixmap::fromImage(icon_enabled));

}

void KeyboardButton::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
}

void KeyboardButton::setDisable()
{
    setPixmap(QPixmap::fromImage(icon_disabled));
    mouseOverFlag = false;
}
