#ifndef GLOBALS_H
#define GLOBALS_H

#include <QVariant>


class Globals
{
public:
    static QMap<QString, std::vector<QString>> global_lists;
    static QMap<QString, QVariant> global_vars;

    Globals();
    QVariant get_var(QString varname);
    bool set_var(QString varname, QVariant val);
    bool contains(QString varname);
    static Globals* getInstance();
    static Globals* instance;
};

#endif // GLOBALS_H
