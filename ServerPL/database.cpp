#include "database.h"
#include <QString>

DataBase::DataBase()
{
    //db = new QSqlDatabase;
}
bool DataBase::open(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sqlite.db");
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

std::string DataBase::querry(std::string str_querry)
{
    return "dgfd";
}
