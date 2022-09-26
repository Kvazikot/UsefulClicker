#include "mainwindow.h"
#include "twee_bot/tweebot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow w;
    //w.show();

    TweeBot w;
    w.show();

    return a.exec();
}
