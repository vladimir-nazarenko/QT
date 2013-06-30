#include "dialog.h"
#include "ui_dialog.h"
#include "../ChatServer"

#include <QTime>
#include <QMessageBox>
#include <QAbstractSocket>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    sok = new QTcpSocket(this);
    connect(sok, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
    connect(sok, SIGNAL(connected()), this, SLOT(onSokConnected()));
    connect(sok, SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));
    connect(sok, SIGNAL(error(QAbstractSocket::SocketError)), this,
            SLOT(onSokDisplayError(QAbstractSocket::SocketError)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pbSend_clicked()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    if (ui->cbToAll->isChecked())
        out << (quint8)MyClient::comMessageToAll;
    else
    {
        out << (quint8)MyClient::comMessageToUsers;
        QString s;
        foreach (QListWidgetItem *i, ui->lwUsers->selectedItems())
                s += i->text() + ",";
        s.remove(s.length() - 1, 1);
    }

    out << ui->pteMessages->document()->toPlainText();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    sok->write(block);
    ui->pteMessages->clear();
}

void Dialog::on_pbConnect_clicked()
{
    sok->connectToHost(ui->leAdress->text(), ui->sbPort->value());
}

void Dialog::on_pbDisconnect_clicked()
{
    sok->disconnectFromHost();
}

void Dialog::onSokConnected()
{
    ui->pbConnect->setEnabled(false);
    ui->pbDisconnect->setEnabled(true);
    _blockSize = 0;
    AddToLog("Connected to"+_sok->peerAddress().toString()+":"+QString::number(_sok->peerPort()),Qt::green);

        //autorization query
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out << (quint16)0 << (quint8)MyClient::comAuthReq << ui->leName->text();
        name = ui->leName->text();
        out.device()->seek(0);
        out << (qint16)(block.size() - sizeof(quint16));
        sok->write(block);
}

void Dialog::onSokDisconnected()
{
    ui->pbConnect->setEnabled(true);
    ui->pbDisconnect->setEnabled(false);
    ui->pbSend->setEnabled(false);
    ui->lwUsers->clear();
    AddToLog("Disconnected from"+_sok->peerAddress().toString()+":"+QString::number(_sok->peerPort()), Qt::green);
}

void Dialog::onSokReadyRead()
{
    QDataStream in(sok);
    if (blockSize == 0)
    {
        if (sok->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }

    if (sok->bytesAvailable() < blockSize)
        return;
    else
        blockSize = 0;
    quint8 command;
    in >> command;

    switch(command)
    {
        case MyClient::comUsersOnline:
        {
            QString users;
            in >> users;
            if (users == "")
                return;
            QStringList l = users.split(",");
            ui->lwUsers->addItems(l);
        }
        break;
        case MyClient::comPublicServerMessage:
        {
            QString message;
            in >> message;
            this->AddToLog("[PublicServerMessage]:" + message, Qt::red);
        }
            break;
    case MyClient::comMessageToUsers:
    {
        QString user;
        in >> user;
        QString message;
        in >> message;
        this->addToLog("[" + user + "](private)"+message, Qt::blue);
    }
        break;
    case MyClient::comPrivateServerMessage:
    {
        QString message;
        in >> message;
        this->addToLog("[PrivateServerMessage]:"+message, Qt::red);
    }
        break;
    case MyClient::comUserJoin:
        QString name;
        in >> name;
        ui->lwUsers->addItem(name);
        this->addToLog(name+" joined", Qt::green);
    }
    case MyClient::comUserLeft:
    {
        QString name;
        in >> name;
        ui->lwUsers->addItem(name+" left", Qt::green);
    }
        break;
    case MyClient::comErrNameInvalid:
    {
        QMessageBox::information(this, "Error", "This name is invalid.");
        sok->disconnectFromHost();
    }
    case MyClient::comErrNameUsed:
        {
            QMessageBox::information(this, "Error", "This name is already used.");
            sok->disconnectFromHost();
        }
        break;
}

void Dialog::onSokDisplayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
        case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, "Error", "The host was not found");
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, "Error", "The connection was refused by the peer.");
        break;
    default:
        QMessageBox::information(this, "Error", "The following error occurred: "+_sok->errorString());
    }
}

void Dialog::addToLog(QString text, QColor color)
{
    ui->lwLog->insertItem(0, QTime::currentTime().toString() + "text");
    ui->lwLog->item(0)->setTextColor(color);
}
