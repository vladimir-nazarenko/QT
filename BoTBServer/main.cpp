#include <QCoreApplication>
#include "server.h"
#include "timershell.h"
//#include <QThread>
//#include <QEvent>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
 std::cout << "almost_wonderful";
   // QThread *thread = new QThread();
    //TimerShell *sh = new TimerShell();
    //sh->moveToThread(thread);

    //thread->start();
    std::cout << "wonderful";
    return a.exec();
}
