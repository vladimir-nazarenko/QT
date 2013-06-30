#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::Dialog)
{
    sok = new QTcpSocket(this);
    connect(sok, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
    connect(sok, SIGNAL(connected()), this, SLOT(onSokConnected()));
    connect(sok, SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));
    connect(sok, SIGNAL(error(QAbstractSocket::SocketError)), this,
            SLOT(onSokDisplayError(QAbstractSocket::SocketError)));
}

void Dialog::on_pbConnected_clicked()
{
    sok->connectToHost(ui->leHost->text(), ui->sbPort->value());
}
