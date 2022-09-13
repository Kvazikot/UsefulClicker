#include <QPainter>
#include "autocompletecombo.h"

AutocompleteCombo::AutocompleteCombo(QWidget *parent) :
    QComboBox(parent)
{
    setEditable(true);
    completion_list = {"Right click",
                       "Left click",
                       "Esc",
                       "Hot key",
                       "Scroll up",
                       "Scroll down",
                       "Launch program",
                       "Image search",
                       "Type text",
                       "ctrl + A",
                       "ctrl + C",
                       "ctrl + V",
                      };

}

void AutocompleteCombo::keyPressEvent(QKeyEvent* event)
{
    QVector<QString> filtered_list;

    if( event->key() == Qt::Key_Backspace)  clear();
    if( event->key() == Qt::Key_Delete)  clear();

    QString text = this->currentText();
    for (QString item : completion_list) {
        if(item.contains(text) && text.size() > 2)
            filtered_list.push_back(item);
    }
    if( filtered_list.size() > 0 )
    {
        this->clear();
        insertItems(0, filtered_list);
        showPopup();
    }
    event->accept();
    QComboBox::keyPressEvent(event);
}

AutocompleteCombo::~AutocompleteCombo()
{
}

void AutocompleteCombo::paintEvent(QPaintEvent* event)
{
    QComboBox::paintEvent(event);
    QPainter painter(this);
    QRect rect = this->rect();
    rect.setLeft(rect.right()-100);
    rect.moveLeft(200);
    rect.setRect(0,0,50,height()-20);
    QImage keyboard_icon(":/play.jpg");
    keyboard_icon = keyboard_icon.scaled(100,100);
    painter.drawPixmap(rect, QPixmap::fromImage(keyboard_icon));


}
