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

void Piece_theatre::afficher(ostream& out) const{
    this->Livre::afficher(out);
    out<<", Siecle : "<< siecle;
}

string Piece_theatre::getCategorie(){
    return "Piece de teatre";
}