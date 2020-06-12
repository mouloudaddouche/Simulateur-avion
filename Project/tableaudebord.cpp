#include "TableauDeBord.h"
#include "iostream"
bool TableauDeBord::n1 = false;
bool TableauDeBord::n2 = false;
bool TableauDeBord::n3 = false;
int TableauDeBord::etat1 = 100;
int TableauDeBord::etat2 = 100;
int TableauDeBord::etat3 = 100;
bool TableauDeBord::p11 = true;
bool TableauDeBord::p12 = false;
bool TableauDeBord::p112 = true;
bool TableauDeBord::p122 = false;
bool TableauDeBord::p113 = true;
bool TableauDeBord::p123 = false;
bool TableauDeBord::VaT12 = false;
bool TableauDeBord::VaT23 = false;
bool TableauDeBord::Va12 = false;
bool TableauDeBord::Va23 = false;
bool TableauDeBord::Va13 = false;
TableauDeBord::TableauDeBord(): QWidget()
{
    setFixedSize(1100,1080);
    //move(0,0);
    M1=new moteur_interface(this);
    M2=new moteur_interface(this);
    M3=new moteur_interface(this);
}

void TableauDeBord::debut_program(){
    this->painter = new QPainter(this);
    QPen pen(Qt::black, 2);
    QProgressBar *Tuyau1,*Tuyau2;

   //M1,M2,M3
   M1->setGeometry(70, 750, 200, 220);
   M2->setGeometry(440, 750, 200, 220);
   M3->setGeometry(810, 750, 200, 220);
   if (n1) { M1->marche1 = false;M1->DemarerMoteur1();} else { M1->marche1 = true;M1->StopMoteur1();}
   if (n2) M2->DemarerMoteur2(); else M2->StopMoteur2();
   if (n3) M3->DemarerMoteur3(); else M3->StopMoteur3();

   Tuyau1 = new QProgressBar(this);
   Tuyau1->setGeometry(641, 260, 168, 40);
   Tuyau1->setTextVisible(false);
   Tuyau1->setMaximum(100);
   Tuyau1->setMinimum(0);
   if (VaT23)Tuyau1->setValue(100);
   Tuyau1->showNormal();

   Tuyau2 = new QProgressBar(this);
   Tuyau2->setGeometry(271, 260, 178, 40);
   Tuyau2->setMaximum(100);
   Tuyau2->setTextVisible(false);
   Tuyau2->setMinimum(0);
   if (VaT12)Tuyau2->setValue(100);
   Tuyau2->show();
   DessinerTank1(painter);
   DessinerTank2(painter);
   DessinerTank3(painter);
   painter->fillRect(80,480,190,4.2*-TableauDeBord::etat1,Qt::red);
   painter->fillRect(810,480,190,4.2*-TableauDeBord::etat3,Qt::yellow);
   painter->fillRect(450,480,190,3.6*-TableauDeBord::etat2,Qt::green);

   //RemplirTank(painter,2,100);
   //RemplirTank(&painter,1,30);
   //RemplirTank(&painter,3,50);
   if (VaT12) VanneVT12(painter,1);
   else VanneVT12(painter,0);
   if (VaT23) VanneVT23(painter,1);
   else VanneVT23(painter,0);
   if (Va12) VanneV12(painter,1);
   else VanneV12(painter,0);
   if (Va13) VanneV13(painter,1);
   else VanneV13(painter,0);
   if (Va23) VanneV23(painter,1);
   else VanneV23(painter,0);
   SchemaTuyau(this->painter);

   path10=new QPainterPath();
   path10->addEllipse(115.0, 415.0, 60.0, 65.0); //P11
   painter->setPen(pen);
   painter->fillPath(*path10, Qt::black);
   painter->drawPath(*path10);

   path11=new QPainterPath();
   path11->addEllipse(180.0, 415.0, 60.0, 65.0); //P12
   painter->setPen(pen);
   painter->fillPath(*path11, Qt::black);
   painter->drawPath(*path11);

   path7=new QPainterPath();
   path7->addRoundedRect(QRectF(110, 410, 140, 70), 10, 10);
   painter->setPen(pen);
   painter->drawPath(*path7);

   path12=new QPainterPath();
   path12->addEllipse(485.0, 415.0, 60.0, 65.0); //P21
   painter->setPen(pen);
   painter->fillPath(*path12, Qt::black);
   painter->drawPath(*path12);

   path13=new QPainterPath();
   path13->addEllipse(550.0, 415.0, 60.0, 65.0); //P22
   painter->setPen(pen);
   painter->fillPath(*path13, Qt::black);
   painter->drawPath(*path13);

   path16=new QPainterPath();
   path16->addRoundedRect(QRectF(480, 410, 140, 70), 10, 10);
   painter->setPen(pen);
   painter->drawPath(*path16);

   path14=new QPainterPath();
   path14->addEllipse(850.0, 415.0, 60.0, 65.0); //P31
   painter->setPen(pen);
   painter->fillPath(*path14, Qt::black);
   painter->drawPath(*path14);


   path15=new QPainterPath();
   path15->addEllipse(915.0, 415.0, 60.0, 65.0); //P32
   painter->setPen(pen);
   painter->fillPath(*path15, Qt::black);
   painter->drawPath(*path15);

   path9=new QPainterPath();
   path9->addRoundedRect(QRectF(840, 410, 140, 70), 10, 10);
   painter->setPen(pen);
   painter->drawPath(*path9);

}
void TableauDeBord::paintEvent(QPaintEvent *event){
    debut_program();
}

void TableauDeBord::DessinerTank1(QPainter* P){

    QFont font1,font2; //Declaration Des Ecriture

    font1.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font1.setPixelSize(20); // this for setting font size
    font1.setFamily("Times new roman");

    font2.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font2.setPixelSize(30); // this for setting font size
    font2.setFamily("arial");

    QPen pen(Qt::black, 2); // Declaration Du Pen


label1 = new QLabel(this);
if (p11)label1->setStyleSheet("QLabel {color : green; }");
else label1->setStyleSheet("QLabel {color : red; }");
label1->setFont(font1);
label1->setText("P11");
label1->move(130,430);
label1->show();

label2 = new QLabel(this);
if (p12) label2->setStyleSheet("QLabel {color : green; }");
else label2->setStyleSheet("QLabel {color : red; }");
label2->setFont(font1);
label2->setText("P12");
label2->move(195,430);
label2->show();

label3 = new QLabel(this);
label3->setStyleSheet("QLabel {color : black; }");
label3->setFont(font2);
label3->setText("Tank1");
label3->move(145,300);
label3->show();

path1=new QPainterPath();
path1->addRoundedRect(QRectF(80, 60, 190, 420), 10, 10);
P->setPen(pen);
P->drawPath(*path1);



}

void TableauDeBord::DessinerTank2(QPainter* P){

    QFont font1,font2; //Declaration Des Ecriture

    font1.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font1.setPixelSize(20); // this for setting font size
    font1.setFamily("Times new roman");

    font2.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font2.setPixelSize(30); // this for setting font size
    font2.setFamily("arial");

    QPen pen(Qt::black, 2); // Declaration Du Pen
    label4 = new QLabel(this);
    if (p112) label4->setStyleSheet("QLabel {color : green; }");
    else label4->setStyleSheet("QLabel {color : red; }");
    label4->setFont(font1);
    label4->setText("P21");
    label4->move(500,435);
    label4->show();

    label5 = new QLabel(this);
    if (p122) label5->setStyleSheet("QLabel {color : green; }");
    else label5->setStyleSheet("QLabel {color : red; }");
    label5->setFont(font1);
    label5->setText("P22");
    label5->move(565,435);
    label5->show();

    label6 = new QLabel(this);
    label6->setStyleSheet("QLabel {color : black; }");
    label6->setFont(font2);
    label6->setText("Tank2");
    label6->move(505,300);
    label6->show();




   path2=new QPainterPath();
   path2->addRoundedRect(QRectF(450, 120, 190, 360), 10, 10);
   P->setPen(pen);
   P->drawPath(*path2);




}

void TableauDeBord::DessinerTank3(QPainter* P){

    QFont font1,font2; //Declaration Des Ecriture

    font1.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font1.setPixelSize(20); // this for setting font size
    font1.setFamily("Times new roman");

    font2.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font2.setPixelSize(30); // this for setting font size
    font2.setFamily("arial");

    QPen pen(Qt::black, 2); // Declaration Du Pen

    label7 = new QLabel(this);
    if (p113) label7->setStyleSheet("QLabel {color : green; }");
    else label7->setStyleSheet("QLabel {color : red; }");
    label7->setFont(font1);
    label7->setText("P31");
    label7->move(865,430);
    label7->show();


    label8 = new QLabel(this);
    if (p123)label8->setStyleSheet("QLabel {color : green; }");
    else label8->setStyleSheet("QLabel {color : red; }");
    label8->setFont(font1);
    label8->setText("P32");
    label8->move(930,430);
    label8->show();

    label9 = new QLabel(this);
    label9->setStyleSheet("QLabel {color : black; }");
    label9->setFont(font2);
    label9->setText("Tank3");
    label9->move(855,300);
    label9->show();


    path8=new QPainterPath();
    path8->addRoundedRect(QRectF(810, 60, 190, 420), 10, 10);
    P->setPen(pen);
    P->drawPath(*path8);


}


void TableauDeBord::ViderTank(QPainter* P,int numTank){
    if (numTank==1) P->eraseRect(path1->boundingRect());
    else if (numTank==2) P->eraseRect(path2->boundingRect());
    else P->eraseRect(path8->boundingRect());

    P->setRenderHint(QPainter::Antialiasing);

}

void TableauDeBord::RemplirTank(QPainter* P,int NumTank,int prcn){

    QPen pen(Qt::black, 2); // Declaration Du Pen
    ViderTank(P,NumTank);
    if(NumTank==1){
        P->fillRect(80,480,190,4.2*-prcn,Qt::red);
        P->drawPath(*path1);

        path10=new QPainterPath();
        path10->addEllipse(115.0, 415.0, 60.0, 65.0); //P11
        P->setPen(pen);
        P->fillPath(*path10, Qt::black);
        P->drawPath(*path10);

        path11=new QPainterPath();
        path11->addEllipse(180.0, 415.0, 60.0, 65.0); //P12
        P->setPen(pen);
        P->fillPath(*path11, Qt::black);
        P->drawPath(*path11);

        path7=new QPainterPath();
        path7->addRoundedRect(QRectF(110, 410, 140, 70), 10, 10);
        P->setPen(pen);
        P->drawPath(*path7);
        }

    else if (NumTank==2){

        P->fillRect(450,480,190,3.6*-prcn,Qt::green);
        P->drawPath(*path2);

        path12=new QPainterPath();
        path12->addEllipse(485.0, 415.0, 60.0, 65.0); //P21
        P->setPen(pen);
        P->fillPath(*path12, Qt::black);
        P->drawPath(*path12);

        path13=new QPainterPath();
        path13->addEllipse(550.0, 415.0, 60.0, 65.0); //P22
        P->setPen(pen);
        P->fillPath(*path13, Qt::black);
        P->drawPath(*path13);

        path16=new QPainterPath();
        path16->addRoundedRect(QRectF(480, 410, 140, 70), 10, 10);
        P->setPen(pen);
        P->drawPath(*path16);
    }

    else {

        P->fillRect(810,480,190,4.2*-prcn,Qt::yellow);
        P->drawPath(*path8);

        path14=new QPainterPath();
        path14->addEllipse(850.0, 415.0, 60.0, 65.0); //P31
        P->setPen(pen);
        P->fillPath(*path14, Qt::black);
        P->drawPath(*path14);


        path15=new QPainterPath();
        path15->addEllipse(915.0, 415.0, 60.0, 65.0); //P32
        P->setPen(pen);
        P->fillPath(*path15, Qt::black);
        P->drawPath(*path15);

        path9=new QPainterPath();
        path9->addRoundedRect(QRectF(840, 410, 140, 70), 10, 10);
        P->setPen(pen);
        P->drawPath(*path9);

    }
}

void TableauDeBord::VanneVT23(QPainter* P,int etat){
    QPen pen1(Qt::black, 2);
    QPen pen2(Qt::black, 6);
    VT23=new QPainterPath();
    VT23->addEllipse(690.0, 194.0, 60.0, 65.0);
    P->setPen(pen2);
    if(etat==0){
        P->fillPath(*VT23, Qt::red);
         P->drawLine(720,197,720,260);}
    else{ P->fillPath(*VT23, Qt::green);
          P->drawLine(692,227,748,227);}
     P->setPen(pen1);
    P->drawPath(*VT23);
}

void TableauDeBord::VanneVT12(QPainter* P,int etat){
    QPen pen1(Qt::black, 2);
    QPen pen2(Qt::black, 6);
    VT12=new QPainterPath();
    VT12->addEllipse(330.0, 194.0, 60.0, 65.0);
    P->setPen(pen2);
    if(etat==0){
        P->fillPath(*VT12, Qt::red);
        P->drawLine(362,197,362,260);}
    else{
        P->fillPath(*VT12, Qt::green);
        P->drawLine(332,227,388,227);}
     P->setPen(pen1);
     P->drawPath(*VT12);
}

void TableauDeBord::VanneV12(QPainter* P,int etat){
    QPen pen1(Qt::black, 2);
    QPen pen2(Qt::black, 6);
    V12=new QPainterPath();
    V12->addEllipse(330.0, 600.0, 60.0, 65.0);
    P->setPen(pen2);
    if(etat==0){
        P->fillPath(*V12, Qt::red);
        P->drawLine(362,602,362,662);}
    else{
        P->fillPath(*V12, Qt::green);
        P->drawLine(332,632,388,632);}
     P->setPen(pen1);
     P->drawPath(*V12);
}

void TableauDeBord::VanneV13(QPainter* P,int etat){
    QPen pen1(Qt::black, 2);
    QPen pen2(Qt::black, 6);
    V13=new QPainterPath();
    V13->addEllipse(630.0, 514.0, 60.0, 65.0);
    P->setPen(pen2);
    if(etat==0){
        P->fillPath(*V13, Qt::red);
        P->drawLine(660,517,660,577);}
    else{
        P->fillPath(*V13, Qt::green);
        P->drawLine(632,546,688,546);}
     P->setPen(pen1);
     P->drawPath(*V13);
}

void TableauDeBord::VanneV23(QPainter* P,int etat){
    QPen pen1(Qt::black, 2);
    QPen pen2(Qt::black, 6);
    V23=new QPainterPath();
    V23->addEllipse(690.0, 640.0, 60.0, 65.0);
    P->setPen(pen2);
    if(etat==0){
        P->fillPath(*V23, Qt::red);
        P->drawLine(722,642,722,702);}
    else{
        P->fillPath(*V23, Qt::green);
        P->drawLine(692,672,746,672);}
     P->setPen(pen1);
     P->drawPath(*V23);
}

void TableauDeBord::SchemaTuyau(QPainter* P){
    QPen pen(Qt::black,3);
    QFont font1;
    font1.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font1.setPixelSize(20); // this for setting font size
    font1.setFamily("Times new roman");
    P->setPen(pen);
    P->drawLine(170,480,170,632);
    P->drawLine(140,580,170,580);
    P->drawLine(140,580,140,748);
    P->drawLine(170,632,327,632);
    P->drawLine(390,632,540,632);
    P->drawLine(540,482,540,748);
    P->drawLine(692,545,955,545);
    P->drawLine(170,545,627,545);
    P->drawLine(540,672,687,672);
    P->drawLine(752,672,907,672);
    P->drawLine(910,480,910,672);
    P->drawLine(955,545,955,748);
    P->drawLine(910,615,955,615);

    label10 = new QLabel(this);
    label10->setStyleSheet("QLabel {color : black; }");
    label10->setFont(font1);
    label10->setText("VT12");
    label10->move(335,167);
    label10->show();

    label11 = new QLabel(this);
    label11->setStyleSheet("QLabel {color : black; }");
    label11->setFont(font1);
    label11->setText("VT23");
    label11->move(700,167);
    label11->show();

    label12 = new QLabel(this);
    label12->setStyleSheet("QLabel {color : black; }");
    label12->setFont(font1);
    label12->setText("V12");
    label12->move(342,574);
    label12->show();

    label13 = new QLabel(this);
    label13->setStyleSheet("QLabel {color : black; }");
    label13->setFont(font1);
    label13->setText("V13");
    label13->move(643,489);
    label13->show();

    label14 = new QLabel(this);
    label14->setStyleSheet("QLabel {color : black; }");
    label14->setFont(font1);
    label14->setText("V23");
    label14->move(703,612);
    label14->show();

    label15 = new QLabel(this);
    label15->setStyleSheet("QLabel {color : black; }");
    label15->setFont(font1);
    label15->setText("M1");
    label15->move(160,722);
    label15->show();

    label16 = new QLabel(this);
    label16->setStyleSheet("QLabel {color : black; }");
    label16->setFont(font1);
    label16->setText("M2");
    label16->move(490,722);
    label16->show();

    label17 = new QLabel(this);
    label17->setStyleSheet("QLabel {color : black; }");
    label17->setFont(font1);
    label17->setText("M3");
    label17->move(900,722);
    label17->show();
}



void TableauDeBord::setEtat1(int etat){
    TableauDeBord::etat1 = etat;
}
void TableauDeBord::setEtat2(int etat){
  TableauDeBord::etat2 = convert(etat);
}
void TableauDeBord::setEtat3(int etat){
    TableauDeBord::etat3 = etat;
}
int TableauDeBord::convert(int x){
    return ((x*100)/80);
}

void TableauDeBord::setN1(bool n){
    TableauDeBord::n1 = n;
}
void TableauDeBord::setN2(bool n){
    TableauDeBord::n2 = n;
}
void TableauDeBord::setN3(bool n){
    TableauDeBord::n3 = n;
}
void TableauDeBord::setp11(bool n){
    p11 = n;
}
void TableauDeBord::setp12(bool n){
    p12 = n;
}
void TableauDeBord::setp112(bool n){
    p112 = n;
}
void TableauDeBord::setp122(bool n){
    p122 = n;
}
void TableauDeBord::setp113(bool n){
    p113 =n;
}
void TableauDeBord::setp123(bool n){
    p123 = n;
}
void TableauDeBord::setVT12(bool n){
    VaT12 = n;
}
void TableauDeBord::setVT23(bool n){
    VaT23 =n;
}
void TableauDeBord::setV12(bool n){
    Va12 = n;
}
void TableauDeBord::setV23(bool n){
    Va23 = n;
}
void TableauDeBord::setV13(bool n){
    Va13 = n;
}
//------------------------------------------------------------------------------
                                    //getters
//------------------------------------------------------------------------------
/*
QPainter* TableauDeBord::getPainter(){
    return this->painter;
}*/
/*
//------------------------------------------------------------------------------
QLabel* TableauDeBord::getLabel1(){
    return this->label1;
}
QLabel* TableauDeBord::getLabel2(){
    return this->label2;
}
QLabel* TableauDeBord::getLabel3(){
    return this->label3;
}
QLabel* TableauDeBord::getLabel4(){
    return this->label4;
}
QLabel* TableauDeBord::getLabel5(){

    return this->label5;
}
QLabel* TableauDeBord::getLabel6(){
    return  this->label6;
}
QLabel* TableauDeBord::getLabel7(){
    return this->label7;
}
QLabel* TableauDeBord::getLabel8(){
    return this->label8;
}
QLabel* TableauDeBord::getLabel9(){
    return this->label9;
}
QLabel* TableauDeBord::getLabel10(){
    return this->label10;
}
QLabel* TableauDeBord::getLabel11(){
    return this->label11;
}
QLabel* TableauDeBord::getLabel12(){
    return this->label12;
}
QLabel* TableauDeBord::getLabel13(){
    return this->label13;
}
QLabel* TableauDeBord::getLabel14(){
    return this->label14;
}
QLabel* TableauDeBord::getLabel15(){
    return this->label15;
}
QLabel* TableauDeBord::getLabel16(){
    return this->label16;
}
QLabel* TableauDeBord::getLabel17(){
    return this->label17;
}
//------------------------------------------------------------------------------
QPainterPath* TableauDeBord::getPath1(){
    return this->path1;
}
QPainterPath* TableauDeBord::getPath2(){
    return this->path2;
}
QPainterPath* TableauDeBord::getPath3(){
    return this->path3;
}
QPainterPath* TableauDeBord::getPath4(){
    return this->path4;
}
QPainterPath* TableauDeBord::getPath5(){
    return this->path5;
}
QPainterPath* TableauDeBord::getPath6(){
    return this->path6;
}
QPainterPath* TableauDeBord::getPath7(){
    return this->path7;
}
QPainterPath* TableauDeBord::getPath8(){
    return this->path8;
}
QPainterPath* TableauDeBord::getPath9(){
    return this->path9;
}
QPainterPath* TableauDeBord::getPath10(){
    return this->path10;
}
QPainterPath* TableauDeBord::getPath11(){
    return this->path11;
}
QPainterPath* TableauDeBord::getPath12(){
    return this->path12;
}
QPainterPath* TableauDeBord::getPath13(){
    return this->path13;
}
QPainterPath* TableauDeBord::getPath14(){
    return this->path14;
}
QPainterPath* TableauDeBord::getPath15(){
    return this->path15;
}
QPainterPath* TableauDeBord::getPath16(){
    return this->path16;
}
QPainterPath* TableauDeBord::getPath17(){
    return this->path17;
}
//------------------------------------------------------------------------------
QPainterPath* TableauDeBord::get_VT12(){
    return this->VT12;
}
QPainterPath* TableauDeBord::get_VT23(){
    return this->VT23;
}
QPainterPath* TableauDeBord::get_V12(){
    return this->V12;
}
QPainterPath* TableauDeBord::get_V13(){
    return this->V13;
}
QPainterPath* TableauDeBord::get_V23(){
    return this->V23;
}
*/
