#include "game.h"
#include <iostream>

game::game()
{

}

std::string start(){ //обработка запроса на старт
    std::string result;
    std::cout << "Beginning of the game" << std::endl;
    return result;
}

std::string finish(){ //обработка запроса на конец
    std::string result;
    std::cout << "The end of the game" << std::endl;
    return result;
}
std::string nextmotion(){ //обработка запроса на очер хода
    std::string result;
    std::cout << "Game processing" << std::endl;
    result = sendresgame();
    result = endgamechack();
    return result;
}

std::string sendresgame(){ //отправить результат игры
    std::string result;
    std::cout << "Send result" << std::endl;
    return result;
}

std::string endgamechack(){ //проверка на конец игры
    std::string result;
    std::cout << "The game finish?" << std::endl;
    return result;
}

