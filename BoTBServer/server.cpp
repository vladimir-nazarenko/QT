#include "server.h"

Server::Server()
{
    socket = new QTcpSocket();
    ticker = new QTimer();
//    connect(socket, SIGNAL(connected()), this, SLOT(onConnect()));
//    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
//    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(ticker, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));

    ticker->start(50);
}

Server::~Server()
{
}

void Server::start()
{
//    if (!listen(QHostAddress("127.0.0.1"), (quint16)12596))
//        std::cout << "Something wrong with start\n";
//    else
//        std::cout << "It's OK";
}

void Server::onConnect()
{
}


void Server::onReadyRead()
{
    QDataStream in(socket);
    QString str;
    in >> str;
    std::cout << str.toStdString();
}

void Server::onTimerTimeout()
{
    std::cout << ".";
}


void Server::onDisconnect()
{
}
