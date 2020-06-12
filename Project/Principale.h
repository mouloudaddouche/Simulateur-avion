#ifndef FENETRE1_H
#define FENETRE1_H

#include <QWidget>
#include "inscription.h"
#include "connexion.h"


namespace Ui {
class Fenetre1;
}

class Fenetre1 : public QWidget
{
    Q_OBJECT

public:
    explicit Fenetre1(QWidget *parent = nullptr);
    ~Fenetre1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Fenetre1 *ui;
};

#endif // FENETRE1_H
