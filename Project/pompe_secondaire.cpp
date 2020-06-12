#include "TableauDeBord.h"
#include "pompe_secondaire.h"
pompe_secondaire::pompe_secondaire(int identifiant)
{
    this->identifiant = identifiant;
    this->en_marche = false;
    this->en_panne = false;
}

void pompe_secondaire::demarrer(){
    this->en_marche = true;
    if (this->identifiant == 12) TableauDeBord::setp12(true);
    if (this->identifiant == 122) TableauDeBord::setp122(true);
    if (this->identifiant == 123) TableauDeBord::setp123(true);
}

void pompe_secondaire::arreter(){
    this->en_marche = false;
    if (this->identifiant == 12) TableauDeBord::setp12(false);
    if (this->identifiant == 122) TableauDeBord::setp122(false);
    if (this->identifiant == 123) TableauDeBord::setp123(false);
    if (this->identifiant == 11) TableauDeBord::setp11(false);
    if (this->identifiant == 112) TableauDeBord::setp112(false);
    if (this->identifiant == 113) TableauDeBord::setp113(false);
}


