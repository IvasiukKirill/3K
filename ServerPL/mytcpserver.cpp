#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include "functions.h"

MyTcpServer::~MyTcpServer()
{
    foreach(int i,SClients.keys()){
                QTextStream os(SClients[i]);
                SClients[i]->close();
                SClients.remove(i);
            }
    server_status=0;
    mTcpServer->close();
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        QTcpSocket* clientSocket=mTcpServer->nextPendingConnection();
        int indesersocs=(int)clientSocket->socketDescriptor();
        SClients[indesersocs]=clientSocket;
        SClients[indesersocs]->write( "Hello, user!!! I am echo server!\r\n");
        connect(SClients[indesersocs], &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(SClients[indesersocs],&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket* clientSocket=(QTcpSocket*)sender();
    int id = (int)clientSocket->socketDescriptor();
    QByteArray array;
    std::string message;
    while(clientSocket->bytesAvailable()>0)
    {
        array =clientSocket->readAll();
        message.append(array);
    }
    //message="auth&user&1234";
    qDebug()<<QString::fromStdString(message);

    array.clear();
    array.append(QString::fromStdString(parsing(message)));

    clientSocket->write(array);

}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* clientSocket=(QTcpSocket*)sender();
    int id = (int)clientSocket->socketDescriptor();
    clientSocket->close();
    SClients.remove(id);
    qDebug() << QString::fromUtf8("Client is disconnected\n");
}
