#ifndef POMPE_H
#define POMPE_H
class pompe
{
    public:
    pompe();
    bool getEn_marche();
    bool getEn_panne();
    void panne_pompe();

    protected:
    bool en_marche;
    bool en_panne;
    int identifiant;
};
#endif // POMPE_H
