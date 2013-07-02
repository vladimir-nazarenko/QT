#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QDataStream>
#include "server.h"

class Client:public QObject
{
	Q_OBJECT

	friend class Server;

	static const quint16 port = 4242;
	static const quint8 cSendPrivate = 1;
	static const quint8 cSendToAll = 2;
	static const quint8 cAuthenticate = 3;
	static const quint8 cGetUsersOnline = 4;
	static const QString hostAdress;

public:
	Client(qintptr desc);
	~Client();
	void sendMessage(QString &message) const;
	void sendMessage(QStringList &message) const;

signals:
	void incomingMessage(Client* client, quint8 command, QString message);
private slots:
	void onConnect();
	void onDisconnect();
	void onError(QAbstractSocket::SocketError error);
	void onReadyRead();

private:
	QTcpSocket *socket;
	QString name;
	bool authenticated;
};

#endif // CLIENT_H
