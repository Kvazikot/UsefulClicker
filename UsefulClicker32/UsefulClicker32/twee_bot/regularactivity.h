#ifndef REGULARACTIVITY_H
#define REGULARACTIVITY_H

#include <QString>
#include <QDateTime>
#include <vector>

enum ActivityType
{
    GO_TO_SITE

};

class Activity
{
public:
    ActivityType type;
    QDateTime startTime;
    QDateTime endTime;
    Activity()
    {
        startTime = QDateTime::currentDateTime();
        endTime = startTime.addSecs(30);
    }
    virtual void run(){};
    virtual QString toStr()
    {
        QString s;
        s+=" startTime = " + startTime.toString() + " ";
        s+=" endTime = " + endTime.toString() + " ";
        return s;
    }
};

class GoToSite: public Activity
{
 public:
    QString URL;
    GoToSite(QString url) { URL = url; }
    virtual void run();
    QString toStr()
    {
        QString out;
        out+=Activity::toStr()  + "\n";
        out+="GoToSite " + URL + "\n";
        return out;
    }

};

// Регулярная активность (RA)
// * поиск твитов по ключевым словам
// * просмотр комментов на конкретный таргетированный твит
// * копирование текста коммента и твита в окно твитов
class RegularActivity : public Activity
{
public:
    std::vector<Activity*> activities;
    int n_step;
    RegularActivity();
    void addActivity(Activity* activity);
};

class TestTwitterActivity : public RegularActivity
{
public:
    TestTwitterActivity();
    void run();

};

#endif // REGULARACTIVITY_H
