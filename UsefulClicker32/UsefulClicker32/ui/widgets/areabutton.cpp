#include <QTreeView>
#include <QPainter>
#include "model/simpledelegate.h"
#include "ui/widgets/areabutton.h"

//---------------------------------------------------------------------------------

AreaButton::AreaButton(QWidget *parent)
    : KeyboardButton(parent)
{
    setContextMenuPolicy(Qt::PreventContextMenu);
    setIcon(":/images/area_icon.png", true, true);
    repaint();
}

void AreaButton::areaSelected(QRect rect, QImage& rect_image)
{
    QPainter painter(&rect_image);
    painter.drawImage(geometry(), rect_image);
    QMap<QString,QString> attrs;
    QString v = QString("QRect(%1,%2,%3,%4)").arg(rect.left())
                                             .arg(rect.top())
                                             .arg(rect.width())
                                             .arg(rect.height());
    attrs["areaRect"] = v;
    emit click(v);
    //emit sendAttrs(attrs);


}

void AreaButton::mousePressEvent(QMouseEvent *ev)
{
    auto classname = QString(this->parent()->parent()->metaObject()->className());
    if ( ev->button() == Qt::MouseButton::RightButton )
    {
        if( classname == "CoolTestsForm")
            createDialog(this->parent(), DialogType::AREA_SELECTOR);
        else
        {
            QTreeView*  view = (QTreeView*)this->parent()->parent()->parent();
            SimpleDelegate* delegate = new SimpleDelegate(view, view->itemDelegate(), DialogType::AREA_SELECTOR);
            view->setItemDelegate(delegate);
            connect(delegate, SIGNAL(activated(const QModelIndex&)), view, SLOT(update(const QModelIndex&)) );
        }
    }

    if ( ev->button() == Qt::MouseButton::LeftButton )
    {
        if( classname == "CoolTestsForm")
            createDialog(this->parent(), DialogType::SCREEN_BUTTONS_DETECTOR);
        else
        {
            QTreeView*  view = (QTreeView*)this->parent()->parent()->parent();
            SimpleDelegate* delegate = new SimpleDelegate(view, view->itemDelegate(), DialogType::SCREEN_BUTTONS_DETECTOR);
            view->setItemDelegate(delegate);
            connect(delegate, SIGNAL(activated(const QModelIndex&)), view, SLOT(update(const QModelIndex&)) );
        }
    }

    emit clicked();
}
