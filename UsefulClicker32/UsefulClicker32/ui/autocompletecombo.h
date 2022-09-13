#ifndef AUTPOCOMPLETECOMBO_H
#define AUTPOCOMPLETECOMBO_H

#include <QVector>
#include <QDialog>
#include <QWidget>
#include <QComboBox>
#include <QKeyEvent>
#include <QPaintEvent>

class AutocompleteCombo : public QComboBox
{
    Q_OBJECT
public:
    QVector<QString> completion_list;
    explicit AutocompleteCombo(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent* event);
    void paintEvent(QPaintEvent* event);
    ~AutocompleteCombo();
};


#endif // AUTPOCOMPLETECOMBO_H
