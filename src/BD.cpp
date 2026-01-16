#include "BD.h"
#include <cmath>

BD :: BD() : Livre(){
    dessinateur="";
}

BD :: BD(const Livre&l, string d):Livre(l){
    dessinateur=d;
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