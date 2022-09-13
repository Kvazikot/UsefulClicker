#include <QImage>
#include <QPainter>
#include <QWheelEvent>
#include <QCoreApplication>
#include <QLabel>
#include <QTimer>
#include <QTreeView>
#include <QHBoxLayout>
#include "autocompleteeditor.h"
#include "model/simpledelegate.h"
#include "areaselectordialog.h"
#include "ui/widgets/comboedit.h"


//---------------------------------------------------------------------------------------------------------

AutocompleteEditor::AutocompleteEditor(QWidget *parent) :
    QComboBox(parent)
{
    setEditable(true);
    ComboEdit* edit = new ComboEdit(this);
    //edit->setEditable(true);
    setLineEdit(edit);
    connect(edit, SIGNAL(sigSetSequence(QString)), this, SLOT(updateSequence(QString)));
    setContextMenuPolicy(Qt::PreventContextMenu);

    setItemIcon(0, QIcon(":/images/keyboard_red.png"));
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

void AutocompleteEditor::updateSequence(QString sequence)
{
    setItemText(0, sequence);
}


void AutocompleteEditor::keyPressEvent(QKeyEvent* event)
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
        //this->clear();
        insertItems(0, filtered_list);
        setItemIcon(0, QIcon(":/images/keyboard_red.png"));
        showPopup();
    }
    event->accept();
    QComboBox::keyPressEvent(event);
}

AutocompleteEditor::~AutocompleteEditor()
{
}

void AutocompleteEditor::setValue(QString value)
{
    ComboEdit* edit  = (ComboEdit*)lineEdit();
    setItemText(0, value);
    edit->setText(value);

    // set buttons state
    if( value.contains("Scroll") )
        edit ->setMouseState(3);
    if( value.contains("Left") )
        edit ->setMouseState(0);
    if( value.contains("Right") )
        edit ->setMouseState(1);

}

/*
void AutocompleteEditor::paintEvent(QPaintEvent* event)
{
    QRect r = event->rect();
    r.setRect(0,0,10,10);
    QPaintEvent pevent(r);

    QComboBox::paintEvent(&pevent);
}
*/
