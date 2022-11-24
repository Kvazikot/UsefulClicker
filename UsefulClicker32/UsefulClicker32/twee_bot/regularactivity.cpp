#include <QDebug>
#include <windows.h>
#include "regularactivity.h"
#include "twee_bot/twitteractivity.h"
//#include "twee_bot/searchwindow.h"
//doc.appendChild(root);

void print(QString s);




RegularActivity::RegularActivity()
{
}


TestTwitterActivity::TestTwitterActivity()
{
    TwitterActivity twitter_activity;
    twitter_activity.run();
}

void GoToSite::run()
{

}

void TestTwitterActivity::run()
{

}


void RegularActivity::addActivity(Activity* activity)
{
    print("add activity" + activity->toStr());
    activities.push_back(activity);
}
