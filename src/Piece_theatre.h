#ifndef Piece_theatre_h
#define Piece_theatre_h
#include "Livre.h"
#include <iostream>
#include <string> 
using namespace std;

class Piece_theatre : public Livre {
    private :
        int siecle;
    public :
        Piece_theatre();
        Piece_theatre(string auteur_livre,string titre_livre,string editeur_livre,int isbn_livre,string public_livre, int siecle_piece);
        void affiche();
        void afficher(ostream&) const;
        int getsiecle();
        string getCategorie();
};

#endif