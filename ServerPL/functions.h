#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>

std::string new_param(std::string & temp);
std::string parsing(std::string mess);

std::string auth(std::string login, std::string password); //запрос на авторизацию
std::string send_stat(std::string status); //запрос на выдачу статисткики

#endif // FUNCTIONS_H
