#ifndef POMPE_SECONDAIRE_H
#define POMPE_SECONDAIRE_H

#include "pompe.h"

class pompe_secondaire : public pompe
{
    public:
    pompe_secondaire(int identifiant);
    void demarrer();
    void arreter();
};

#endif // POMPE_SECONDAIRE_H
