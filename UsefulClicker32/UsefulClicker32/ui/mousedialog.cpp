#include <windows.h>

#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include "cv/dspmodule.h"
#include "ui/areaselectordialog.h"
#include "mousedialog.h"
#include "interpreter/interpreter.h"
#include "ui_mousedialog.h"

MouseDialog::MouseDialog(QWidget *parent) :
    QDialog(parent), screenNum(0),
    ui(new Ui::MouseDialog)
{
    setWindowFlags(Qt::Widget );
    setAttribute(Qt::WA_AlwaysStackOnTop, true);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_WState_WindowOpacitySet);
    setAttribute(Qt::WA_PaintOnScreen); // not needed in Qt 5.2 and up
    setCursor(Qt::CrossCursor);
    userWindow = GetFocus();
    ui->setupUi(this);
    ui->delayWidget->hide();
    withDelayFlag = false;
    wheel_repeats = 0;

    QImage bg_image(300,300,QImage::Format_ARGB32);
    bg_image.fill(QColor(100,100,100,0));

    dsp = new DspModule();

    startTimer(10);
}

void MouseDialog::slotAreaSelected(QRect area, QPointF p)
{
    QMap<QString, QString> attrs;
    attrs["event"] = "area";
    attrs["button"] = "left";
    attrs["area"] = QString("QRect(%1,%2,%3,%4)").
                    arg(area.left()).
                    arg(area.top()).
                    arg(area.right()).
                    arg(area.bottom());
    emit sigSetAttrs(attrs);
    close();
}

void MouseDialog::showOnlyMouse()
{
    hideLabels();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->tipLabel->show();
}

void MouseDialog::showOnlyKeyboard()
{
    hideLabels();
    ui->keySequenceLabel->show();
    ui->label_8->show();
    ui->tipLabel->show();
}

void MouseDialog::hideLabels()
{
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_8->hide();
    ui->tipLabel->hide();
    ui->keySequenceLabel->hide();
}

void MouseDialog::keyPressEvent(QKeyEvent* event)
{
    event->accept();

    //show delay widget if F2
    if( event->key() == Qt::Key_F2)
    {
        withDelayFlag = true;
        ui->delayWidget->setHidden(!ui->delayWidget->isHidden());
        if( ui->delayWidget->isHidden() )
            ui->tipLabel->setText( "Press F2 again to accept delay values");
        else
            ui->tipLabel->setText( "Press F2 to set delays");
        return;
    }

    //if( event->key() == Qt::Key_Delete)  clear();
    if( event->key() == Qt::Key_F3)
    {
        AreaSelectorDialog* dlg = new AreaSelectorDialog(this);
        setWindowOpacity(0);
        dlg->setWindowOpacity(0.6);
        dlg->fullScreen();
        auto str = "";
        ui->tipLabel->setText(str);
        hideLabels();

        connect(dlg, SIGNAL(sigSetRect(QRect, QPointF)), this, SLOT(slotAreaSelected(QRect, QPointF)));
    }


    Qt::KeyboardModifiers m = event->modifiers();
    sequence = "";
    if( m.testFlag(Qt::ControlModifier) )
        sequence="ctrl+";
    if( m.testFlag(Qt::ControlModifier) && m.testFlag(Qt::ShiftModifier))
    {
       sequence="ctrl+shift+";
    }
    sequence+=QKeySequence(event->key()).toString();
    //setStyleSheet("");
    QString html = QString("<html><head/><body><p><span style=\" font-size:24pt; font-weight:700; color:#00007f;\">%1</span></p></body></html>")
                   .arg(sequence);
    ui->keySequenceLabel->setText(html);
}

void MouseDialog::keyReleaseEvent(QKeyEvent *event)
{
    QMap<QString, QString> attrs;
    if( event->key() == Qt::Key_F2)
    {
        if( ui->delayWidget->isHidden() )
        {
            attrs["delay_fixed"] = QString::number(ui->delayWidget->delay_fixed);
            attrs["delay_random"] = QString::number(ui->delayWidget->delay_random);
            attrs["repeats"] = QString::number(ui->delayWidget->repeats);
            QString str = "Press F2 to set delays. <br/> delay_fixed = " + attrs["delay_fixed"] + "<br/>";
            str+= "delay_random = " + attrs["delay_random"] + "<br/>";
            str+= "repeats = " + attrs["repeats"];
            QString html = QString("<html><head/><body><p><span style=\" font-size:18pt; font-weight:700; color:#00007f;\">%1</span></p></body></html>")
                           .arg(str);
            ui->tipLabel->setText(html);
        }
        else
        {
            QString str = "Press F2 to set delays.";
            QString html = QString("<html><head/><body><p><span style=\" font-size:18pt; font-weight:700; color:#00007f;\">%1</span></p></body></html>")
                           .arg(str);
            ui->tipLabel->setText(html);
        }
        return;
    }

    attrs["event"] = "hotkey";
    attrs["hotkey"] = sequence;
    attrs["withDelayFlag"] = QString::number(withDelayFlag);
    emit sigSetAttrs(attrs);
    close();
}


void MouseDialog::mousePressEvent(QMouseEvent* event)
{
    //process selected rectangle
    QMap<QString, QString> attrs;
    attrs["event"] = "click";
    attrs["withDelayFlag"] = QString::number(withDelayFlag);
    mpos = event->pos();

    attrs["x"] = QString::number(mpos.x());
    attrs["y"] = QString::number(mpos.y());
    attrs["delay_fixed"] = QString::number(ui->delayWidget->delay_fixed);
    attrs["delay_random"] = QString::number(ui->delayWidget->delay_random);
    attrs["repeats"] = QString::number(ui->delayWidget->repeats);
    button = event->button();
    if( button == Qt::MouseButton::LeftButton )
        attrs["button"] = "left";
    if( button == Qt::MouseButton::RightButton )
        attrs["button"] = "right";
    if( button == Qt::MouseButton::MiddleButton )
        attrs["button"] = "middle";
    emit sigSetAttrs(attrs);
    //hide();
    //MouseClick(mpos, button);
   // SetFocus(userWindow);
    //QTimer::singleShot(100, this, SLOT(afterclick()));
    //QTimer::singleShot(1000, this, SLOT(show()));

    close();

    event->accept();
}

void MouseDialog::afterclick()
{
    userWindow = GetFocus();
    //MouseClick(mpos, button);
}

void MouseDialog::mouseMoveEvent(QMouseEvent* event)
{
    mpos = event->globalPosition().toPoint();
    repaint();
    event->accept();
}

void MouseDialog::wheelEvent(QWheelEvent* event)
{
    QMap<QString, QString> attrs;
    auto s = QString("%1").arg(event->angleDelta().y());
    attrs["event"] = "scroll";
    attrs["wheel_repeats"] = QString::number(wheel_repeats);
    attrs["delta"] = s;
    attrs["delay_fixed"] = QString::number(ui->delayWidget->delay_fixed);
    attrs["delay_random"] = QString::number(ui->delayWidget->delay_random);
    attrs["repeats"] = QString::number(ui->delayWidget->repeats);
    attrs["withDelayFlag"] = QString::number(withDelayFlag);
    emit sigSetAttrs(attrs);
    event->accept();
    wheel_repeats++;
    lastWheelEvent.restart();

    //close();
}



void MouseDialog::timerEvent(QTimerEvent* event)
{
    if( wheel_repeats > 0 && lastWheelEvent.elapsed() > 1000 )
        close();
    repaint();
    event->accept();
}


void MouseDialog::showEvent(QShowEvent* event)
{
    //dsp->detectButtons(screenNum, dsp->kernel_size, rects);
    showFullScreen();
    event->accept();
}


MouseDialog::~MouseDialog()
{
    delete ui;
}
