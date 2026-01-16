#include "Recueil_poesie.h"
#include <cmath>

Recueil_poesie :: Recueil_poesie() : Livre(){
    indicateur="";
}

Recueil_poesie :: Recueil_poesie(const Livre&l, string i):Livre(l){
    indicateur=i;
}

void Recueil_poesie :: affiche(){
    Livre::affiche();
    cout<<", Indicateur : "<<indicateur<<endl;
}

string Recueil_poesie :: getindicateur(){
    return indicateur;
}

ostream& operator<<(ostream& out, Recueil_poesie &rp){
    out << (Livre&)rp;
    out << ", Indicateur : "<< rp.getindicateur();
    return out;
}

string Recueil_poesie::getCategorie(){
    return "Recueil de poesie";
}