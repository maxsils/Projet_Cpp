#include "Roman.h"
#include <cmath>

Roman :: Roman(): Livre(){
    genre="";
}

Roman :: Roman(string auteur_livre,string titre_livre,string editeur_livre,int isbn_livre,string public_livre, string g):Livre(auteur_livre,titre_livre,editeur_livre,isbn_livre,public_livre){
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