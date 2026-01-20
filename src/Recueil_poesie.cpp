#include "Recueil_poesie.h"
#include <cmath>

Recueil_poesie :: Recueil_poesie() : Livre(){
    indicateur="";
}

Recueil_poesie :: Recueil_poesie(string auteur_livre,string titre_livre,string editeur_livre,int isbn_livre,string public_livre, string i):Livre(auteur_livre,titre_livre,editeur_livre,isbn_livre,public_livre){
    indicateur=i;
}

void Recueil_poesie :: affiche(){
    Livre::affiche();
    cout<<", Indicateur : "<<indicateur<<endl;
}

string Recueil_poesie :: getindicateur(){
    return indicateur;
}

void Recueil_poesie::afficher(ostream& out) const {
    this->Livre::afficher(out);
    out << ", Indicateur : "<<indicateur;
}

string Recueil_poesie::getCategorie(){
    return "Recueil de poesie";
}