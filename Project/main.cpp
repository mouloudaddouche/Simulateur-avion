#include <QApplication>
#include <iostream>
#include <QObject>
#include "FenPrincipale.h"
#include "table_controle.h"
#include "Principale.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Fenetre1 w;
    w.show();
    return app.exec();
}


