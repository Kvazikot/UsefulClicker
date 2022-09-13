#ifndef DIALOGTYPE_H
#define DIALOGTYPE_H

#include <QObject>
#include <QMap>

enum DialogType
{
    AREA_SELECTOR=0,
    SCREEN_BUTTONS_DETECTOR=1,
    COORDINATES_SELECTOR=2,
    SHELL_COMMAND_DIALOG=3,
    TYPE_DIALOG=4,
    DELAY_WIDGET=5,
    KEYDOWN_DIALOG=6,
    MOUSE_DIALOG=7
};

static QMap<QString, DialogType> action_map{{"Add image click", SCREEN_BUTTONS_DETECTOR},
                                            {"Add left click", COORDINATES_SELECTOR},
                                            {"Area click", AREA_SELECTOR},
                                     {"Add right click", COORDINATES_SELECTOR},
                                     {"Add scroll down", COORDINATES_SELECTOR},
                                     {"Add Shell", SHELL_COMMAND_DIALOG},
                                     {"Add type", TYPE_DIALOG},
                                     {"Add keydown", KEYDOWN_DIALOG},
                                     {"Set delay for this", DELAY_WIDGET},
                                    };

void createDialog(QObject* receiver_object, DialogType dialog_type, QString args="");

#endif // DIALOGTYPE_H
