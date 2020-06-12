#include "vanne_reservoir.h"
#include <iostream>
vanne_reservoir::vanne_reservoir(int ouverte, reservoir* reservoir1, reservoir* reservoir2, int identifiant)
    : vanne(ouverte, reservoir1, reservoir2)
{
    this->identifiant = identifiant;
}
void vanne_reservoir::ouvrir(){
    if (!this->autre_vanne->getOuverte()){
        int marge = 0;
        int partagee = partagee = ((this->reservoir1->getEtat()+this->reservoir2->getEtat())/2);
        if (this->reservoir1->getCapacite()>this->reservoir2->getCapacite()){
            if (partagee > this->reservoir2->getCapacite()){
                this->reservoir2->setEtat(80);
                marge = partagee - 80;
                partagee += marge;
                this->reservoir1->setEtat(partagee);
                TableauDeBord::setEtat2(80);
                if (this->identifiant == 112) TableauDeBord::setVT12(true);
                if (this->identifiant == 123) TableauDeBord::setVT23(true);
               if (this->reservoir1->getIdentifiant() == 1) TableauDeBord::setEtat1(partagee);
                else TableauDeBord::setEtat3(partagee);
            }else {
                this->reservoir1->setEtat(partagee);
                this->reservoir2->setEtat(partagee);
                if(this->reservoir1->getIdentifiant() == 1) TableauDeBord::setEtat1(partagee);
                else if(this->reservoir1->getIdentifiant() == 2)TableauDeBord::setEtat2(partagee);
                else TableauDeBord::setEtat3(partagee);
                if(this->reservoir2->getIdentifiant() == 1) TableauDeBord::setEtat1(partagee);
                else if(this->reservoir2->getIdentifiant() == 2)TableauDeBord::setEtat2(partagee);
                else TableauDeBord::setEtat3(partagee);
                if (this->identifiant == 112) TableauDeBord::setVT12(true);
                if (this->identifiant == 123) TableauDeBord::setVT23(true);
            }
        }
        else if (this->reservoir2->getCapacite()>this->reservoir1->getCapacite()){
            if (partagee > this->reservoir1->getCapacite()){
                this->reservoir1->setEtat(80);
                marge = partagee - 80;
                partagee += marge;
                this->reservoir2->setEtat(partagee);
                TableauDeBord::setEtat2(80);
                if (this->identifiant == 112) TableauDeBord::setVT12(true);
                if (this->identifiant == 123) TableauDeBord::setVT23(true);
               if (this->reservoir2->getIdentifiant() == 1) TableauDeBord::setEtat1(partagee);
                else TableauDeBord::setEtat3(partagee);
        }
            else {
                        this->reservoir1->setEtat(partagee);
                        this->reservoir2->setEtat(partagee);
                if(this->reservoir1->getIdentifiant() == 1) TableauDeBord::setEtat1(partagee);
                else if(this->reservoir1->getIdentifiant() == 2)TableauDeBord::setEtat2(partagee);
                else TableauDeBord::setEtat3(partagee);
                if(this->reservoir2->getIdentifiant() == 1) TableauDeBord::setEtat1(partagee);
                else if(this->reservoir2->getIdentifiant() == 2)TableauDeBord::setEtat2(partagee);
                else TableauDeBord::setEtat3(partagee);
                if (this->identifiant == 112) TableauDeBord::setVT12(true);
                if (this->identifiant == 123) TableauDeBord::setVT23(true);
                    }
    }
    if (this->reservoir1->getPanneVidange())
        this->reservoir1->setPanneVidange(false);
    else this->reservoir2->setPanneVidange(true);
    this->ouverte = true;
    }
    else if (this->autre_vanne->getOuverte()){
        reservoir* reservoir3 = nullptr;
            if ((this->reservoir1 != this->autre_vanne->reservoir1)
                    && (this->reservoir2 != this->autre_vanne->reservoir1))
                reservoir3 = this->autre_vanne->reservoir1;
            else if ((this->reservoir1 != this->autre_vanne->reservoir2)
                    && (this->reservoir2 != this->autre_vanne->reservoir2))
                reservoir3 = this->autre_vanne->reservoir2;
            int marge = 0;
            int partagee = partagee = ((this->reservoir1->getEtat()+this->reservoir2->getEtat()+reservoir3->getEtat())/3);
            if ((this->reservoir1->getCapacite()>this->reservoir2->getCapacite())
                    && (reservoir3->getCapacite()>this->reservoir2->getCapacite())){
                if (partagee > this->reservoir2->getCapacite()){
                    this->reservoir2->setEtat(80);
                    marge = (partagee - 80)/2;
                    partagee += marge;
                    this->reservoir1->setEtat(partagee);
                    reservoir3->setEtat(partagee);
                    TableauDeBord::setEtat2(80);
                   TableauDeBord::setEtat1(partagee);
                   TableauDeBord::setEtat3(partagee);
                   if (this->identifiant == 112) TableauDeBord::setVT12(true);
                   if (this->identifiant == 123) TableauDeBord::setVT23(true);
                }else {
                    this->reservoir1->setEtat(partagee);
                    this->reservoir2->setEtat(partagee);
                    reservoir3->setEtat(partagee);
                    TableauDeBord::setEtat2(partagee);
                   TableauDeBord::setEtat1(partagee);
                   TableauDeBord::setEtat3(partagee);
                   if (this->identifiant == 112) TableauDeBord::setVT12(true);
                   if (this->identifiant == 123) TableauDeBord::setVT23(true);
                }
            }
            if ((this->reservoir2->getCapacite()>this->reservoir1->getCapacite())
                    && (reservoir3->getCapacite()>this->reservoir1->getCapacite())){
                if (partagee > this->reservoir1->getCapacite()){
                    this->reservoir1->setEtat(80);
                    marge = (partagee - 80)/2;
                    partagee += marge;
                    this->reservoir2->setEtat(partagee);
                    reservoir3->setEtat(partagee);
                    TableauDeBord::setEtat2(80);
                   TableauDeBord::setEtat1(partagee);
                   TableauDeBord::setEtat3(partagee);
                   if (this->identifiant == 112) TableauDeBord::setVT12(true);
                   if (this->identifiant == 123) TableauDeBord::setVT23(true);

                }else {
                    this->reservoir1->setEtat(partagee);
                    this->reservoir2->setEtat(partagee);
                    reservoir3->setEtat(partagee);
                    TableauDeBord::setEtat2(partagee);
                   TableauDeBord::setEtat1(partagee);
                   TableauDeBord::setEtat3(partagee);
                   if (this->identifiant == 112) TableauDeBord::setVT12(true);
                   if (this->identifiant == 123) TableauDeBord::setVT23(true);
                }
            }
            if ((this->reservoir2->getCapacite()>reservoir3->getCapacite())
                    && (this->reservoir1->getCapacite()>reservoir3->getCapacite())){
                if (partagee > reservoir3->getCapacite()){
                    reservoir3->setEtat(80);
                    marge = (partagee - 80)/2;
                    partagee += marge;
                    this->reservoir1->setEtat(partagee);
                    this->reservoir2->setEtat(partagee);
                    TableauDeBord::setEtat2(80);
                   TableauDeBord::setEtat1(partagee);
                   TableauDeBord::setEtat3(partagee);
                   if (this->identifiant == 112) TableauDeBord::setVT12(true);
                   if (this->identifiant == 123) TableauDeBord::setVT23(true);

                }else {
                    this->reservoir1->setEtat(partagee);
                    this->reservoir2->setEtat(partagee);
                    reservoir3->setEtat(partagee);
                    TableauDeBord::setEtat2(partagee);
                   TableauDeBord::setEtat1(partagee);
                   TableauDeBord::setEtat3(partagee);
                   if (this->identifiant == 112) TableauDeBord::setVT12(true);
                   if (this->identifiant == 123) TableauDeBord::setVT23(true);
                }
            }
            if (this->reservoir1->getPanneVidange())
                this->reservoir1->setPanneVidange(false);
            else this->reservoir2->setPanneVidange(true);
            this->ouverte = true;

    }
}

void vanne_reservoir::fermer(){
    this->ouverte = false;
    if (this->identifiant == 112) TableauDeBord::setVT12(false);
    if (this->identifiant == 123) TableauDeBord::setVT23(false);
}

void vanne_reservoir::setAutre_vanne(vanne_reservoir* autre_vanne){
    this->autre_vanne = autre_vanne;
}
