#include "functions.h"
#include <iostream>
#include "database.h"
#include "game.h"
#include <QDebug>

std::string new_param(std::string & temp)
{
    int pos = -1;
    pos = temp.find("&");
    std::string res = temp.substr(0,pos);
    temp.erase(0,pos+1);
    return res;
}

std::string parsing(std::string mess, QTcpSocket *clientSocket, QMap<std::string, std::string> map)
{
    std::string name_of_func;

    name_of_func = new_param(mess);

    if(name_of_func=="auth"){

        std::string log = "";
        std::string pass = "";

        log = new_param(mess);
        pass = new_param(mess);
        std::string prov = auth(log,pass);

        if (prov == "0"){
           clientSocket->write("auth&false");
        } else {
           clientSocket->write("auth&true");
            }
    }

    else if (name_of_func=="reg")
    {
        std::string log = "";
        std::string pass = "";

        log = new_param(mess);
        pass = new_param(mess);
        return reg(log,pass);
    }

    else if (name_of_func=="status"){
        //std::string stat = send_stat();
        //clientSocket->write("status&",stat);
        return "status";
    }

    else if (name_of_func=="start"){
         std::string pole = ""; //создание поля
         pole = new_param(mess);
         //char* tab = std::string start(pole);
         //clientSocket->write("start&true");
    }

    else if (name_of_func=="finish"){
        std::string finish (mess);
        //clientSocket->write("finish&true");
    }

    else if (name_of_func=="nextmotion"){
        std::string move = "";
        move = new_param(mess);
        std::string nextmotion(move);
        //clientSocket->write("nextmotion&",);
    }
    else {
        return "statistic";
    }
}

std::string auth(std::string log,std::string pass) //авторизация, подключение к бд
{
    DataBase db;
    db.open();
    std::string prov;
    //db.querry("");
    std::string result = db.querry("SELECT login, password FROM bd_kr_nl WHERE login='" + log + "' AND password='"+pass+"' ;");
    qDebug()<<QString::fromStdString(result);
    if (result == ""){
            result = "auth_false";
             prov = "0";
             qDebug()<<QString::fromStdString(result);
        }
        else {
            result = "auth_true";
            prov = "1";
            qDebug()<<QString::fromStdString(result);
        }
    return prov;
}

std::string send_stat(){ //отправить статус
    std::string result;
    std::string stat;
    qDebug()<< "Search status\n";
    qDebug()<<QString::fromStdString(stat);
    return stat;
}

std::string reg(std::string log,std::string pass)
{
    DataBase db;
    db.open();
    //db.querry("");
    std::string result = db.querry("SELECT login, password FROM bd_kr_nl WHERE login='" + log + "' AND password='"+pass+"' ;");
    qDebug()<<QString::fromStdString(result);
    if (result == ""){
            db.querry("INSERT INTO bd_kr_nl VALUES ('"+log+"', '"+pass+"', 0, 0);");
            qDebug()<<QString::fromStdString(result);
            result = "reg_true";
        }
        else {
            result = "reg_false";
        }
    return result;
}
