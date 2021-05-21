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
    while(clientSocket->bytesAvailable()>0)
    {
        QByteArray array =clientSocket->readAll();
        std::string log = "";
        std::string pass = "";
        std::string message;
        message = array.toStdString();
        qDebug()<<QString::fromStdString(message);

        int pos = message.find("&");

        message.erase(0,pos+1);
        pos = message.find("&");
        log = message.substr(0,pos);
        message.erase(0,pos+1);

        pos = message.find("&");
        pass = message.substr(0,pos);
        message.erase(0,pos+1);

        qDebug()<<"login = "<<QString::fromStdString(log)
               <<"password = "<<QString::fromStdString(pass)
              <<"result = "<<auth(log,pass);


        array.clear();
        array.append(auth(log,pass));

        clientSocket->write(array);

    }
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* clientSocket=(QTcpSocket*)sender();
    int id = (int)clientSocket->socketDescriptor();
    clientSocket->close();
    SClients.remove(id);
    qDebug() << QString::fromUtf8("Client is disconnected\n");
}
