#include "database.h"
#include <QDebug>


DataBase::DataBase(const QString& path)
    {
       m_db = QSqlDatabase::addDatabase("QSQLITE");
       m_db.setDatabaseName(path);

       if (!m_db.open())
       {
          qDebug() << "Error: connection with database fail";
       }
       else
       {
          qDebug() << "Database: connection ok";
       }
    }

void DataBase::AjouterPilote(const QString& username,const QString& password)
{
   QSqlQuery query;
   if (!this->ExistePilote(username)){
   query.prepare("INSERT INTO User (username,password) VALUES (:username,:password)");
   query.bindValue(":username",username);
   query.bindValue(":password",password);
   if(!query.exec())qDebug() << "addPerson error: ";



   }

   //User existe déja : on affiche un message...
}

bool DataBase::ExistePilote(const QString& username){
    QSqlQuery query;
    query.prepare("SELECT username FROM User WHERE username = (:username)");
    query.bindValue(":username", username);
    if (query.exec())
    {
       if (query.next())
       {
          return true;
       }
       else return false;
    }

    else return false;
}

bool DataBase::Connexion(const QString& username,const QString& password){
    QSqlQuery query;
    query.prepare("SELECT * FROM User where ((password = (:password)) & (username = (:username))) ");
   query.bindValue(":username", username);
   query.bindValue(":password", password);
    if (query.exec())
    {
       if (query.next())
       {
          return true;
       }
       else return false;
    }
    else {qDebug() << "error";
          return false;}
}



