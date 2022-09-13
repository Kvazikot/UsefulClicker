#include <QTreeView>
#include <QDir>
#include "ui/widgets/crossbutton.h"
#include "model/simpledelegate.h"

//---------------------------------------------------------------------------------

CrossButton::CrossButton(QWidget *parent)
    : QLabel(parent)
{
    setContextMenuPolicy(Qt::PreventContextMenu);
    setScaledContents(true);
    setGeometry(0,0,50,20);
    QImage image(":/images/templ_cross_org.png");
    image = image.scaled(50,50);
    setPixmap(QPixmap::fromImage(image));
    repaint();
}


void CrossButton::mousePressEvent(QMouseEvent *ev)
{
    auto classname = QString(this->parent()->parent()->metaObject()->className());
    if ( ev->button() == Qt::MouseButton::RightButton )
    {
    }

    if ( ev->button() == Qt::MouseButton::LeftButton )
    {
        if( classname == "CoolTestsForm")
            createDialog(this->parent(), DialogType::SHELL_COMMAND_DIALOG);
        else
        {
            QTreeView*  view = (QTreeView*)this->parent()->parent()->parent();
            SimpleDelegate* delegate = new SimpleDelegate(view, view->itemDelegate(), DialogType::COORDINATES_SELECTOR);
            view->setItemDelegate(delegate);
            connect(delegate, SIGNAL(activated(const QModelIndex&)), view, SLOT(update(const QModelIndex&)) );
        }
    }

    ev->accept();
}
