#ifndef Roman_h
#define Roman_h
#include "Livre.h"
#include <iostream>
#include <string> 
using namespace std;

class Roman : public Livre {
    private :
        string genre;
    public :
        Roman();
        Roman(string auteur_livre,string titre_livre,string editeur_livre,int isbn_livre,string public_livre, string);
        void affiche();
        string getgenre();
        void afficher(ostream&) const;
        string getCategorie();
};

#endif