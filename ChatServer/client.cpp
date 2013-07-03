#include "client.h"

const QString Client::hostAdress = "127.0.0.1";

Client::Client(qintptr desc)
{
	socket = new QTcpSocket();
	connect(socket, SIGNAL(connected()), this, SLOT(onConnect()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
	connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
	connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));

	socket->setSocketDescriptor(desc);
}

Client::~Client()
{
	delete socket;
}

void Client::sendMessage(QString &message) const
{
	QByteArray block;
	QDataStream out(block);
	out << message;
	socket->write(block);
}

void Client::sendMessage(QStringList &message) const
{
	QByteArray block;
	QDataStream out(block);
	out << message;
	socket->write(block);
}


void Client::onConnect()
{
	// Clent already connected
}

void Client::onDisconnect()
{
	emit disconnected(this);
}

void Client::onError(QAbstractSocket::SocketError error)
{
	emit occuredError(this, error);
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

	quint8 command;
	in >> command;
	QString mes;
	in >> mes;
	emit incomingMessage(this, command, mes);
}
