#include "BD.h"
#include <cmath>

BD :: BD(const Livre&l, string d):Livre(l){
    dessinateur=d;
}

void BD :: affiche(){
    Livre::affiche();
    cout<<"Dessinateur : "<<dessinateur<<endl;
}

string BD :: getdessinateur(){
    return dessinateur;
}

ostream& operator<<(ostream& out, BD &bd){
    out << (Livre&)bd;
    out << ", Dessinateur : "<< bd.getdessinateur();
}