#ifndef REGULARACTIVITY_H
#define REGULARACTIVITY_H

#include <QString>
#include <vector>

enum ActivityType
{
    GO_TO_SITE

};

class Activity
{
public:
    ActivityType type;
    virtual void run(){};
    virtual QString toStr(){return "Activity ";}
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
        out+="GoToSite " + URL;
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
