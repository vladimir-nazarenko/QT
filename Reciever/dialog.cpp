#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    socket = new QTcpSocket();
    connect(socket, SIGNAL(connected()), this, SLOT(onSockConnected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onSockDisconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onSockReadyRead()));
    //connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSockDisplayError(QAbstractSocket::SocketError)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onSockConnected()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    ui->tbMessage->setText("omg I DID IT!!!");
    out << "This is spartaaaa!!1";
    socket->write(block);
}

void Dialog::onSockReadyRead()
{
}

void Dialog::onSockDisconnected()
{
}

void Dialog::on_pbSend_clicked()
{

}

void Dialog::on_pbConnect_clicked()
{
    socket->connectToHost(QHostAddress("127.0.0.1"), (quint16)12596);
}

void Dialog::on_pbDisconnect_clicked()
{
    socket->disconnectFromHost();
}


void Dialog::onSockDisplayError()
{
}
