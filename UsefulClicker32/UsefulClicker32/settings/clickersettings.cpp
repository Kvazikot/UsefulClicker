#include <QDir>
#include "clickersettings.h"

ClickerSettings ClickerSettings::instance;


ClickerSettings::ClickerSettings()
{
    // load settings
    QString m_strWorkingPath(QDir::currentPath() + "/settings/UsefulClicker.ini");
    settings = 0;
    strKey = "common";
    settings = new QSettings( m_strWorkingPath, QSettings::IniFormat );
}

void ClickerSettings::reload()
{
    QString m_strWorkingPath(QDir::currentPath() + "/settings/UsefulClicker.ini");
    QSettings* new_settings = new QSettings( m_strWorkingPath, QSettings::IniFormat );
    QSettings* old_settings = settings;
    settings = new_settings;
    if(old_settings!=0)
        delete old_settings;
}

bool ClickerSettings::readFlag(QString name)
{
    return settings->value( strKey + "/" + name, "r").toBool();
}

QVariant ClickerSettings::readDefault(QString name)
{
    return settings->value( "defaults/" + name, "r");
}

void ClickerSettings::writeDefault(QString key, QVariant value)
{
    settings->setValue("defaults/" + key, value.toString());
}


