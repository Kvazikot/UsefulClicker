#include <QString>
#include "searchwindow.h"

void print(QString s);

std::vector<HWND> handles;

std::string programWindowTitle;

extern HWND chWnd;
HWND g_Processes = NULL;

BOOL CALLBACK FindProcessesChildWindowEnum(HWND hWnd, LPARAM lParam)
{
    char name[256];
    GetWindowTextA(hWnd,name,256);

    char ClassName[256];
    GetClassNameA(hWnd,ClassName,256);

   // print(QString(name));

    if((strcmp(ClassName,"")==0)&&(strstr(name,"Chrome")!=0))
        g_Processes = hWnd;

    if (name == NULL)
        return FALSE;
    return TRUE;
}


BOOL CALLBACK FindProcessesWindowEnum(HWND hWnd,LPARAM lParam)
{
    char name[256];
    GetWindowTextA(hWnd,name,256);

    char ClassName[256];
    GetClassNameA(hWnd,ClassName,256);



    if((strstr(name,"Google")!=0))
    {
        g_Processes = hWnd;
        print(QString(name));
        handles.push_back(hWnd);
    }

    if (name == NULL)
        return FALSE;
    return TRUE;
}

VOID FindProcessesWindow(HWND hWndStart)
{
    g_Processes = NULL;
    EnumChildWindows(hWndStart, FindProcessesWindowEnum, NULL);
    if (g_Processes != NULL)
        EnumChildWindows(g_Processes, FindProcessesChildWindowEnum, NULL);
}

void SearchWindow::setWindowFocus(std::string name)
{
    std::vector<HWND> wnds = SearchWnd(name);
    if(wnds.size()==0) return;
    int index = rand() % wnds.size();
    //BOOL enumeratingWindowsSucceeded = ::EnumChildWindows( GetDesktopWindow(), enumWindowsProc,  (LPARAM)programname.c_str());
    //qDebug << "Setting focus to window." << std::endl;
    HWND hWnd = wnds[index];
    SetForegroundWindow(hWnd);
}


SearchWindow::SearchWindow()
{

}

std::vector<HWND> SearchWindow::SearchWnd(std::string name)
{
    handles.clear();
    FindProcessesWindow(GetDesktopWindow());
    return handles;
}
