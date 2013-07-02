#include "server.h"

Server::Server(QString host, quint16 port):
    _host(host),
    _port(port)
{

}

Server::~Server()
{
}

void Server::start()
{
    if (!listen(QHostAddress("127.0.0.1"), (quint16)12596))
        addToLog("Server started at host " + host + " port " + );
    else
        qDebug() << "It's OK";
}

void Server::incomingConnection(qintptr desc)
{
    Client *newClient = new Client(desc);
    connect(newClient, SIGNAL(incomingMessage(quint8 ,QString)), this, SLOT(onIncomingMessage(quint8 ,QString)));
    clients->append(newClient);
}


void Server::onIncomingMessage(quint8 command, QString message)
{
    if (command == Client::cSendToAll)
        emit addToLog(message, cMToAll);


}

void Server::onError()
{
}
