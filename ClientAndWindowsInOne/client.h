#ifndef CLIENT_H
#define CLIENT_H
#pragma once

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QObject>
#include <QTcpSocket>
#include <QStringList>


class client;

class clientDestroyer
{
    private:
        client * p_instance;
    public:
        ~clientDestroyer();
        void initialize(client * p);
};


class client: public QObject
{
    Q_OBJECT
    private:
        static client * p_instance;
        static clientDestroyer destroyer;
        static QTcpSocket * mTcpSocket;

    protected:
         client(QObject *parent = nullptr);
        ~client();
        client(const client& );
        client& operator = (client &);
        friend class clientDestroyer;

    public:
        static client* getInstance();
        void sendToServer(QString message);

signals:
    void welcome();
    void registered();
public slots:
    void slotServerRead();
};

#endif // CLIENT_H

