#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    /**
     * @brief Функция создания слота для нового подключения
     */
    void slotNewConnection();
    /**
     * @brief Функция отключения клиента
     */
    void slotClientDisconnected();
    /**
     * @brief Функция чтения строки от пользователя
     */
    void slotServerRead();
private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    /**
     * @brief список подключенний, сокетов
     */
    QList<QTcpSocket*> list;
    //int server_status;
};
#endif // MYTCPSERVER_H







