#include "dialog.h"
#include <QApplication>
#include <QMessageBox>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    std::cout << "omg u did this!";
    return a.exec();
}
