#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>

QString auth(std::string login, std::string password); //запрос на авторизацию
QString send_stat(std::string stat); //запрос на выдачу статисткики

#endif // FUNCTIONS_H
