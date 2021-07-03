#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>
class functions
{
public:
    static std::string new_param(std::string  temp);
   static std::string parsing(std::string mess);

   static std::string auth(std::string login, std::string password); //запрос на авторизацию
   static std::string send_stat(std::string status); //запрос на выдачу статисткики
   static bool validate_string(QString string);
};


#endif // FUNCTIONS_H
