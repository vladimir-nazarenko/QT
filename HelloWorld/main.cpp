#include <QCoreApplication>
#include <stdio.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    printf("Hello, world!");
    std::cout << "Hello, world(cout)!";
    return a.exec();
}
