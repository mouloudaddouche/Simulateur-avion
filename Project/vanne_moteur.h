#ifndef VANNE_MOTEUR_H
#define VANNE_MOTEUR_H
#include "moteur.h"
#include "vanne.h"
class vanne_moteur : public vanne
{
    public:
    vanne_moteur(int ouverte, reservoir* reservoir1, reservoir* reservoir2, moteur* m1, moteur* m2, int identifiant);
    void ouvrir();
    void fermer();
    moteur getM1();
    moteur getM2();

    private:
    moteur* m1;
    moteur* m2;
    int identifiant;

};
#endif // VANNE_MOTEUR_H
