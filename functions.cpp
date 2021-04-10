#include "functions.h"

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

