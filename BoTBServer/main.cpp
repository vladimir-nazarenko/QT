#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server server;
    QObject::connect(&server, SIGNAL(serverStopped()), &a, SLOT(quit()));
    server.start();
    return a.exec();
}
