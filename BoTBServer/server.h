#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QObject>
#include <iostream>
#include <QTimer>

class Server:public QObject
{
    Q_OBJECT

public:
    Server();
    virtual ~Server();

    void start();

public slots:
    void onConnect();
    void onDisconnect();
    void onReadyRead();
    void onTimerTimeout();
private:
    QTcpSocket *socket;
    QTimer *ticker;
};

#endif // SERVER_H
