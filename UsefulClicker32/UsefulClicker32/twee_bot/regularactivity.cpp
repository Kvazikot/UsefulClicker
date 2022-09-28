#include <QDebug>
#include <windows.h>
#include "regularactivity.h"
#include "twee_bot/searchwindow.h"
//doc.appendChild(root);

void print(QString s);




RegularActivity::RegularActivity()
{
}


TestTwitterActivity::TestTwitterActivity()
{
    addActivity(new GoToSite("https://twitter.com/"));
    //setWindowFocus(L"Chrome");
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
    SearchWindow search;
    search.setWindowFocus("Chrome");
}
