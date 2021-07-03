#ifndef GAME_H
#define GAME_H
#include <QString>
/*!
     Класс game содержит непосредственно процесс самой игры

 */
class game
{
public:
    game();
};
std::string start();
std::string finish();
std::string nextmotion();
std::string sendresgame();
std::string endgamechack();

#endif // GAME_H
