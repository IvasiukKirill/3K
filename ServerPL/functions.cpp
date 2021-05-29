#include "functions.h"
#include <iostream>
#include "database.h"

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
    else if (name_of_func=="status"){
        return "status";
    }
    else if (name_of_func=="start"){
        return "start";
    }

    else if (name_of_func=="finish"){
        return"finish";
    }

    else if (name_of_func=="nextmotion"){
        return "nextmotion";
    }
    else {
        return "statistic";
    }

}

std::string auth(std::string login,std::string password) //авторизация
{
/*    std::string result;
    if (login =="admin" && password == "123")
        result = "admin";
    else if (login =="user" && password == "456")
        result = "user";
    else
        result = "authorization error";
*/
    DataBase db;
    db.open();
    db.querry("");
    std::string result=db.querry("");

    //проверка, если ничего не нашли, то result = "auth_false";
    //иначе result = "auth_statistic";
    return result;
}

std::string send_stat(std::string status){ //отправить статус
    std::string result;
    std::cout << "Search status" << std::endl;
    std::cout << "Your status is " << std::endl;

    return result;
}
