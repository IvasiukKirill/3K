#include "game.h"
#include "functions.h"
#include <iostream>

game::game()
{

}

std::string start(std::string pole){ //обработка запроса на старт, создание массива с игрой
    std::string result;
    int s = std::stoi(pole); //размер массива
    /*char* tab[s][s];
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s; i++){
            tab[i][j] = 0;
        }
    }
    std::cout << "Beginning of game" << std::endl;
    //return tab; */
    return result;
}

std::string finish(){ //обработка запроса на конец
    std::string result;
    std::cout << "Your game is over" << std::endl;
    return result;
}
std::string nextmotion(){ //обработка запроса на очер хода
    std::string result;
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

