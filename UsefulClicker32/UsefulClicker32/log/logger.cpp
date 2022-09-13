#include "logger.h"

void log2(const char* fmt,...)
{
    va_list ap;
    static char buffer[60000];

    va_start(ap, fmt);
    #ifdef WIN32
    _vsnprintf_s(buffer, 60000, fmt, ap);
    #else
    vsnprintf(mu_printftmp, 60000, fmt, ap);
    #endif
    va_end(ap);

    MainWindow::getInstance()->log(QString(buffer));
    //log();
}


Logger::Logger()
{

}
