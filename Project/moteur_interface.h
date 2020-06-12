#ifndef MOTEUR_INTERFACE_H
#define MOTEUR_INTERFACE_H
#include <QtGui>
#include <QPixmap>
#include <QWidget>

class moteur_interface : public QWidget
{
    Q_OBJECT
    QPixmap pix;
    QTimeLine m_t;

public:
    moteur_interface(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *);
    void StopMoteur1();
    void StopMoteur2();
    void StopMoteur3();
    void DemarerMoteur1();
    void DemarerMoteur2();
    void DemarerMoteur3();
    static bool marche1;
    static bool marche2;
    static bool marche3;
};
#endif // MOTEUR_INTERFACE_H
