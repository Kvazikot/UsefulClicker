#include <QDebug>
#include <windows.h>
#include "regularactivity.h"

//doc.appendChild(root);

void print(QString s);

RegularActivity::RegularActivity()
{
}


TestTwitterActivity::TestTwitterActivity()
{
    addActivity(new GoToSite("https://twitter.com/"));
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

static void setWindowFocus(std::string programname)
{
    //qDebug << "Setting focus to window." << std::endl;
    HWND hWnd = FindWindowA(NULL, programname.c_str());
    if (hWnd != NULL) {
        // Set application to the foreground
        SetForegroundWindow(hWnd);
    }
}

