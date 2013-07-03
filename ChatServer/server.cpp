#include "server.h"
#include <QStringBuilder>
#include <QStringList>

Server::Server(QString host, quint16 port):
	_host(host),
	_port(port)
{

}

Server::~Server()
{
	foreach (Client* client, *clients) {
		delete client;
	}

	delete clients;
}

void Server::start()
{
	if (!listen(_host, _port))
		addToLog("Failed to start at host "+_host.toString()+" port "+QString(_port), cEvent);
	else
		addToLog("Server started at host " + _host.toString() + " port " + QString(_port), cEvent);
}

void Server::incomingConnection(qintptr desc)
{
	Client *newClient = new Client(desc);
	connect(newClient, SIGNAL(incomingMessage(Client*, quint8 ,QString)), this, SLOT(onIncomingMessage(Client*, quint8 ,QString)));
	connect(newClient, SIGNAL(occuredError(Client*, QAbstractSocket::SocketError)),
			this, SLOT(onError(Client*, QAbstractSocket::SocketError)));
	connect(newClient, SIGNAL(disconnected(Client*)), this, SLOT(clientDisconnected(Client*)));
	clients->append(newClient);
}


void Server::onIncomingMessage(Client* client, quint8 command, QString message)
{
	switch (command)
	{
	case Client::cAuthenticate:
	{
		// Incoming message should be like this:
		// Name
		if (nameIsValid(message))
		{
			client->authenticated = true;
			client->name = message;
		}
	}
		break;
	case Client::cSendPrivate:
	{
		QStringList parsed = message.split('|');
		QString messageToUsers = parsed.takeAt(0);
		foreach (Client *client, *clients) {
			if (parsed.contains(client->name))
				client->sendMessage(messageToUsers);
		}
	}
		break;
	case Client::cGetUsersOnline:
	{
		QStringList sClients;
		foreach (Client *cClient, *clients)
		{
			if (cClient->authenticated)
				sClients.append(cClient->name);
		}

		client->sendMessage(sClients);
	}
		break;
	}


}

void Server::onError(Client*, QAbstractSocket::SocketError error)
{
	addToLog(QString(error), Qt::red);
}

void Server::clientDisconnected(Client *client)
{
	clients->removeAt(clients->indexOf(client));
}

bool Server::nameIsValid(QString name)
{
	if (name == "")
		return false;

	bool isValid = true;
	foreach(Client* client, *clients)
	{
		if (client->name == name)
			isValid = false;
	}

	return isValid;
}
