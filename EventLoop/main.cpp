#include <QCoreApplication>
#include <QEventLoop>
#include <iostream>
#include "timershell.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "it was printed, omg";
    TimerShell *sh = new TimerShell();
    QObject::connect(sh, SIGNAL(readyToFinish()), &a, SLOT(quit()));
    a.exec();

    delete sh;
    std::cout << "ololo it works";
    return 0;
}
