#include "timershell.h"
#include <iostream>

TimerShell::TimerShell(QObject *parent) :
    QObject(parent)
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTick()));
    std::cout << "ololo";

}

void TimerShell::onTimerTick()
{
    static int counter;
    std::cout << ".";
   // counter++;
   // if (counter > 10)
      //  emit readyToFinish();
}

void TimerShell::arrrriva()
{
    std::cout << "arrriva!";
    timer->start(50);
}
