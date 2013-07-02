#include "server.h"

Server::Server()
{
    socket = new QTcpSocket();
    ticker = new QTimer();
    connect(socket, SIGNAL(connected()), this, SLOT(onConnect()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(ticker, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
    //socket->connectToHost(QHostAddress("127.0.0.1"), (quint16)12596);
    //ticker->start(1000);
}

Server::~Server()
{
}

void Server::start()
{
    if (!listen(QHostAddress("127.0.0.1"), (quint16)12596))
        std::cout << "Something wrong with start\n";
    else
        std::cout << "It's OK";
    std::cout.flush();
}
void Server::onConnect()
{
    //std::cout << "Got connection";
}


void Server::onReadyRead()
{
    if (socket->bytesAvailable() < 3)
        return;
    qDebug() << "ReadyRead";
    QDataStream in(socket);
    QString result;
    in >> result;
    qDebug() << result;
    QString s(socket->readAll());
    qDebug() << s;
}

void Server::onTimerTimeout()
{
    /*std::cout << ".";
    std::cout.flush();*/
}

void Server::onError()
{
    /*QString err = socket->errorString();
    std::cout << err.toStdString();*/
}

void Server::incomingConnection(qintptr desc)
{
    std::cout.flush();
    socket->setSocketDescriptor(desc);
}


void Server::onDisconnect()
{
}
