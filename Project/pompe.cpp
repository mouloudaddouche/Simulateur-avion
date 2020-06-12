#include "pompe.h"
#include "TableauDeBord.h"
pompe::pompe()
{
}

bool pompe::getEn_marche(){
    return this->en_marche;
}

bool pompe::getEn_panne(){
    return this->en_panne;
}

void pompe::panne_pompe(){
    this->en_panne = true;
    this->en_marche = false;
    if (this->identifiant == 12) TableauDeBord::setp12(false);
    if (this->identifiant == 122) TableauDeBord::setp122(false);
    if (this->identifiant == 123) TableauDeBord::setp123(false);
    if (this->identifiant == 11) TableauDeBord::setp11(false);
    if (this->identifiant == 112) TableauDeBord::setp112(false);
    if (this->identifiant == 113) TableauDeBord::setp113(false);
}
