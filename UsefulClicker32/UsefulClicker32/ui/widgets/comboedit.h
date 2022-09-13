#ifndef COMBOEDIT_H
#define COMBOEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>

class ComboEdit : public QLineEdit
{
    Q_OBJECT
public:
    QString sequence;
    QHBoxLayout* hbox;
    int hbox_width;

    explicit ComboEdit(QWidget *parent = nullptr);
    ~ComboEdit();
    void resizeEvent(QResizeEvent* event) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void showEvent(QShowEvent* ev) override;
    void keyPressEvent(QKeyEvent* event) override;
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void setMouseState(int button);
    void dimIcons(QWidget* except_label);

signals:
    void sigSetSequence(QString sequence);

public slots:
    void slotCrossClick();
    void slotKeyboardClick();
    void slotSetSequence(QString sequence);
    void slotButtonClicked();

//    void paintEvent(QPaintEvent *) override;

};


#endif // COMBOEDIT_H
