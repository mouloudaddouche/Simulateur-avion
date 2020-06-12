#ifndef RESERVOIR_H
#define RESERVOIR_H

#include "pompe_primaire.h"
#include "pompe_secondaire.h"
#include "TableauDeBord.h"
class reservoir
{

    public:
    reservoir(int capacite, int identifiant, int id_pompe1, int id_pompe2);
    bool getEst_Vide();
    int getEtat();
    int getCapacite();
    bool getPanneVidange();
    void setPanneVidange(bool panne_vidange);
    void vidange();
    pompe_primaire* getPompe_primaire();
    pompe_secondaire* getPompe_secondaire();
    void panne_pompe_secondaire();
    void panne_pompe_primaire();
    void demarrer_pompe_secondaire();
    void arreter_pompe_secondaire();
    int getIdentifiant();
    void setEtat(int etat);

    private:
    pompe_primaire* p11;
    pompe_secondaire* p12;
    bool est_vide;
    int etat;
    int capacite;
    bool panne_vidange;
    int identifiant;
    int id_pompe1, id_pompe2;
};
#endif // RESERVOIR_H
