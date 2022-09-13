#ifndef LOGGER_H
#define LOGGER_H

#include "../mainwindow.h"

#define Log(msg) MainWindow::getInstance()->log(msg)
void log2(const char* fmt,...);
#define Log2(fmt, msg) log2(fmt,msg)

class Logger
{
public:
    Logger();
};

#endif // LOGGER_H
