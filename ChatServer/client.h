#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>

class Client:public QObject
{
    Q_OBJECT

    const quint16 port = 4242;
    const QString hostName = "127.0.0.1";
    enum Command {sendPrivateMessage, sendToAll, authenicate,
                 getUsersList};

public:
    Client();
    ~Client();
    void sendMessage(QString message);
    inline void setName(QString newName) {name = newName;}
    inline QString getName() {return name;}
signals:
    void incomingMessage(Command command, QString message);
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
