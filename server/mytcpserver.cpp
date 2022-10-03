#include "mytcpserver.h"
#include "myfunctions.h"
#include "myfunctions.cpp"
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QList>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        qDebug() << "server is started";
    }
}


void MyTcpServer::slotNewConnection(){
        QTcpSocket* mTcpSocket = mTcpServer->nextPendingConnection();
        list.push_back(mTcpSocket);
        qDebug() << "1";

        mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
}


void MyTcpServer::slotServerRead(){
    myfunctions f;
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    QString res = "";

    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array = mTcpSocket->readAll();
        res.append(array);
    }
    qDebug() << res;
    mTcpSocket->write(f.parsing(res).toUtf8());

}


void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    list.removeAt(list.indexOf(mTcpSocket));
    mTcpSocket->close();
    qDebug() << list.size();
}
