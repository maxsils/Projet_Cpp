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

ostream& operator<<(ostream& out, Album &al){
    out << (Livre&)al;
    out << ", Illustrations : "<< al.getillustrations();
    return out;
}