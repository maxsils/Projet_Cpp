#include "Album.h"
#include <cmath>

Album :: Album() : Livre(){
    illustrations="";
}

Album :: Album(const Livre&l, string i):Livre(l){
    illustrations=i;
}

void Album :: affiche(){
    Livre::affiche();
    cout<<", Illustrations : "<<illustrations<<endl;
}

string Album :: getillustrations(){
    return illustrations;
}

void Album::afficher(ostream& out) const {
    this->Livre::afficher(out);
    out<<", Illustrations : "<<illustrations;
}

string Album::getCategorie(){
    return "Album";
}