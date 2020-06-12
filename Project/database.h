#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>


class DataBase
    {
    public:
        DataBase(const QString& path);
        void AjouterPilote(const QString& username,const QString& password,const QString& Nom,const QString& Prenom,const QString& Email);
        bool ExistePilote(const QString& username);
        bool Connexion(const QString& username,const QString& password);
    private:
        QSqlDatabase m_db;
};


#endif // DATABASE_H
