#include "vanne_moteur.h"
#include <iostream>
vanne_moteur::vanne_moteur(int ouverte, reservoir* reservoir1, reservoir* reservoir2, moteur* m1, moteur* m2, int identifiant)
    : vanne(ouverte, reservoir1, reservoir2)
{
    this->identifiant = identifiant;
    this->m1 = m1;
    this->m2 = m2;
}

void vanne_moteur::ouvrir(){
    if(!this->ouverte){
    if (!this->m1->getEn_marche() || !this->m2->getEn_marche()){
        if (!this->m1->getEn_marche()){
            if (this->reservoir2->getIdentifiant() != this->getM1().getProvenance()->getIdentifiant())
                this->m1->setProvenance(this->reservoir2);
            else this->m1->setProvenance(this->reservoir1);

        if ((this->m1->getProvenance()->getPompe_primaire()->getEn_marche())
                    && (this->m1->getProvenance()->getPompe_secondaire()->getEn_marche())
                        && (!this->m1->getProvenance()->getEst_Vide()))
            {
                this->ouverte = true;
                this->m1->setEn_marche(true);
                if (this->identifiant == 12) TableauDeBord::setV12(true);
                if (this->identifiant == 13) TableauDeBord::setV13(true);
                if (this->identifiant == 23) TableauDeBord::setV23(true);
            }
        }
        if (!this->m2->getEn_marche()){
            if (this->reservoir2->getIdentifiant() != this->getM2().getProvenance()->getIdentifiant())
                this->m2->setProvenance(this->reservoir2);
            else this->m2->setProvenance(this->reservoir1);
        if ((this->m2->getProvenance()->getPompe_primaire()->getEn_marche())
                    && (this->m2->getProvenance()->getPompe_secondaire()->getEn_marche())
                        && (!this->m2->getProvenance()->getEst_Vide()))
            {
                this->ouverte = true;

            if (this->identifiant == 12) TableauDeBord::setV12(true);
            if (this->identifiant == 13) TableauDeBord::setV13(true);
            if (this->identifiant == 23) TableauDeBord::setV23(true);
            }
        }
    }
    }
}

void vanne_moteur::fermer(){
    if(this->ouverte){
        if (reservoir1->getPompe_primaire()->getEn_panne()
                && !reservoir1->getPompe_secondaire()->getEn_marche())
        {
            reservoir2->getPompe_secondaire()->arreter();
            this->ouverte = false;
            this->m2->setEn_marche(false);
            if (this->identifiant == 12) TableauDeBord::setV12(false);
            if (this->identifiant == 13) TableauDeBord::setV13(false);
            if (this->identifiant == 23) TableauDeBord::setV23(false);
        }
        else if (reservoir2->getPompe_primaire()->getEn_panne()
                 && !reservoir2->getPompe_secondaire()->getEn_marche())
         {
             reservoir1->getPompe_secondaire()->arreter();
             this->ouverte = false;
             this->m2->setEn_marche(false);
             if (this->identifiant == 12) TableauDeBord::setV12(false);
             if (this->identifiant == 13) TableauDeBord::setV13(false);
             if (this->identifiant == 23) TableauDeBord::setV23(false);
         }
    }
}
moteur vanne_moteur::getM1(){
    return *this->m1;
}
moteur vanne_moteur::getM2(){
    return *this->m2;
}
