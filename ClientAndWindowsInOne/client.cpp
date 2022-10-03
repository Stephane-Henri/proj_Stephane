#include "client.h"
#include <QDebug>
#include <QCoreApplication>


client * client::p_instance=0;
clientDestroyer client::destroyer;
QTcpSocket * client::mTcpSocket;

clientDestroyer::~clientDestroyer(){
    delete p_instance;
}

void clientDestroyer::initialize(client * p){
    p_instance = p;
}

client::client(QObject *parent){
    mTcpSocket = new QTcpSocket(this);
    mTcpSocket->connectToHost("127.0.0.1", 33333);
    connect(mTcpSocket, &QTcpSocket::readyRead, this, &client::slotServerRead);
}

client::~client(){
    mTcpSocket->close();
}

client* client::getInstance(){
    if (!p_instance)
    {
        p_instance = new client();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

void client::sendToServer(QString message){
    qDebug() << "send";
    mTcpSocket->write(message.toUtf8());
}




void client::slotServerRead(){
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray res = mTcpSocket->readAll();
        qDebug() << res;

        if (res == "Welcome"){
            emit welcome();
        }
        else if (res == "Registration success"){
            emit registered();
        }

    }

}
