#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QDataStream>

class Client:public QObject
{
    Q_OBJECT

    static const quint16 port = 4242;
    static const quint8 cSendPrivate = 1;
    static const quint8 cSendToAll = 2;
    static const quint8 cAuthenticate = 3;
    static const quint8 cGetUsersOnline = 4;
    static const QString hostName;

public:
    Client(qintptr desc);
    ~Client();
    void sendMessage(QString message);
    inline void setName(QString newName) {name = newName;}
    inline QString getName() {return name;}

signals:
    void incomingMessage(quint8 command, QString message);
private slots:
    void onConnect();
    void onDisconnect();
    void onError(QAbstractSocket::SocketError error);
    void onReadyRead();

private:
    QTcpSocket *socket;
    QString name;
};

#endif // CLIENT_H
