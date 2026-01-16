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
        Album(const Livre&l, string illustrations_album);
        void affiche();
        void afficher(ostream&) const;
        string getillustrations();
        string getCategorie();
};

#endif