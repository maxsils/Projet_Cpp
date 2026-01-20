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
        Recueil_poesie(string auteur_livre,string titre_livre,string editeur_livre,int isbn_livre,string public_livre, string);
        void affiche();
        string getindicateur();
        void afficher(ostream& os) const;
        string getCategorie();
};

#endif