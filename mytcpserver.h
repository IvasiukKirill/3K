#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer> //класс с сигналами tcp
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
    void slotNewConnection();
    void slotClientDisconnected();

    void slotServerRead();
    //void slotReadClient();
private:

    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    int server_status;
    QMap<int, QTcpSocket *> SClients;
};
#endif // MYTCPSERVER_H






