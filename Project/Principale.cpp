#include "Principale.h"
#include "ui_fenetre1.h"


Fenetre1::Fenetre1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fenetre1)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/BUYMORE/Documents/PhotoJeu.jpg");
    ui->label_picture->setPixmap(pix.scaled(450,300,Qt::KeepAspectRatio));
}

Fenetre1::~Fenetre1()
{
    delete ui;
}

void Fenetre1::on_pushButton_clicked()
{
 this->hide();
 Inscription FenIns;
 FenIns.setModal(true);
 FenIns.exec();
}

void Fenetre1::on_pushButton_2_clicked()
{
    this->hide();
    Connexion FenCon;
    FenCon.setModal(true);
    FenCon.exec();
}
