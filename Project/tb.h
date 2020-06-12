#ifndef TB_H
 #define TB_H
 #include <QMainWindow>
 #include <QPushButton>
#include <QDebug>
#include <QCoreApplication>
#include <QLabel>
#include <QPixmap>
#include <QPainter>

 class tb : public QWidget
 {
    Q_OBJECT

 public:
     tb(int num,QWidget *parent = 0);
    tb();
    void paintEvent(QPaintEvent *);
     void emettre();
    bool getVT12();
    bool getVT23();
    bool getV12();
    bool getV13();
    bool getV23();
    bool getP12();
    bool getP22();
    bool getP32();
    void setNum(int num);
    QPushButton *panne_pompe, *panne_p_s, *ouverture_v_m, *vidange1, *equilibre;
 signals:
 void send( int ); // un signal personnalisé
 private:
 QPixmap pic;
     QPushButton *VT12,*VT23,*P12,*P22,*P32,*V12,*V13,*V23;

     QLabel* imageLabel;
     QLabel *label1,*label2,*label3,*label4,*label5,*label6,*label7,*label8,*label9,*label10;
    int num;
    bool bVT12, bVT23, bP12, bP22, bP32, bV12, bV13, bV23;
    bool PP, PPS, VM, VR, EQ;
    int cpt;

 private slots:
     //void handleButton();
    void handleButtonVT12();
    void handleButtonVT23();
    void handleButtonV12();
    void handleButtonV13();
    void handleButtonV23();
    void handleButtonP12();
    void handleButtonP22();
    void handleButtonP32();
    void handleButtonPP();
    void handleButtonPPS();
    void handleButtonVM();
    void handleButtonVR();
    void handleButtonEQ();
 };
 #endif // MAINWINDOW_H
