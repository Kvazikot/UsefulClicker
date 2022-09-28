#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <windows.h>
#include <string>
#include <vector>

class SearchWindow
{
public:

    SearchWindow();
    std::vector<HWND> SearchWnd(std::string name);
    void setWindowFocus(std::string name);
};

#endif // SEARCHWINDOW_H
