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

ostream& operator<<(ostream& out, Roman &r){
    out << (Livre&)r;
    out << ", Genre : "<< r.getgenre();
    return out;
}