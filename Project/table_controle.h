#ifndef TABLE_CONTROLE_H
#define TABLE_CONTROLE_H
#include <iostream>
#include "reservoir.h"
#include "moteur.h"
#include "vanne_reservoir.h"
#include "vanne_moteur.h"
#include "FenPrincipale.h"
#include "tb.h"
class table_controle : public QObject
{
    Q_OBJECT

    public:
    table_controle(reservoir* Tank1, reservoir* Tank2, reservoir* Tank3,
                   moteur* M1, moteur* M2, moteur* M3,  vanne_reservoir* VT12,
                    vanne_reservoir* VT23, vanne_moteur* V12, vanne_moteur* V13,
                    vanne_moteur* V23);
    void receiveVT12( int valeur );
    void receiveVT23( int valeur );
    void receiveV12( int valeur );
    void receiveV13( int valeur );
    void receiveV23( int valeur );
    void receiveP12( int valeur );
    void receiveP22( int valeur );
    void receiveP32( int valeur );
    void receivePP(int valeur);
    void receivePPS(int valeur);
    void receiveVM(int valeur);
    void receiveVR(int valeur);
    void receiveEQ(int valeur);
    void exercice1();
    void exercice2();
private :
    reservoir* Tk1;
    reservoir* Tk2;
    reservoir* Tk3;
    moteur* m1;
    moteur* m2;
    moteur* m3;
    vanne_reservoir* vt12;
    vanne_reservoir* vt23;
    vanne_moteur* v12;
    vanne_moteur* v13;
    vanne_moteur* v23;
    //tb* temp;
    tb* monObjet1;
    FenPrincipale* fenetre;
    public slots:
    void receive( int valeur );
};
#endif // TABLE_CONTROLE_H
