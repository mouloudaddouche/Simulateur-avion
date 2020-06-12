#ifndef TABLEAUDEBORD_H
#define TABLEAUDEBORD_H
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

class TableauDeBord : public QWidget // On hérite de QWidget (IMPORTANT)
{
 Q_OBJECT


public:

    TableauDeBord();
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
    static void setEtat1(int etat);
    static void setEtat2(int etat);
    static void setEtat3(int etat);
    static int convert(int x);
    static void demarrer_moteur();
    static void setN1(bool n);
    static void setN2(bool n);
    static void setN3(bool n);
    static void setp11(bool n);
    static void setp12(bool n);
    static void setp112(bool n);
    static void setp122(bool n);
    static void setp113(bool n);
    static void setp123(bool n);
    static void setVT12(bool n);
    static void setVT23(bool n);
    static void setV12(bool n);
    static void setV23(bool n);
    static void setV13(bool n);
moteur_interface *M1,*M2,*M3;
private:

     QLabel *label1,*label2,*label3,*label4,*label5,*label6,*label7,*label8,*label9,*label10,*label11,*label12,*label13,*label14,*label15,*label16,*label17;
     QPainterPath *path1,*path2,*path3,*path4,*path5,*path6,*path7,*path8,*path9,*path10,*path11,*path12,*path13,*path14,*path15,*path16,*path17,
     *VT12,*VT23,*V12,*V13,*V23;
     QPainter* painter;
     static int etat1;
     static int etat2;
     static int etat3;
     static bool n1;
     static bool n2;
     static bool n3;
     static bool p11;
     static bool p12;
     static bool p112;
     static bool p122;
     static bool p113;
     static bool p123;
     static bool VaT12;
     static bool VaT23;
     static bool Va12;
     static bool Va23;
     static bool Va13;
};
#endif // TABLEAUDEBORD_H
