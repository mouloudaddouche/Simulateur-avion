#include "moteur.h"
#include <iostream>
moteur::moteur(reservoir* provenance, int identifiant)
{
    this->identifiant = identifiant;
    this->en_marche = false;
    this->provenance = provenance;
    if (!provenance->getEst_Vide()
            &&((provenance->getPompe_primaire()->getEn_marche())
                || (provenance->getPompe_secondaire()->getEn_marche()))) {
        this->en_marche = true;
    }
    if (this->en_marche){
        if (this->identifiant == 1) TableauDeBord::setN1(true);
        else if (this->identifiant == 2) TableauDeBord::setN2(true);
        else TableauDeBord::setN3(true);
    }
}
bool moteur::getEn_marche(){
    return this->en_marche;
}

void moteur::panne_pompeP(){
    this->provenance->panne_pompe_primaire();
    if (!provenance->getPompe_secondaire()->getEn_marche())
    {
    this->en_marche = false;
        if (this->identifiant == 1) TableauDeBord::setN1(false);
        else if (this->identifiant == 2) TableauDeBord::setN2(false);
        else TableauDeBord::setN3(false);
         if (this->en_marche){
        }
    }

}
void moteur::panne_pompeS(){
    this->provenance->panne_pompe_secondaire();
    if (!provenance->getPompe_primaire()->getEn_marche()){
        this->en_marche = false;
        if (this->en_marche){
            if (this->identifiant == 1) TableauDeBord::setN1(false);
            else if (this->identifiant == 2) TableauDeBord::setN2(false);
            else TableauDeBord::setN3(false);
        }
    }
}
void moteur::demarrer_pompe_s(){
    this->provenance->demarrer_pompe_secondaire();
    if (!this->en_marche) {
        this->en_marche = true;
        if (this->en_marche){
            if (this->identifiant == 1) TableauDeBord::setN1(true);
            else if (this->identifiant == 2) TableauDeBord::setN2(true);
            else TableauDeBord::setN3(true);
        }
    }
}
void moteur::arreter_pompe_s(){
    this->provenance->arreter_pompe_secondaire();
    if (!provenance->getPompe_primaire()->getEn_marche()){
        this->en_marche = false;
        if (this->en_marche){
            if (this->identifiant == 1) TableauDeBord::setN1(false);
            else if (this->identifiant == 2) TableauDeBord::setN2(false);
            else TableauDeBord::setN3(false);
        }
    }
    else {
        this->en_marche = true;
        if (this->en_marche){
            if (this->identifiant == 1) TableauDeBord::setN1(true);
            else if (this->identifiant == 2) TableauDeBord::setN2(true);
            else TableauDeBord::setN3(true);
        }
    }
}

reservoir* moteur::getProvenance(){
    return this->provenance;
}

void moteur::setProvenance(reservoir* provenance){
    this->provenance = provenance;
}

void moteur::setEn_marche(bool en_marche){
    this->en_marche = en_marche;
    if (this->en_marche){
        if (this->identifiant == 1) TableauDeBord::setN1(true);
        else if (this->identifiant == 2) TableauDeBord::setN2(true);
        else TableauDeBord::setN3(true);
    }else {
        if (this->identifiant == 1) TableauDeBord::setN1(false);
        else if (this->identifiant == 2) TableauDeBord::setN2(false);
        else TableauDeBord::setN3(false);
    }
}
int moteur::getIdentifiant(){
    return this->identifiant;
}
