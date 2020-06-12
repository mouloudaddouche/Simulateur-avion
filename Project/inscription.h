#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QDialog>
#include <QMessageBox>
#include "database.h"
#include "FenPrincipale.h"
#include "table_controle.h"

namespace Ui {
class Inscription;
}

class Inscription : public QDialog
{
    Q_OBJECT

public:
    explicit Inscription(QWidget *parent = nullptr);
    ~Inscription();

private slots:
    void on_pushButton_clicked();

    void on_Valider_clicked();

private:
    Ui::Inscription *ui;
};

#endif // INSCRIPTION_H
