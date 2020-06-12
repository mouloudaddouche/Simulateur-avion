#include "inscription.h"
#include "ui_inscription.h"

Inscription::Inscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inscription)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/BUYMORE/Documents/Enregistrement.png");
    ui->label_picture->setPixmap(pix.scaled(150,200,Qt::KeepAspectRatio));
}

Inscription::~Inscription()
{
    delete ui;
}

void Inscription::on_pushButton_clicked()
{
    DataBase db("C:/Users/BUYMORE/Documents/Pilote.db");
    QString Username =ui->lineEdit_Username->text();
    QString Password = ui->lineEdit_Password->text();
    QString Nom= ui->lineEdit_Nom->text();
    QString Prenom = ui->lineEdit_Prenom->text();
    QString Email = ui->lineEdit_Email->text();

    if ( db.ExistePilote(Username)){
        QMessageBox::warning(this,"pushButton","Utilisateur Existe déja, Veuillez réessayer avec un autre Username.");
    }
        else {
        db.AjouterPilote(Username,Password,Nom,Prenom,Email);
         QMessageBox::information(this,"pushButton","Inscription Reussite.");
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
}

