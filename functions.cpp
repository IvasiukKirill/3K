#include "functions.h"
#include <iostream>

QString authorize(std::string login,std::string password) //авторизация
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

QString start(){ //обработка запроса на старт
    QString result;
    std::cout << "Beginning of the game" << std::endl;
    return result;
}

QString finish(){ //обработка запроса на конец
    QString result;
    std::cout << "The end of the game" << std::endl;
    return result;
}
QString nextmotion(){ //обработка запроса на очер хода
    QString result;
    std::cout << "Game processing" << std::endl;
    return result;
}
QString send_stat(){ //отправить статус
    QString result;
    std::cout << "Search status" << std::endl;
    return result;
}

QString sendresgame(){ //отправить результат игры
    QString result;
    std::cout << "Send result" << std::endl;
    return result;
}

QString endgamechack(){ //проверка на конец игры
    QString result;
    std::cout << "The game finish?" << std::endl;
    return result;
}
