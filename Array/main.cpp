#include <QCoreApplication>
#include <iostream>
#include "istack.h"
#include "arraystack.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    IStack* stack = new ArrayStack();
    stack->push(15);
    stack->push(16);

    std::cout << stack->pop() << "second: " << stack->pop();
    int c = 0;
    std::cin >> c;
    return a.exec();
}
