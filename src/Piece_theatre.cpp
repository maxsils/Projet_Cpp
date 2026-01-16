#include "Piece_theatre.h"
#include <cmath>

Piece_theatre :: Piece_theatre() : Livre(){
    siecle=-1;
}

Piece_theatre :: Piece_theatre(const Livre&l, int s):Livre(l){
    siecle=s;
}

void Piece_theatre :: affiche(){
    Livre::affiche();
    cout<<", Siecle : "<<siecle<<endl;
}

int Piece_theatre :: getsiecle(){
    return siecle;
}

ostream& operator<<(ostream& out, Piece_theatre &pt){
    out << (Livre&)pt;
    out << ", Siecle : "<< pt.getsiecle();
    return out;
}

string Piece_theatre::getCategorie(){
    return "Piece de teatre";
}