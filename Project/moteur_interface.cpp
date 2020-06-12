#include <QtGui>
#include "moteur_interface.h"
bool moteur_interface::marche1 = false;
bool moteur_interface::marche2 = false;
bool moteur_interface::marche3 = false;

moteur_interface::moteur_interface(QWidget* parent): QWidget(parent),pix("C:/Users/BUYMORE/Documents/interf/moteur.jpg")
    {

    }

void moteur_interface::paintEvent(QPaintEvent *)
   {
       QPainter p(this);
       //position du centre de l'image
       p.translate(width()/2,height()/2);

       //rotation à appliquer
       p.rotate(m_t.currentValue ()* 360);
       //translation de l'image pour faire correspondre le centre.
       p.translate(-pix.width()/2,-pix.height()/2);

       p.drawPixmap(0,0,pix);
   }

void moteur_interface::StopMoteur1(){
    if (marche1)
    m_t.stop();
}
void moteur_interface::StopMoteur2(){
    if (marche2)
    m_t.stop();
}
void moteur_interface::StopMoteur3(){
    if (marche3)
    m_t.stop();
}


void moteur_interface::DemarerMoteur1(){
    if (!marche1){
    connect(&m_t,SIGNAL(valueChanged(qreal)),this,SLOT(update()));
    m_t.start();
    m_t.setLoopCount(0);
    m_t.setDuration(2000);
    marche1 = true;
    }
}
void moteur_interface::DemarerMoteur2(){
    if (!marche2){
    connect(&m_t,SIGNAL(valueChanged(qreal)),this,SLOT(update()));
    m_t.start();
    m_t.setLoopCount(0);
    m_t.setDuration(2000);
    marche2 = true;
    }
}
void moteur_interface::DemarerMoteur3(){
    if (!marche3){
    connect(&m_t,SIGNAL(valueChanged(qreal)),this,SLOT(update()));
    m_t.start();
    m_t.setLoopCount(0);
    m_t.setDuration(2000);
    marche3 = true;
    }
}
