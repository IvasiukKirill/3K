#include "functions.h"
#include <iostream>

QString auth(std::string login,std::string password) //авторизация
{
    QString result;
    if (login =="admin" && password == "123")
        result = "admin";
    else if (login =="user" && password == "456")
        result = "user";
    else
        result = "authorization error";
    return result;
}

QString send_stat(){ //отправить статус
    QString result;
    std::cout << "Search status" << std::endl;
    return result;
}
