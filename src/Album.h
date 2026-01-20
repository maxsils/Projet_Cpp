#ifndef Album_h
#define Album_h
#include "Livre.h"
#include <iostream>
#include <string> 
using namespace std;

class Album : public Livre {
    private :
        string illustrations;
    public :
        Album();
        Album(string auteur_livre,string titre_livre,string editeur_livre,int isbn_livre,string public_livre, string illustrations_album);
        void affiche();
        void afficher(ostream&) const;
        string getillustrations();
        string getCategorie();
};

#endif