#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QObject>
#include <iostream>
#include <QTimer>
#include "client.h"

// I wonder what this blue label do?
class Client;

class Server:public QTcpServer
{
	Q_OBJECT

	static const Qt::GlobalColor cMToAll = Qt::green;
	static const Qt::GlobalColor cEvent = Qt::black;

public:
	Server(QString hostAdress, quint16 port);
	virtual ~Server();

	void start();

signals:
	void serverStopped();
	void addToLog(QString message, Qt::GlobalColor color);

public slots:
	void onIncomingMessage(Client *client, quint8 command, QString message);
	void onError(Client*, QAbstractSocket::SocketError error);
	void clientDisconnected(Client* client);
private:
	bool nameIsValid(QString name);
	QList<Client* > *clients;
	QHostAddress _host;
	quint16 _port;
protected:
	void incomingConnection(qintptr desc);
};

#endif // SERVER_H
