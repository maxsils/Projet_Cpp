#include "Piece_theatre.h"
#include <cmath>

Piece_theatre :: Piece_theatre() : Livre(){
    siecle=-1;
}

Piece_theatre :: Piece_theatre(string auteur_livre,string titre_livre,string editeur_livre,int isbn_livre,string public_livre, int s):Livre(auteur_livre,titre_livre,editeur_livre,isbn_livre,public_livre){
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