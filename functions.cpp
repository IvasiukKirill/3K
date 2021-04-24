#include "functions.h"
#include <iostream>

QString authorize(std::string login,std::string password)
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

QString start(){
    QString result;
    std::cout << "Beginning of the game" << std::endl;
    return result;
}

QString finish(){
    QString result;
    std::cout << "The end of the game" << std::endl;
    return result;
}
QString next(){
    QString result;
    std::cout << "Game processing" << std::endl;
    return result;
}
QString send_status(){
    QString result;
    std::cout << "Search status" << std::endl;
    return result;
}

