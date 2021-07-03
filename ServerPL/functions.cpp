#include "functions.h"
#include <iostream>
#include "database.h"
#include "game.h"
#include <QDebug>
/*! \brief Методы класса functions
    Занимается разбором сообщения, разбивает сообщения, проводит регистрацию и авторизацию и высылает статистику побед-проигрышей
*/
std::string new_param(std::string & temp)
{
    int pos = -1;
    pos = temp.find("&");
    std::string res = temp.substr(0,pos);
    temp.erase(0,pos+1);
    return res;
}

std::string parsing(std::string mess)
{
    std::string name_of_func;

    name_of_func = new_param(mess);

    if(name_of_func=="auth"){

        std::string log = "";
        std::string pass = "";

        log = new_param(mess);
        pass = new_param(mess);
        return auth(log,pass);
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
        std::string log = "";
        log = new_param(mess);
        return send_stat(log);
    }

    else if (name_of_func=="start"){
         std::string pole = ""; //создание поля
         pole = new_param(mess);
         //char* tab = std::string start(pole);

    }

    else if (name_of_func=="finish"){
        std::string finish (mess);
    }

    else if (name_of_func=="nextmotion"){
        std::string move = "";
        move = new_param(mess);
        std::string nextmotion(move);

    }
    else {
        return "statistic";
    }
}

std::string auth(std::string log,std::string pass) //авторизация, подключение к бд
{
    DataBase db;
    db.open();
    //db.querry("");
    std::string result = db.querry("SELECT login, password FROM bd_kr_nl WHERE login='" + log + "' AND password='"+pass+"' ;");
    qDebug()<<QString::fromStdString(result);
    if (result == ""){
            result = "auth_false";
        }
        else {
            result = "auth_true";
        }
    return result;
}
std::string reg(std::string log,std::string pass)
{
    DataBase db;
    db.open();
    //db.querry("");
    std::string result = db.querry("SELECT login, password FROM bd_kr_nl WHERE login='" + log + "' AND password='"+pass+"' ;");
    qDebug()<<QString::fromStdString(result);
    if (result == "" || result == " "){
            db.querry("INSERT INTO bd_kr_nl VALUES ('"+log+"', '"+pass+"', 0, 0);");
            qDebug()<<QString::fromStdString(result);
            result = "reg_true";
        }
        else {
            result = "reg_false";
        }
    return result;
}
std::string send_stat(std::string log){ //отправить статус
        DataBase db;
        db.open();
        std::string result = db.querry("SELECT pobed, porog FROM bd_kr_nl WHERE login = '" + log + "';");
        qDebug()<<QString::fromStdString(result);
        return result;

    //std::string result;
    //std::cout << "Search status" << std::endl;
    //std::cout << "Your status is " << std::endl;

    //return result;
}
