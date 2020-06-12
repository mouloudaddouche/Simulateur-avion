/*#include "interface_remplissage.h"
interface_remplissage::interface_remplissage(TableauDeBord* tableau){
    //setFixedSize(1100,1080);

    M1=tableau->getInterfaceMoteur1();
    M2=tableau->getInterfaceMoteur2();
    M3=tableau->getInterfaceMoteur3();
}

void interface_remplissage::paintEvent(QPaintEvent *event){
    this->painter = this->tableau->getPainter();
    QPen pen(Qt::black, 2);

    //QProgressBar *Tuyau1,*Tuyau2;


   //M1,M2,M3
   this->M1->setGeometry(70, 750, 200, 220);
   this->M2->setGeometry(440, 750, 200, 220);
   this->M3->setGeometry(810, 750, 200, 220);

   //this->Tuyau1 = this->tableau->
   //Tuyau1->setGeometry(641, 260, 168, 40);
   //Tuyau1->setTextVisible(false);
  // Tuyau1->setMaximum(0);
   //Tuyau1->setMinimum(0);
   //Tuyau1->setValue(100);
   //Tuyau1->showNormal();

   //Tuyau2 = new QProgressBar(this);
   //Tuyau2->setGeometry(271, 260, 217, 40);
   //Tuyau2->show();

   DessinerTank1(painter);
   DessinerTank2(painter);
   DessinerTank3(painter);
   //RemplirTank(painter,2,100);
   //RemplirTank(&painter,1,30);
   //RemplirTank(&painter,3,50);
   VanneVT12(painter,1);
   VanneVT23(painter,1);
   VanneV12(painter,0);
   VanneV13(painter,1);
   VanneV23(painter,1);
   SchemaTuyau(this->painter);
}

void interface_remplissage::DessinerTank1(QPainter* P){
    QFont font1,font2; //Declaration Des Ecriture
    font1.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font1.setPixelSize(20); // this for setting font size
    font1.setFamily("Times new roman");
    font2.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font2.setPixelSize(30); // this for setting font size
    font2.setFamily("arial");

    QPen pen(Qt::black, 2); // Declaration Du Pen

this->label1 = this->tableau->getLabel1();
label1->setStyleSheet("QLabel {color : white; }");
label1->setFont(font1);
label1->setText("P11");
label1->move(130,430);
label1->show();

label2 = this->tableau->getLabel2();
label2->setStyleSheet("QLabel {color : white; }");
label2->setFont(font1);
label2->setText("P12");
label2->move(195,430);
label2->show();

label3 = this->tableau->getLabel3();
label3->setStyleSheet("QLabel {color : black; }");
label3->setFont(font2);
label3->setText("Tank1");
label3->move(145,300);
label3->show();

this->path1= this->tableau->getPath1();
path1->addRoundedRect(QRectF(80, 60, 190, 420), 10, 10);
P->setPen(pen);
P->drawPath(*path1);
}

void interface_remplissage::DessinerTank2(QPainter* P){


    QFont font1,font2; //Declaration Des Ecriture

    font1.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font1.setPixelSize(20); // this for setting font size
    font1.setFamily("Times new roman");

    font2.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font2.setPixelSize(30); // this for setting font size
    font2.setFamily("arial");

    QPen pen(Qt::black, 2); // Declaration Du Pen
    label4 = this->tableau->getLabel4();
    label4->setStyleSheet("QLabel {color : white; }");
    label4->setFont(font1);
    label4->setText("P21");
    label4->move(500,435);
    label4->show();

    label5 = this->tableau->getLabel5();
    label5->setStyleSheet("QLabel {color : white; }");
    label5->setFont(font1);
    label5->setText("P22");
    label5->move(565,435);
    label5->show();

    label6 = this->tableau->getLabel6();
    label6->setStyleSheet("QLabel {color : black; }");
    label6->setFont(font2);
    label6->setText("Tank2");
    label6->move(505,300);
    label6->show();
   path2=this->tableau->getPath2();
   path2->addRoundedRect(QRectF(450, 120, 190, 360), 10, 10);
   P->setPen(pen);
   P->drawPath(*path2);
}

void interface_remplissage::DessinerTank3(QPainter* P){

    QFont font1,font2; //Declaration Des Ecriture

    font1.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font1.setPixelSize(20); // this for setting font size
    font1.setFamily("Times new roman");

    font2.setWeight(QFont::Bold); // set font weight with enum QFont::Weight
    font2.setPixelSize(30); // this for setting font size
    font2.setFamily("arial");

    QPen pen(Qt::black, 2); // Declaration Du Pen

    label7 = this->tableau->getLabel7();
    label7->setStyleSheet("QLabel {color : white; }");
    label7->setFont(font1);
    label7->setText("P31");
    label7->move(865,430);
    label7->show();
    label8 = this->tableau->getLabel8();
    label8->setStyleSheet("QLabel {color : white; }");
    label8->setFont(font1);
    label8->setText("P32");
    label8->move(930,430);
    label8->show();
    label9 = this->tableau->getLabel9();
    label9->setStyleSheet("QLabel {color : black; }");
    label9->setFont(font2);
    label9->setText("Tank3");
    label9->move(855,300);
    label9->show();

    path8=this->tableau->getPath8();
    path8->addRoundedRect(QRectF(810, 60, 190, 420), 10, 10);
    P->setPen(pen);
    P->drawPath(*path8);
}

void interface_remplissage::VanneVT23(QPainter* P,int etat){
    QPen pen1(Qt::black, 2);
    QPen pen2(Qt::black, 6);
    VT23=this->tableau->get_VT23();
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

void interface_remplissage::VanneVT12(QPainter* P,int etat){
    QPen pen1(Qt::black, 2);
    QPen pen2(Qt::black, 6);
    VT12=this->tableau->get_VT12();
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

void interface_remplissage::VanneV12(QPainter* P,int etat){
    QPen pen1(Qt::black, 2);
    QPen pen2(Qt::black, 6);
    V12=this->tableau->get_V12();
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

void interface_remplissage::VanneV13(QPainter* P,int etat){
    QPen pen1(Qt::black, 2);
    QPen pen2(Qt::black, 6);
    V13=this->tableau->get_V13();
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

void interface_remplissage::VanneV23(QPainter* P,int etat){
    QPen pen1(Qt::black, 2);
    QPen pen2(Qt::black, 6);
    V23=this->tableau->get_V23();
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

void interface_remplissage::SchemaTuyau(QPainter* P){
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

    label10 = this->tableau->getLabel10();
    label10->setStyleSheet("QLabel {color : black; }");
    label10->setFont(font1);
    label10->setText("VT12");
    label10->move(335,167);
    label10->show();

    label11 = this->tableau->getLabel11();
    label11->setStyleSheet("QLabel {color : black; }");
    label11->setFont(font1);
    label11->setText("VT23");
    label11->move(700,167);
    label11->show();

    label12 = this->tableau->getLabel12();
    label12->setStyleSheet("QLabel {color : black; }");
    label12->setFont(font1);
    label12->setText("V12");
    label12->move(342,574);
    label12->show();

    label13 = this->tableau->getLabel13();
    label13->setStyleSheet("QLabel {color : black; }");
    label13->setFont(font1);
    label13->setText("V13");
    label13->move(643,489);
    label13->show();

    label14 = this->tableau->getLabel14();
    label14->setStyleSheet("QLabel {color : black; }");
    label14->setFont(font1);
    label14->setText("V23");
    label14->move(703,612);
    label14->show();

    label15 = this->tableau->getLabel15();
    label15->setStyleSheet("QLabel {color : black; }");
    label15->setFont(font1);
    label15->setText("M1");
    label15->move(160,722);
    label15->show();

    label16 = this->tableau->getLabel16();
    label16->setStyleSheet("QLabel {color : black; }");
    label16->setFont(font1);
    label16->setText("M2");
    label16->move(490,722);
    label16->show();

    label17 = this->tableau->getLabel1();
    label17->setStyleSheet("QLabel {color : black; }");
    label17->setFont(font1);
    label17->setText("M3");
    label17->move(900,722);
    label17->show();
}
*/
