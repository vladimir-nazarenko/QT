#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QObject>
#include <iostream>
#include <QTimer>

class Server:public QTcpServer
{
    Q_OBJECT

public:
    Server();
    virtual ~Server();

    void start();

signals:
    void serverStopped();

public slots:
    void onConnect();
    void onDisconnect();
    void onReadyRead();
    void onTimerTimeout();
    void onError();
private:
    QTcpSocket *socket;
    QTimer *ticker;
protected:
    void incomingConnection(qintptr desc);
};

#endif // SERVER_H
