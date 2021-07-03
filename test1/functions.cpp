#include "functions.h"
#include <iostream>
/*
#include "database.h"
#include "game.h"
*/
#include <QDebug>

std::string functions::new_param(std::string  temp)
{
    int pos = -1;
    pos = temp.find("&");
    std::string res = temp.substr(0,pos);
    temp.erase(0,pos+1);
    return res;
}

/*std::string functions::parsing(std::string mess)
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

    else if (name_of_func=="status"){
        return "status";
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

*/
/*
std::string functions::auth(std::string log,std::string pass) //авторизация, подключение к бд
{
    DataBase db;
    //db.open();
    //db.querry("");
    std::string result = db.querry("SELECT login, password FROM bd_kr_nl WHERE login=log AND password=pass;");
    //std::string result = db.querry("SELECT login, password FROM bd_kr_nl WHERE login = " + log + " AND password = "+pass+" ;");
    qDebug()<<QString::fromStdString(result);
    if (result == ""){
        result = "auth_false\n";
    }
    else{
        result = "auth_true";
    }
    return result;
    }
*/

std::string functions::send_stat(std::string status){ //отправить статус
    std::string result;
    std::cout << "Search status" << std::endl;
    std::cout << "Your status is " << std::endl;

    return result;
}


bool functions::validate_string(QString string)
{
   for (int i=0;i<string.length();i++)
   {
       if (string[i]>'0' && string[i]<='9')
       {
           return false;
           break;


       }


   }

    return true;

}







