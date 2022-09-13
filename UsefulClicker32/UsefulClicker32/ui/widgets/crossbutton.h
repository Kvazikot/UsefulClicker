#ifndef CROSSBUTTON_H
#define CROSSBUTTON_H

#include <QWidget>
#include <QMouseEvent>
#include <QMouseEvent>
#include "ui/widgets/keyboardbutton.h"

class CrossButton : public QLabel
{
    Q_OBJECT
public:
    explicit CrossButton(QWidget *parent = nullptr);
    virtual void mousePressEvent(QMouseEvent *ev) override;
signals:
    void click(QString button);
};


#endif // CROSSBUTTON_H
