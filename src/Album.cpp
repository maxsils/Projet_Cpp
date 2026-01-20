#include "Album.h"
#include <cmath>

Album :: Album() : Livre(){
    illustrations="";
}

Album :: Album(string auteur_livre,string titre_livre,string editeur_livre,int isbn_livre,string public_livre, string i):Livre(auteur_livre,titre_livre,editeur_livre,isbn_livre,public_livre){
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