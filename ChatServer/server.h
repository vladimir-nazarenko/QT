#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QObject>
#include <iostream>
#include <QTimer>
#include "client.h"

class Server:public QTcpServer
{
    Q_OBJECT

    static const Color cMToAll = Qt::green;
    static const Color cEvent = Qt::black;

public:
    Server(QString hostAdress, quint16 port);
    virtual ~Server();

    void start();

signals:
    void serverStopped();
    void addToLog(QString message, Color color);

public slots:
    void onIncomingMessage(quint8 command, QString message);
    void onError();
private:
    QList<Client*> *clients;
    QHostAddress host;
    quint16 port;
protected:
    void incomingConnection(qintptr desc);
};

#endif // SERVER_H
