#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

signals:
    
public slots:
    
private slots:
    //handling sockets signal
    void onSokConnected();
    void onSokDisconnected();
    //is called when data packet recieved
    void onSocketReadyRead();
    void onSokDisplayError(QAbstractSocket::SocketError socketError);
private:
    QTcpSocket *sok;
    quint16 blockSize;
    QString name;
    void addToLog(QString text, QColor color);
};

#endif // DIALOG_H
