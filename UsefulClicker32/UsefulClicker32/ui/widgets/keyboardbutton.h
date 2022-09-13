#ifndef KEYBOARDBUTTON_H
#define KEYBOARDBUTTON_H

#include <QWidget>
#include <QLabel>


class KeyboardButton : public QLabel
{
    Q_OBJECT
public:
    QImage icon_enabled, icon_disabled;
    explicit KeyboardButton(QWidget *parent = nullptr);
    virtual void mousePressEvent(QMouseEvent *ev) override;
    void timerEvent(QTimerEvent* event) override;
    void setDisable();
    bool mouseOverFlag;
    bool state;
    void setIcon(QString filename, bool invert_pixels=true, bool init_state=false);
    virtual void paintEvent(QPaintEvent *) override;
signals:
    void clicked();
    //void sendAttrs(QMap<QString,QString> attrs);
    void accept();
    void updateSequence();

};

#endif // KEYBOARDBUTTON_H
