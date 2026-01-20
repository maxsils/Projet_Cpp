#include "BD.h"
#include <cmath>

BD :: BD() : Livre(){
    dessinateur="";
}

BD :: BD(string auteur,string titre,string editeur,int isbn,string publi,string dessinateur):Livre(auteur,titre,editeur,isbn,publi){
    this->dessinateur=dessinateur;
}

void BD :: affiche(){
    Livre::affiche();
    cout<<", Dessinateur : "<<dessinateur<<endl;
}

string BD :: getdessinateur(){
    return dessinateur;
}

void BD::afficher(ostream& out) const {
    this->Livre::afficher(out);
    out << ", Dessinateur : "<<dessinateur;
}

string BD::getCategorie(){
    return "BD";
}