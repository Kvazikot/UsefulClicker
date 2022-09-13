#include "ui/dialogtype.h"

#include "ui/areaselectordialog.h"
#include "ui/screenbuttonsdetector.h"
#include "ui/coordselector.h"
#include "ui/shelldialog.h"
#include "ui/widgets/keyboardbutton.h"
#include "ui/typedialog.h"
#include "ui/mousedialog.h"
#include "ui/widgets/delaywidget.h"

void createDialog(QObject* receiver_object, DialogType dialog_type, QString args)
{
    switch( dialog_type )
    {
         case AREA_SELECTOR:
         {
             AreaSelectorDialog* dlg = new AreaSelectorDialog((QWidget*)receiver_object);
             receiver_object->connect(dlg, SIGNAL(sigSetAreaRect(QMap<QString,QString>)), receiver_object, SLOT(slotSetAttrs(QMap<QString,QString>)));
             dlg->show();
         } break;
         case SCREEN_BUTTONS_DETECTOR:
         {
            ScreenButtonsDetector* dlg2 = new ScreenButtonsDetector((QWidget*)receiver_object);
            receiver_object->connect(dlg2, SIGNAL(sigSetAttrs(QMap<QString,QString>)), receiver_object, SLOT(slotSetAttrs(QMap<QString,QString>)));
            dlg2->show();
         } break;
         case COORDINATES_SELECTOR:
         {
             CoordSelector* dlg2 = new CoordSelector((QWidget*)receiver_object);
             receiver_object->connect(dlg2, SIGNAL(sigSetAttrs(QMap<QString,QString>)), receiver_object, SLOT(slotSetAttrs(QMap<QString,QString>)));
             dlg2->show();
         } break;
         case SHELL_COMMAND_DIALOG:
         {
             ShellDialog* dlg3 = new ShellDialog((QWidget*)receiver_object);
             receiver_object->connect(dlg3, SIGNAL(sigSetAttrs(QMap<QString,QString>)), receiver_object, SLOT(slotSetAttrs(QMap<QString,QString>)));
             dlg3->show();

         } break;
        case DELAY_WIDGET:
        {
            DelayWidget* delay_widget = new DelayWidget();
            receiver_object->connect(delay_widget, SIGNAL(sigSetAttrs(QMap<QString,QString>)), receiver_object, SLOT(slotSetAttrs(QMap<QString,QString>)));
            delay_widget->showFullScreen();
        } break;
        case TYPE_DIALOG:
        {
            TypeDialog* dlg = new TypeDialog();
            receiver_object->connect(dlg, SIGNAL(sigSetAttrs(QMap<QString,QString>)), receiver_object, SLOT(slotSetAttrs(QMap<QString,QString>)));
            dlg->show();
        } break;
        case KEYDOWN_DIALOG:
        {
            TypeDialog* dlg = new TypeDialog("keydown");
            receiver_object->connect(dlg, SIGNAL(sigSetAttrs(QMap<QString,QString>)), receiver_object, SLOT(slotSetAttrs(QMap<QString,QString>)));
            dlg->show();
        }break;
        case MOUSE_DIALOG:
        {
            MouseDialog* dlg = new MouseDialog();
            if( args == "hotkey")
                dlg->showOnlyKeyboard();
            if( args == "click")
                dlg->showOnlyMouse();
            receiver_object->connect(dlg, SIGNAL(sigSetAttrs(QMap<QString,QString>)), receiver_object, SLOT(slotSetAttrs(QMap<QString,QString>)));
            dlg->show();
        }break;

    }

}
