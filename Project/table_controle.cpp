#include "table_controle.h"

table_controle::table_controle(reservoir* Tank1, reservoir* Tank2, reservoir* Tank3,
                               moteur* M1, moteur* M2, moteur* M3,  vanne_reservoir* VT12,
                                vanne_reservoir* VT23, vanne_moteur* V12, vanne_moteur* V13,
                                vanne_moteur* V23 ){

    //----------------sauvegarde
    this->Tk1 = Tank1;
    this->Tk2 = Tank2;
    this->Tk3 = Tank3;
    //----------------sauvegarde
    m1 = M1;
    m2 = M2;
    m3 = M3;
    //----------------sauvegarde
    vt12 = VT12;
    vt23 = VT23;
    VT23->setAutre_vanne(VT12);
    VT12->setAutre_vanne(VT23);
    //----------------sauvegarde
    v12 = V12;
    v13 = V13;
    v23 = V23;

    TableauDeBord* w = new TableauDeBord();
    fenetre = new FenPrincipale();
    fenetre->setCentralWidget(w);
    this->monObjet1 = new tb();
    w->setVisible(true);
    fenetre->setVisible(true);
    monObjet1->show();
    fenetre->setAutoFillBackground( true );
    w->setAutoFillBackground( true );
    fenetre->setFocus();
    fenetre->show();
    QObject::connect(monObjet1, SIGNAL(send(int)), this, SLOT(receive(int)));
}

void table_controle::receive( int valeur ){
    this->monObjet1->setNum(0);
    std::cout<<"alors\n";
    if (valeur == 1) receiveVT12(valeur);
    else if (valeur == 2) receiveVT23(valeur);
    else if (valeur == 3) receiveV12(valeur);
    else if (valeur == 4) receiveV13(valeur);
    else if (valeur == 5) receiveV23(valeur);
    else if (valeur == 6) receiveP12(valeur);
    else if (valeur == 7) receiveP22(valeur);
    else if (valeur == 8) receiveP32(valeur);
    else if (valeur == 9) receivePP(valeur);
    else if (valeur == 10) receivePPS(valeur);
    else if (valeur == 11) receiveVM(valeur);
    else if (valeur == 12) receiveVR(valeur);
    else if (valeur == 13) receiveEQ(valeur);
}
void table_controle::receivePP(int valeur){
    this->monObjet1->hide();
    this->fenetre->show();
    this->m1->panne_pompeP();
    this->monObjet1->show();
}
void table_controle::receivePPS(int valeur){
    this->monObjet1->hide();
    this->fenetre->show();
    this->m1->panne_pompeS();
    this->monObjet1->show();
}
void table_controle::receiveVM(int valeur){
    this->monObjet1->hide();
    this->fenetre->show();

    this->monObjet1->show();
}
void table_controle::receiveVR(int valeur){
    this->monObjet1->hide();
    this->fenetre->show();
    this->Tk1->vidange();this->Tk1->vidange();this->Tk1->vidange();this->Tk1->vidange();this->Tk1->vidange();
    this->Tk1->vidange();this->Tk1->vidange();this->Tk1->vidange();this->Tk1->vidange();this->Tk1->vidange();
    this->monObjet1->show();
}
void table_controle::receiveEQ(int valeur){
    this->monObjet1->hide();
    this->fenetre->show();

    this->monObjet1->show();
}

void table_controle::receiveVT12( int valeur ){
    this->monObjet1->hide();
    this->fenetre->show();
    if (this->vt12->getOuverte()) this->vt12->fermer();
    else this->vt12->ouvrir();
    std::cout << !this->m1->getProvenance()->getEst_Vide()<< "\n";
    if (!this->m1->getProvenance()->getEst_Vide()) m1->setEn_marche(true);
    if (!this->m2->getProvenance()->getEst_Vide()) m2->setEn_marche(true);
    if (!this->m3->getProvenance()->getEst_Vide()) m3->setEn_marche(true);
    this->monObjet1->show();
}
void table_controle::receiveVT23( int valeur ){
    this->monObjet1->hide();
    this->fenetre->show();
    if (this->vt23->getOuverte()) this->vt23->fermer();
    else this->vt23->ouvrir();
    if (!this->m1->getProvenance()->getEst_Vide()) m1->setEn_marche(true);
    if (!this->m2->getProvenance()->getEst_Vide()) m2->setEn_marche(true);
    if (!this->m3->getProvenance()->getEst_Vide()) m3->setEn_marche(true);
    this->monObjet1->show();
}
void table_controle::receiveV12( int valeur ){
    this->monObjet1->hide();
    this->fenetre->show();
    if (this->v12->getOuverte()) this->v12->fermer();
    else this->v12->ouvrir();
    this->monObjet1->show();
}
void table_controle::receiveV13( int valeur ){
    this->monObjet1->hide();
    this->fenetre->show();
    if (this->v13->getOuverte()) this->v13->fermer();
    else this->v13->ouvrir();
    this->monObjet1->show();
}
void table_controle::receiveV23( int valeur ){
    this->monObjet1->hide();
    this->fenetre->show();
    if (this->v23->getOuverte()) this->v23->fermer();
    else this->v23->ouvrir();
    this->monObjet1->show();
}
void table_controle::receiveP12( int valeur ){
    this->monObjet1->hide();
    this->fenetre->show();
    if (!this->Tk1->getPompe_secondaire()->getEn_panne()){
    if (this->Tk1->getPompe_secondaire()->getEn_marche()) this->m1->arreter_pompe_s();
    else this->m1->demarrer_pompe_s();}
    this->monObjet1->show();
}
void table_controle::receiveP22( int valeur ){
    this->monObjet1->hide();
    this->fenetre->show();
    if (!this->Tk2->getPompe_secondaire()->getEn_panne()){
    if (this->Tk2->getPompe_secondaire()->getEn_marche()) this->m2->arreter_pompe_s();
    else this->m2->demarrer_pompe_s();}
    this->monObjet1->show();
}
void table_controle::receiveP32( int valeur ){
    this->monObjet1->hide();
    this->fenetre->show();
    if (!this->Tk3->getPompe_secondaire()->getEn_panne()){
    if (this->Tk3->getPompe_secondaire()->getEn_marche()) this->m3->arreter_pompe_s();
    else this->m3->demarrer_pompe_s();}
    this->monObjet1->show();
}
void table_controle::exercice1(){
    this->monObjet1->panne_pompe->show();
}
void table_controle::exercice2(){
    this->monObjet1->panne_p_s->show();
}
