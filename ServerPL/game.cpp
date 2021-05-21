#include "game.h"
#include <iostream>

game::game()
{

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

