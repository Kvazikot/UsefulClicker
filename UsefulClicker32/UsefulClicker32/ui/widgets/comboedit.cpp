#include <QCoreApplication>

#include "ui/widgets/areabutton.h"
#include "ui/widgets/crossbutton.h"
#include "ui/widgets/keyboardbutton.h"
#include "ui/widgets/mousebutton.h"
#include "ui/widgets/comboedit.h"
#include "ui/widgets/shellbutton.h"

static KeyboardButton* keyboard_but;
static CrossButton* cross_but;
static MouseButton* mouse_but;
static AreaButton* area_but;
static ShellButton* shell_but;
static QVector<QImage> icons_cache;

void cache_icons(QLayout* layout)
{
    icons_cache.append(QImage(50,50,QImage::Format_ARGB32));
    for( int n = 0; n < layout->count(); n++)
        if( QString(layout->itemAt(n)->widget()->metaObject()->className()) != "ComboEdit")
        {
            auto label = (QLabel*)layout->itemAt(n)->widget();
            icons_cache.append((label->pixmap().toImage()));
        }
}

//---------------------------------------------------------------------------------------------------------

ComboEdit::ComboEdit(QWidget *parent) :
    QLineEdit(parent)
{

    keyboard_but = new KeyboardButton(0);
    keyboard_but->setIcon(":/images/keyboard_icon.png", true, false);
    setContextMenuPolicy(Qt::PreventContextMenu);
    connect(keyboard_but, SIGNAL(clicked()),this, SLOT(slotKeyboardClick()));
    connect(keyboard_but, SIGNAL(clicked()),this, SLOT(slotButtonClicked()));

    mouse_but = new MouseButton(0);
    mouse_but->setIcon(":/images/mouse_default.png", true, true);
    connect(mouse_but, SIGNAL(click(QString)), this, SLOT(slotSetSequence(QString)));
    connect(mouse_but, SIGNAL(clicked()),this, SLOT(slotButtonClicked()));

    cross_but = new CrossButton(0);
    connect(cross_but, SIGNAL(click(QString)), this, SLOT(slotSetSequence(QString)));
    connect(cross_but, SIGNAL(clicked()),this, SLOT(updateSequence()));

    area_but = new AreaButton(this);
    area_but->state = true;
    area_but->setIcon(":/images/area_icon.png", true, true);
    connect(area_but, SIGNAL(clicked()),this, SLOT(slotButtonClicked()));
    connect(QCoreApplication::instance(), SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(slotFocusChanged(QWidget*, QWidget*)));

    shell_but = new ShellButton(0);
    connect(shell_but, SIGNAL(click(QString)), this, SLOT(slotSetSequence(QString)));
    connect(shell_but, SIGNAL(clicked()),this, SLOT(slotButtonClicked()));

    hbox = new QHBoxLayout((QWidget*)this->parent());
    hbox->addWidget(this);
    hbox->addWidget(shell_but);
    hbox->addWidget(area_but);
    hbox->addWidget(cross_but);
    hbox->addWidget(keyboard_but);
    hbox->addWidget(mouse_but);
    cache_icons(hbox);

    hbox->setStretch(0, 100);

    QWidget* w = (QWidget*)this->parent();
    w->setLayout(hbox);

}

ComboEdit::~ComboEdit()
{

}

void ComboEdit::showEvent(QShowEvent* ev)
{
    ev->accept();
    qDebug() << __FUNCTION__ << text();
    if( text() == "shell" )
        dimIcons(shell_but);
    if( text() == "click" )
        dimIcons(mouse_but);
    if( text().contains("Scroll") )
        dimIcons(mouse_but);
    if( text().contains("hotkey") )
        dimIcons(keyboard_but);
}

void ComboEdit::slotCrossClick()
{
    clear();
    QKeyEvent keyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier);
    QCoreApplication::sendEvent(this, &keyEvent);
    //cross_but->setDisabled(cross_but->state);
}

void ComboEdit::dimIcons(QWidget* except_label)
{
    ((QLabel*)except_label)->setFrameShape(QLabel::Shape::Box);
    ((QLabel*)except_label)->setLineWidth(2);
    ((QLabel*)except_label)->setStyleSheet("color: rgb(255, 0, 0);");

    QHBoxLayout* layout = (QHBoxLayout*)((QWidget*)this->parent())->layout();
    for( int n = 0; n < layout->count(); n++)
    {
        if( QString(layout->itemAt(n)->widget()->metaObject()->className()) != "ComboEdit")
        {
            auto label = (QLabel*)layout->itemAt(n)->widget();
            QImage icon = icons_cache[n];
            if(label!=except_label)
            {
                label->setFrameShape(QLabel::Shape::NoFrame);
                for (int l = 0; l < icon.height(); ++l) {
                for (int k = 0; k < icon.width(); ++k) {
                    QColor c = icon.pixelColor(k,l);
                    c.setAlpha(c.alpha()/3);
                    icon.setPixelColor(k,l,c);
                }
                }
                label->setPixmap(QPixmap::fromImage(icon));
            }
            else
            {
                QImage icon = icons_cache[n];
                label->setPixmap(QPixmap::fromImage(icon));
                continue;
            }

        }
    }
}

void ComboEdit::slotButtonClicked()
{
    QLabel* label = static_cast<QLabel*>(QWidget::sender());
    //perform invert image test on every icon
    //dimIcons(label);
}

void ComboEdit::wheelEvent(QWheelEvent *event)
{

    if( event->angleDelta().y() > 0 )
        sequence = "Scroll up";
    else
        sequence = "Scroll down";
    setText(sequence);
    setStyleSheet("");
    QLineEdit::wheelEvent(event);
}

void ComboEdit::mousePressEvent(QMouseEvent *ev)
{
    QLineEdit::mousePressEvent(ev);
}

void ComboEdit::keyPressEvent(QKeyEvent* event)
{
    event->accept();
    if( event->key() == Qt::Key_Backspace)  clear();
    if( event->key() == Qt::Key_Delete)  clear();

    if (keyboard_but->state)
    {
        Qt::KeyboardModifiers m = event->modifiers();
        if(keyboard_but->mouseOverFlag)
        {
            sequence = "";
            if( m.testFlag(Qt::ControlModifier) )
               sequence="ctrl+";
            if( m.testFlag(Qt::ControlModifier) && m.testFlag(Qt::ShiftModifier))
               sequence="ctrl+shift+";
            sequence+=QKeySequence(event->key()).toString();
            setText(sequence);
        }
    }
    setStyleSheet("");
    QLineEdit::keyPressEvent(event);
}


void ComboEdit::slotKeyboardClick()
{
    setText("press the hot key sequence  ");
    setStyleSheet("color: rgb(188, 188, 188);");
}

void ComboEdit::slotSetSequence(QString sequence)
{
    setText(sequence);
    setStyleSheet("");

    emit sigSetSequence(sequence);
}


void ComboEdit::resizeEvent(QResizeEvent* event)
{
    event->accept();
}

void ComboEdit::mouseMoveEvent(QMouseEvent *ev)
{
    ev->accept();
    keyboard_but->setDisable();
}

void ComboEdit::setMouseState(int button)
{
    switch(button)
    {
        case 0: mouse_but->setIcon(":/images/mouse_left_click.png");
        break;
        case 1: mouse_but->setIcon(":/images/mouse_right_click.png");
        break;
        case 2: mouse_but->setIcon(":/images/mouse_scroll.png");
        break;
    }

}
