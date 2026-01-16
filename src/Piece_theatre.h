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
        Piece_theatre(const Livre&l, int siecle_piece);
        void affiche();
        friend ostream& operator<<(ostream& out, Piece_theatre &pt);
        int getsiecle();
};

#endif