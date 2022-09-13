#ifndef MOUSEBUTTON_H
#define MOUSEBUTTON_H

#include <QWidget>
#include "ui/widgets/keyboardbutton.h"


class MouseButton : public KeyboardButton
{
    Q_OBJECT
public:
    Qt::MouseButton button;
    explicit MouseButton(QWidget *parent = nullptr);
    virtual void wheelEvent(QWheelEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *ev) override;
signals:
    void click(QString button);
    void clicked();
};


#endif // MOUSEBUTTON_H
