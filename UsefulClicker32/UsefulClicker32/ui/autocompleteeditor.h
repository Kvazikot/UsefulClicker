#ifndef AUTOCOMPLETEEDITOR_H
#define AUTOCOMPLETEEDITOR_H

#include <QWidget>
#include <QMouseEvent>
#include <QComboBox>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QKeyEvent>


class AutocompleteEditor : public QComboBox
{
    Q_OBJECT
public:
    QVector<QString> completion_list;

    explicit AutocompleteEditor(QWidget *parent = nullptr);
    void setValue(QString value);
    void keyPressEvent(QKeyEvent* event);

    //void paintEvent(QPaintEvent* event);
    ~AutocompleteEditor();
public slots:
    void updateSequence(QString sequence);

};

#endif // AUTOCOMPLETEEDITOR_H
