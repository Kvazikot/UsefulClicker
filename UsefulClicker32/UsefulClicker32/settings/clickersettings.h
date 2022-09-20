#ifndef CLICKERSETTINGS_H
#define CLICKERSETTINGS_H

#include <QSettings>
#include <QMessageBox>

#define show_message(title,msg) { QMessageBox msgBox; msgBox.setWindowTitle(title); msgBox.setText(msg); msgBox.exec(); }
// -------------------------------------------------------------------------------

#define _F(f) ClickerSettings::getInstance()->readFlag(f)
#define _(f) ClickerSettings::getInstance()->readFlag(f)
#define DEFAULT(f) ClickerSettings::getInstance()->readDefault(f)
#define SAVE_DEFAULT(key,val) ClickerSettings::getInstance()->writeDefault(key,val)
#define ATTR(a) node.toElement().attribute(a, DEFAULT(a).toString())

class ClickerSettings
{
public:
    static ClickerSettings instance;
    QSettings* settings;
    QString strKey;
    ClickerSettings();
    static ClickerSettings* getInstance(){return &instance;}
    void reload();
    bool readFlag(QString name);
    QVariant readDefault(QString name);
    void writeDefault(QString key, QVariant value);
};

#endif // CLICKERSETTINGS_H
