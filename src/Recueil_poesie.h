#ifndef Recueil_poesie_h
#define Recueil_poesie_h
#include "Livre.h"
#include <iostream>
#include <string> 
using namespace std;

class Recueil_poesie : public Livre {
    private :
        string indicateur;
    public :
        Recueil_poesie();
        Recueil_poesie(const Livre&l, string);
        void affiche();
        string getindicateur();
        friend ostream& operator<<(ostream& out, Recueil_poesie &rp);
};

#endif