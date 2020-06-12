#include "pompe_primaire.h"

pompe_primaire::pompe_primaire(int identifiant)
{
    this->identifiant = identifiant;
    this->en_marche = true;
    this->en_panne = false;
}
