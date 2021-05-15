#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>

QString auth(std::string login, std::string password);
QString start();
QString finish();
QString nextmotion();
QString send_stat();
QString sendresgame();
QString endgamechack();

#endif // FUNCTIONS_H
