#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>
#include <QTcpSocket>
#include <QDebug>

std::string new_param(std::string & temp);
std::string parsing(std::string mess, QTcpSocket *clientSocket, QMap<std::string, std::string> map);

std::string auth(std::string login, std::string password); //запрос на авторизацию
std::string send_stat(std::string status); //запрос на выдачу статистики
std::string reg(std::string log, std::string pass);

#endif // FUNCTIONS_H
