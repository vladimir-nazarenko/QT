#include "client.h"

Client::Client(qintptr desc)
{
    socket = new QTcpSocket();
    connect(socket, SIGNAL(connected()), this, SLOT(onConnect()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));

    socket->setSocketDescriptor(desc);
}


void Client::onConnect()
{
}

void Client::onDisconnect()
{
}

void Client::onError(QAbstractSocket::SocketError error)
{
}

void Client::onReadyRead()
{
    if (socket->bytesAvailable() < (int)sizeof(quint16))
        return;

    quint16 blockSize;
    QDataStream in(socket);
    in >> blockSize;

    if (socket->bytesAvailable() < (int)blockSize)
        return;

    Command com;
    in >> com;
    QString mes;
    in >> mes;
    emit incomingMessage(com, mes);
}
