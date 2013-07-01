#ifndef TIMERSHELL_H
#define TIMERSHELL_H

#include <QObject>
#include <QTimer>

class TimerShell : public QObject
{
    Q_OBJECT
public:
    explicit TimerShell(QObject *parent = 0);
    
signals:
    
public slots:
    void onTimerTick();
signals:
    void readyToFinish();
private:
    QTimer *timer;
};

#endif // TIMERSHELL_H
