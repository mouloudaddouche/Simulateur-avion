#include "vanne.h"

vanne::vanne(int ouverte, reservoir* reservoir1, reservoir* reservoir2)
{
    this->ouverte = ouverte;
    this->reservoir1 = reservoir1;
    this->reservoir2 = reservoir2;
}

bool vanne::getOuverte(){
    return this->ouverte;
}


reservoir vanne::getReservoir1(){
    return *this->reservoir1;
}
reservoir vanne::getReservoir2(){
    return *this->reservoir2;
}
