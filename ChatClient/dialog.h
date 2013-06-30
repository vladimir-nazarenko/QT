#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_pbSend_clicked();

    void on_pbConnect_clicked();

    void on_pbDisconnect_clicked();

    //handling sockets signal
    void onSokConnected();
    void onSokDisconnected();

    //is called when data packet recieved
    void onSocketReadyRead();
    void onSokDisplayError(QAbstractSocket::SocketError socketError);

private:
    Ui::Dialog *ui;
    QTcpSocket *sok;
    quint16 blockSize;
    QString name;
    void addToLog(QString text, QColor color = Qt::black);
};

#endif // DIALOG_H
