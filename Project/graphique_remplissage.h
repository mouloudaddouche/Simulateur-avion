#ifndef GRAPHIQUE_REMPLISSAGE_H
#define GRAPHIQUE_REMPLISSAGE_H
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QLabel>
#include <QFont>
#include "moteur_interface.h"
#include <QtGui>
#include <QProgressBar>
#include <QSlider>
#include <QPushButton>

class graphique_remplissage : public QWidget // On hérite de QWidget (IMPORTANT)
{
 Q_OBJECT

public:
    graphique_remplissage();
    virtual void paintEvent(QPaintEvent *event);
    //---------------------------------------
    void DessinerTank1(QPainter* P);
    void DessinerTank2(QPainter* P);
    void DessinerTank3(QPainter* P);
    //---------------------------------------
    void ViderTank(QPainter* P,int NumTank);
    void RemplirTank(QPainter* P,int NumTank,int prcn);
    //------------------------------------------
    void VanneVT23(QPainter* P,int etat);
    void VanneVT12(QPainter* P,int etat);
    void VanneV12(QPainter* P,int etat);
    void VanneV13(QPainter* P,int etat);
    void VanneV23(QPainter* P,int etat);
    //-----------------------------------------
    void SchemaTuyau(QPainter* P);
    void debut_program();
    void setIZI(bool izi);

private:
   moteur_interface *M1,*M2,*M3;
     QLabel *label1,*label2,*label3,*label4,*label5,*label6,*label7,*label8,*label9,*label10,*label11,*label12,*label13,*label14,*label15,*label16,*label17;
     QPainterPath *path1,*path2,*path3,*path4,*path5,*path6,*path7,*path8,*path9,*path10,*path11,*path12,*path13,*path14,*path15,*path16,*path17,
     *VT12,*VT23,*V12,*V13,*V23;

     QPainter* painter;
     bool izi;
};
#endif // GRAPHIQUE_REMPLISSAGE_H
