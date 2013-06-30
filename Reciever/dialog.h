#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private:
    Ui::Dialog *ui;
    QTcpSocket *socket;
    QHostAddress name;
    quint16 port;
    qint16 blockSize;

private slots:
    void onSockConnected();
    void onSockReadyRead();
    void onSockDisconnected();
    void onSockDisplayError();
    void on_pbSend_clicked();
    void on_pbConnect_clicked();
    void on_pbDisconnect_clicked();
};

#endif // DIALOG_H
