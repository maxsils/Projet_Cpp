#include "Roman.h"
#include <cmath>

Roman :: Roman(): Livre(){
    genre="";
}

Roman :: Roman(const Livre&l, string g):Livre(l){
    genre=g;
}

void Roman :: affiche(){
    Livre::affiche();
    cout<<", Genre : "<<genre<<endl;
}

string Roman :: getgenre(){
    return genre;
}

void Roman::afficher(ostream& out) const {
    this->Livre::afficher(out);
    out << ", Genre : "<<genre;
}

string Roman::getCategorie(){
    return "Roman";
}