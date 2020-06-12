#include "tb.h"
#include <iostream>
#include <QCoreApplication>

tb::tb(int num,QWidget *parent)
   : QWidget(parent), pic("C:/Users/BUYMORE/Documents/TableauDeBord.png")
{
    this->num = 0;

       this->bVT12 = false;
       this->bVT23 = false;
       this->bP12 = false;
       this->bP22 = false;
       this->bP32 = false;
       this->bV12 = false;
       this->bV13 = false;
       this->bV23 = false;

       PP = false;
       PPS = false;
       VM = false;
       VR = false;
       EQ = false;

       setFixedSize(570,450);
       VT23 = new QPushButton(this);
       VT23->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/VT23.png); border-style: solid;border-width:1px;border-radius:34px;border-color: black;max-width:68px;max-height:68px;min-width:68px;min-height:68px");
       VT23->setGeometry(QRect(QPoint(3, 58),QSize(10, 10)));


       VT12 = new QPushButton(this);
       VT12->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/VT12.png); border-style: solid;border-width:2px;border-radius:41px;border-color: black;max-width:82px;max-height:82px;min-width:82px;min-height:82px");
       VT12->setGeometry(QRect(QPoint(92, 30),QSize(10, 10)));

       P12 = new QPushButton(this);
       P12->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/P12.png); border-style: solid;border-width:2px;border-radius:41px;border-color: black;max-width:82px;max-height:82px;min-width:82px;min-height:82px");
       P12->setGeometry(QRect(QPoint(195, 25),QSize(10, 10)));


       P22 = new QPushButton(this);
       P22->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/P22.png); border-style: solid;border-width:2px;border-radius:41px;border-color: black;max-width:82px;max-height:82px;min-width:82px;min-height:82px");
       P22->setGeometry(QRect(QPoint(289, 25),QSize(10, 10)));


       P32 = new QPushButton(this);
       P32->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/P32.png); border-style: solid;border-width:1px;border-radius:38px;border-color: black;max-width:76px;max-height:76px;min-width:76px;min-height:76px");
       P32->setGeometry(QRect(QPoint(2, 143),QSize(10, 10)));


       V12 = new QPushButton("V12", this);
       V12->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/V12.png); border-style: solid;border-width:1px;border-radius:41px;border-color: black;max-width:82px;max-height:82px;min-width:82px;min-height:82px");
       V12->setGeometry(QRect(QPoint(98, 121),QSize(10, 10)));

       V13 = new QPushButton("V13", this);
       V13->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/V13.png); border-style: solid;border-width:1px;border-radius:41px;border-color: black;max-width:82px;max-height:82px;min-width:82px;min-height:82px");
       V13->setGeometry(QRect(QPoint(198, 112),QSize(10, 10)));

       V23 = new QPushButton("V23", this);
       V23->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/V23.png); border-style: solid;border-width:1px;border-radius:41px;border-color: black;max-width:82px;max-height:82px;min-width:82px;min-height:82px");
       V23->setGeometry(QRect(QPoint(292, 115),QSize(10, 10)));

}
tb::tb() : pic("C:/Users/BUYMORE/Documents/TableauDeBord.png"){
    this->num = 0;
    setFixedSize(570,450);
    this->bVT12 = false;
    this->bVT23 = false;
    this->bP12 = false;
    this->bP22 = false;
    this->bP32 = false;
    this->bV12 = false;
    this->bV13 = false;
    this->bV23 = false;


    PP = false;
    PPS = false;
    VM = false;
    VR = false;
    EQ = false;
       VT23 = new QPushButton(this);
       VT23->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/VT23.png); border-style: solid;border-width:1px;border-radius:34px;border-color: black;max-width:68px;max-height:68px;min-width:68px;min-height:68px");
       VT23->setGeometry(QRect(QPoint(3, 58),QSize(10, 10)));
       connect(VT23, SIGNAL (clicked()), this, SLOT (handleButtonVT23()));

       VT12 = new QPushButton(this);
       VT12->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/VT12.png); border-style: solid;border-width:2px;border-radius:41px;border-color: black;max-width:82px;max-height:82px;min-width:82px;min-height:82px");
       VT12->setGeometry(QRect(QPoint(92, 30),QSize(10, 10)));
       connect(VT12, SIGNAL (clicked()), this, SLOT (handleButtonVT12()));

       P12 = new QPushButton(this);
       P12->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/P12.png); border-style: solid;border-width:2px;border-radius:41px;border-color: black;max-width:82px;max-height:82px;min-width:82px;min-height:82px");
       P12->setGeometry(QRect(QPoint(195, 25),QSize(10, 10)));
       connect(P12, SIGNAL (clicked()), this, SLOT (handleButtonP12()));


       P22 = new QPushButton(this);
       P22->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/P22.png); border-style: solid;border-width:2px;border-radius:41px;border-color: black;max-width:82px;max-height:82px;min-width:82px;min-height:82px");
       P22->setGeometry(QRect(QPoint(289, 25),QSize(10, 10)));
       connect(P22, SIGNAL (clicked()), this, SLOT (handleButtonP22()));

       P32 = new QPushButton(this);
       P32->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/P32.png); border-style: solid;border-width:1px;border-radius:38px;border-color: black;max-width:76px;max-height:76px;min-width:76px;min-height:76px");
       P32->setGeometry(QRect(QPoint(2, 143),QSize(10, 10)));
       connect(P32, SIGNAL (clicked()), this, SLOT (handleButtonP32()));


       V12 = new QPushButton("V12", this);
       V12->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/V12.png); border-style: solid;border-width:1px;border-radius:41px;border-color: black;max-width:82px;max-height:82px;min-width:82px;min-height:82px");
       V12->setGeometry(QRect(QPoint(98, 121),QSize(10, 10)));
       connect(V12, SIGNAL (clicked()), this, SLOT (handleButtonV12()));


       V13 = new QPushButton("V13", this);
       V13->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/V13.png); border-style: solid;border-width:1px;border-radius:41px;border-color: black;max-width:82px;max-height:82px;min-width:82px;min-height:82px");
       V13->setGeometry(QRect(QPoint(198, 112),QSize(10, 10)));
       connect(V13, SIGNAL (clicked()), this, SLOT (handleButtonV13()));


       V23 = new QPushButton("V23", this);
       V23->setStyleSheet("background-image: url(C:/Users/BUYMORE/Documents/V23.png); border-style: solid;border-width:1px;border-radius:41px;border-color: black;max-width:82px;max-height:82px;min-width:82px;min-height:82px");
       V23->setGeometry(QRect(QPoint(292, 115),QSize(10, 10)));
       connect(V23, SIGNAL (clicked()), this, SLOT (handleButtonV23()));



       this->panne_pompe = new QPushButton("Panne Pompe", this);
       panne_pompe->setGeometry(QRect(QPoint(380, 10),
       QSize(200, 50)));
       connect(panne_pompe, SIGNAL (clicked()), this, SLOT (handleButtonPP()));
       //this->panne_pompe->hide();

       panne_p_s = new QPushButton("Panne S", this);
       panne_p_s->setGeometry(QRect(QPoint(380, 80),
       QSize(200, 50)));
       connect(panne_p_s, SIGNAL (clicked()), this, SLOT (handleButtonPPS()));
       //this->panne_p_s->hide();

       ouverture_v_m = new QPushButton("vanne moteur", this);
       ouverture_v_m->setGeometry(QRect(QPoint(380, 150),
       QSize(200, 50)));
       connect(ouverture_v_m, SIGNAL (clicked()), this, SLOT (handleButtonVM()));
//       this->ouverture_v_m->hide();

       vidange1 = new QPushButton("vidange un reservoir", this);
       vidange1->setGeometry(QRect(QPoint(380, 220),
       QSize(200, 50)));
       connect(vidange1, SIGNAL (clicked()), this, SLOT (handleButtonVR()));
  //     this->vidange1->hide();

       equilibre = new QPushButton("equilibre", this);
       equilibre->setGeometry(QRect(QPoint(380, 290),
       QSize(200, 50)));
       connect(equilibre, SIGNAL (clicked()), this, SLOT (handleButtonEQ()));
    //   this->equilibre->hide();
}


void tb::emettre()
{
    if (this->bVT12) {
        this->num = 1;
        emit send(this->num);
        this->num = 0;
        this->bVT12 = false;
    }
    else if (this->bVT23){
        this->num = 2;
        emit send(this->num);
        this->num = 0;
        this->bVT23 = false;
    }
    else if (this->bV12){
        this->num = 3;
        emit send(this->num);
        this->num = 0;
        this->bV12 = false;
    }
    else if (this->bV13){
        this->num = 4;
        emit send(this->num);
        this->num = 0;
        this->bV13 = false;
    }
    else if (this->bV23){
        this->num = 5;
        emit send(this->num);
        this->num = 0;
        this->bV23 = false;
    }
    else if (this->bP12){
        this->num = 6;
        emit send(this->num);
        this->num = 0;
        this->bP12 = false;
    }
    else if (this->bP22){
        this->num = 7;
        emit send(this->num);
        this->num = 0;
        this->bP22 = false;
    }
    else if (this->bP32){
        this->num = 8;
        emit send(this->num);
        this->num = 0;
        this->bP32 = false;
    }
    else if (this->PP){
        this->num = 9;
        emit send(this->num);
        this->num = 0;
        this->PP = false;
    }
    else if (this->PPS){
        this->num = 10;
        emit send(this->num);
        this->num = 0;
        this->PPS = false;
    }
    else if (this->VM){
        this->num = 11;
        emit send(this->num);
        this->num = 0;
        this->VM = false;
    }
    else if (this->VR){
        this->num = 12;
        emit send(this->num);
        this->num = 0;
        this->VR = false;
    }
    else if (this->EQ){
        this->num = 13;
        emit send(this->num);
        this->num = 0;
        this->EQ = false;
    }
 // envoie le signal send avec la valeur de la variable numero
}

void tb::handleButtonVT12()
{
    bVT12 = true;
    emettre();
}
void tb::handleButtonVT23(){
    bVT23 = true;
    emettre();

}
void tb::handleButtonV12(){
    bV12 = true;
    emettre();

}
void tb::handleButtonV13(){
    bV13 = true;
    emettre();

}
void tb::handleButtonV23(){
    bV23 = true;
    emettre();

}
void tb::handleButtonP12(){
    bP12 = true;
    emettre();

}
void tb::handleButtonP22(){
    bP22 = true;
    emettre();

}
void tb::handleButtonP32(){
    bP32 = true;
    emettre();

}
void tb::handleButtonPP(){
    PP = true;
    emettre();
}
void tb::handleButtonPPS(){
    PPS = true;
    emettre();
}
void tb::handleButtonVM(){
    VM = true;
    emettre();
}
void tb::handleButtonVR(){
    VR = true;
    emettre();
}
void tb::handleButtonEQ(){
    EQ = true;
    emettre();
}
void tb::paintEvent(QPaintEvent *){
QPainter p(this);
QFont font1;
font1.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
font1.setPixelSize(18); // this for setting font size
font1.setFamily("arial");

label1 = new QLabel(this);
label1->setStyleSheet("QLabel {color : white; }");
label1->setFont(font1);
label1->setText("VT23");
label1->move(14,21);
label1->show();

label2 = new QLabel(this);
label2->setStyleSheet("QLabel {color : white; }");
label2->setFont(font1);
label2->setText("VT12");
label2->move(111,1);
label2->show();

label3 = new QLabel(this);
label3->setStyleSheet("QLabel {color : white; }");
label3->setFont(font1);
label3->setText("P12");
label3->move(220,1);
label3->show();

label4 = new QLabel(this);
label4->setStyleSheet("QLabel {color : white; }");
label4->setFont(font1);
label4->setText("P22");
label4->move(316,1);
label4->show();

label5 = new QLabel(this);
label5->setStyleSheet("QLabel {color : white; }");
label5->setFont(font1);
label5->setText("P32");
label5->move(25,127);
label5->show();

label6 = new QLabel(this);
label6->setStyleSheet("QLabel {color : white; }");
label6->setFont(font1);
label6->setText("V12");
label6->move(123,106);
label6->show();

label7 = new QLabel(this);
label7->setStyleSheet("QLabel {color : white; }");
label7->setFont(font1);
label7->setText("V13");
label7->move(220,100);
label7->show();

label8 = new QLabel(this);
label8->setStyleSheet("QLabel {color : white; }");
label8->setFont(font1);
label8->setText("V23");
label8->move(316,103);
label8->show();


p.drawPixmap(0,0,pic);
}

bool tb::getVT12(){
    return this->bVT12;
}
bool tb::getVT23(){
    return this->bVT23;
}
bool tb::getV12(){
    return this->bV12;
}
bool tb::getV13(){
    return this->bV13;
}
bool tb::getV23(){
    return this->bV23;
}
bool tb::getP12(){
    return this->P12;
}
bool tb::getP22(){
    return this->P22;
}
bool tb::getP32(){
    return this->P32;
}
void tb::setNum(int num){
    this->num = num;
}
