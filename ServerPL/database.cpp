#include "database.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>
/*! \brief Методы класса fatabase
    Присоединяется к базе данных, проверяет успешность подключение и считывает значения после отправления запроса
*/
DataBase::DataBase()
{
    //db = new QSqlDatabase;
}
bool DataBase::open(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Consttt/Desktop/JJ/ServerPL/sqlite.db");
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

std::string DataBase::querry(std::string str_querry)
{
    qDebug() << QString::fromStdString(str_querry) << "\n";
    std::string res;
    QSqlQuery query(db);
    query.exec(QString::fromStdString(str_querry));
        /*while (query.next()) {
            QString country = query.value(0).toString();
            res+=(country.toStdString());
        }*/
    query.next();
    res = query.value(0).toString().toStdString()+query.value(1).toString().toStdString();
    qDebug() << QString::fromStdString(res) << "\n";
    return res;
}
