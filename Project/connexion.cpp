#include "connexion.h"
#include "ui_connexion.h"

Connexion::Connexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connexion)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/BUYMORE/Documents/Login.ico");
    ui->label_picture->setPixmap(pix.scaled(140,100,Qt::KeepAspectRatio));
}

Connexion::~Connexion()
{
    delete ui;
}

void Connexion::on_pushButton_clicked()
{
    DataBase db("C:/Users/BUYMORE/Documents/Pilote.db");
    QString Username =ui->lineEdit_Username->text();
    QString Password = ui->lineEdit_Password->text();
    if(db.Connexion(Username,Password)){
        QMessageBox::information(this,"pushButton","Connexion Reussite.");
        this->hide();
        reservoir Tank1(100,1, 11,12);
        reservoir Tank2(80,2,112,122);
        reservoir Tank3(100,3,113,123);

        moteur M1(&Tank1, 1);
        moteur M2(&Tank2, 2);
        moteur M3(&Tank3, 3);

        vanne_reservoir VT12(false, &Tank1, &Tank2, 112);
        vanne_reservoir VT23(false, &Tank2, &Tank3,123);

        vanne_moteur V12(false, &Tank1, &Tank2, &M1, &M2, 12);
        vanne_moteur V13(false, &Tank1, &Tank3, &M1, &M3, 13);
        vanne_moteur V23(false, &Tank2, &Tank3, &M2, &M3, 23);
        table_controle* controle = new  table_controle(&Tank1, &Tank2, &Tank3, &M1, &M2, &M3,
                         &VT12, &VT23, &V12, &V13, &V23);

    }
    else
        QMessageBox::warning(this,"pushButton","Nom d'utilisateur ou le mot de passe est incorrect.");

}
