#include <QString>
#include "globals.h"

QMap<QString, std::vector<QString>> Globals::global_lists;
QMap<QString, QVariant> Globals::global_vars;

Globals* Globals::instance;

Globals::Globals()
{

}

bool Globals::set_var(QString name, QVariant val)
{
    global_vars[name] = val;
    return true;
}

bool Globals::contains(QString varname)
{
    return global_vars.contains(varname);
}

QVariant Globals::get_var(QString varname)
{
    if(global_vars.find(varname)!=global_vars.end())
    {
        return global_vars[varname];
    }
    return QVariant();
}
