#ifndef VANNE_RESERVOIR_H
#define VANNE_RESERVOIR_H
#include "vanne.h"
class vanne_reservoir : public vanne
{
    public:
    vanne_reservoir(int ouverte, reservoir* reservoir1, reservoir* reservoir2, int identifiant);
    void ouvrir();
    void fermer();
    void setAutre_vanne(vanne_reservoir* autre_vanne);
    private :
    vanne_reservoir* autre_vanne;
    int identifiant;
};
#endif // VANNE_RESERVOIR_H
