#include <QTreeView>
#include <QDir>
#include "model/simpledelegate.h"
#include "ui/widgets/shellbutton.h"
#include "ui/dialogtype.h"

//---------------------------------------------------------------------------------

ShellButton::ShellButton(QWidget *parent)
    : QLabel(parent)
{
    setContextMenuPolicy(Qt::PreventContextMenu);
    setScaledContents(true);
    setGeometry(0,0,50,20);
    QImage image(":/images/Terminal-icon.png");
    image = image.scaled(50,50);
    setPixmap(QPixmap::fromImage(image));
    repaint();
}


void ShellButton::mousePressEvent(QMouseEvent *ev)
{
    if ( ev->button() == Qt::MouseButton::RightButton )
    {
    }

    if ( ev->button() == Qt::MouseButton::LeftButton )
    {
        auto classname = QString(this->parent()->parent()->metaObject()->className());
        //if(this->parent()->parent() != 0)

        if( classname == "CoolTestsForm")
            createDialog(this->parent(), DialogType::SHELL_COMMAND_DIALOG);
        else
        {
            QTreeView*  view = (QTreeView*)this->parent()->parent()->parent();
            SimpleDelegate* delegate = new SimpleDelegate(view, view->itemDelegate(), DialogType::SHELL_COMMAND_DIALOG);
            view->setItemDelegate(delegate);
        }
        //connect(delegate, SIGNAL(activated(const QModelIndex&)), view, SLOT(update(const QModelIndex&)) );
    }
    emit clicked();
    ev->accept();
}
