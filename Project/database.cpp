#include "database.h"
#include <QDebug>


DataBase::DataBase(const QString& path)
    {
       m_db = QSqlDatabase::addDatabase("QSQLITE");
       m_db.setDatabaseName(path);
       m_db.open();
    }

void DataBase::AjouterPilote(const QString& username,const QString& password,const QString& Nom,const QString& Prenom,const QString& Email)
{
   QSqlQuery query;
   if (!this->ExistePilote(username)){
   query.prepare("INSERT INTO User (username,password,Nom,Prenom,Email) VALUES (:username,:password,:Nom,:Prenom,:Email)");
   query.bindValue(":username",username);
   query.bindValue(":password",password);
   query.bindValue(":Nom",Nom);
   query.bindValue(":Prenom",Prenom);
   query.bindValue(":Email",Email);
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



