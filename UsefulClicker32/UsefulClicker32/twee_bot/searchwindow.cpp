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


    char* query = (char*) lParam;
    if((strstr(name,query)!=0))
    {
        g_Processes = hWnd;
        print(QString(name));
        handles.push_back(hWnd);
    }

    if (name == NULL)
        return FALSE;
    return TRUE;
}

VOID FindProcessesWindow(HWND hWndStart, char* query)
{
    g_Processes = NULL;
    EnumChildWindows(hWndStart, FindProcessesWindowEnum, (LPARAM)query);
    if (g_Processes != NULL)
        EnumChildWindows(g_Processes, FindProcessesChildWindowEnum, (LPARAM)query);
}

HWND SearchWindow::setWindowFocus(std::string name)
{
    std::vector<HWND> wnds = SearchWnd(name);
    if(wnds.size()==0) return 0;
    int index = rand() % wnds.size();
    //BOOL enumeratingWindowsSucceeded = ::EnumChildWindows( GetDesktopWindow(), enumWindowsProc,  (LPARAM)programname.c_str());
    //qDebug << "Setting focus to window." << std::endl;
    HWND hWnd = wnds[index];
    SetForegroundWindow(hWnd);
    return hWnd;
}


SearchWindow::SearchWindow()
{

}

std::vector<HWND> SearchWindow::SearchWnd(std::string name)
{
    handles.clear();
    FindProcessesWindow(GetDesktopWindow(),(char*)name.c_str());
    return handles;
}
