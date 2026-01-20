#ifndef BD_h
#define BD_h
#include "Livre.h"
#include <iostream>
#include <string> 
using namespace std;

class BD : public Livre {
    private :
        string dessinateur;
    public :
        BD();
        BD(string auteur,string titre,string editeur,int isbn,string publi,string dessinateur);
        void affiche();
        string getdessinateur();
        void afficher(ostream&) const;

        string getCategorie();
};

#endif