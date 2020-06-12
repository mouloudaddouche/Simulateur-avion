#include "reservoir.h"

reservoir::reservoir(int capacite, int identifiant, int id_pompe1, int id_pompe2)
{
    this->capacite = capacite;
    this->identifiant = identifiant;
    this->est_vide = false;
    this->etat = capacite;
    this->panne_vidange = false;
    this->id_pompe1 = id_pompe1;
    this->id_pompe2 = id_pompe2;
    p11 = new pompe_primaire(id_pompe1);
    p12 = new pompe_secondaire(id_pompe2);
}

bool reservoir::getEst_Vide(){
    return this->est_vide;
}

void reservoir::vidange(){
    this->panne_vidange = true;
    this->etat = this->etat - 10;
    if (!this->etat) this->est_vide = true;
    if (this->identifiant == 2 ) {
        TableauDeBord::setEtat2(this->etat);
        if (this->getEst_Vide()) TableauDeBord::setN2(false);
    }
    else if (this->identifiant == 1 ) {
        TableauDeBord::setEtat1(this->etat);
        if (this->getEst_Vide()) TableauDeBord::setN1(false);
    }
    else {
        TableauDeBord::setEtat3(this->etat);
        if (this->getEst_Vide()) TableauDeBord::setN3(false);
    }
}

int reservoir::getEtat(){
    return this->etat;
}

int reservoir::getCapacite(){
    return this->capacite;
}

pompe_primaire* reservoir::getPompe_primaire(){
    return this->p11;
}
pompe_secondaire* reservoir::getPompe_secondaire(){
    return this->p12;
}
void reservoir::panne_pompe_primaire(){
    this->p11->panne_pompe();
}
void reservoir::panne_pompe_secondaire(){
    this->p12->panne_pompe();
}
void reservoir::demarrer_pompe_secondaire(){
    this->p12->demarrer();
}
void reservoir::arreter_pompe_secondaire(){
    this->p12->arreter();
}
int reservoir::getIdentifiant(){
    return this->identifiant;
}
bool reservoir::getPanneVidange(){
    return this->panne_vidange;
}
void reservoir::setEtat(int etat){
    this->etat = etat;
    if (this->etat > 0) this->est_vide = false;
}
void reservoir::setPanneVidange(bool panne_vidange){
    this->panne_vidange = panne_vidange;
}
