#ifndef MOTEUR_H
#define MOTEUR_H

#include "reservoir.h"

class moteur
{
    public:
    moteur(reservoir* provenance, int identifiant);
    bool getEn_marche();
    void panne_pompeP();
    void panne_pompeS();
    void demarrer_pompe_s();
    void arreter_pompe_s();
    reservoir* getProvenance();
    void setProvenance(reservoir* provenance);
    void setEn_marche(bool en_marche);
//    void setV1(vanne* v1);
  //  void setV2(vanne* v2);
    /*void ouvrir_v1();
    void ouvrir_v2();
    void fermer_v1();
    void fermer_v2();*/
    int getIdentifiant();
    private:
    int identifiant;
    bool en_marche;
    reservoir* provenance;
};
#endif // MOTEUR_H
