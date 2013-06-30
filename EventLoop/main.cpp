#include <QCoreApplication>
#include <QEventLoop>
#include <iostream>
#include "timershell.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QEventLoop* loop = new QEventLoop();
    TimerShell *sh = new TimerShell();
    QObject::connect(sh, SIGNAL(readyToFinish()), loop, SLOT(quit()));
    loop->exec();
    delete loop;
    delete sh;
    std::cout << "ololo it works";
    //return a.exec();
    return 0;
}
