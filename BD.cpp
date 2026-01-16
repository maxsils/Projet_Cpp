#include "BD.h"
#include <cmath>

BD :: BD(const Livre&l, string d):Livre(l){
    dessinateur=d;
}

void BD :: affiche(){
    Livre::affiche();
    cout<<"Dessinateur : "<<dessinateur<<endl;
}