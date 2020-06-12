#ifndef VANNE_H
#define VANNE_H
#include "reservoir.h"
class vanne
{
    public:
    vanne(int ouverte, reservoir* reservoir1, reservoir* reservoir2);
    bool getOuverte();
    reservoir getReservoir1();
    reservoir getReservoir2();

    protected:
    bool ouverte;
    reservoir* reservoir1;
    reservoir* reservoir2;
};
#endif // VANNE_H
