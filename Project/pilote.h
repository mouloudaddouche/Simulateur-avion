#ifndef PILOTE_H
#define PILOTE_H
#include <string>
class pilote
{
public :
    pilote();
    pilote(std::string nom, std::string prenom);
    std::string getNom();
    std::string getPrenom();
private :
    std::string nom;
    std::string prenom;
    int note;
};
#endif // PILOTE_H
