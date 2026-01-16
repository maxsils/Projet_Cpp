#include "Livre.h"
#include <cmath>

Livre :: Livre(){
    code = -1;
    auteur = nullptr;
    titre = nullptr;
    editeur = nullptr;
    isbn = -1;
    publics = nullptr;
    etat = nullptr;
}

Livre :: Livre(int c,string a,string t,string e,int i,string p){
    code = c;
    auteur = a;
    titre = t;
    editeur = e;
    isbn = i;
    publics = p;
    etat = "libre";
}

ostream& operator<<(ostream& out, Livre &L){
    out << "Code : "<< L.code << ", Auteur : " << L.auteur <<", Titre : "<< L.titre <<
    ", Editeur : "<< L.editeur << ", ISBN : " <<L.isbn<<", Public :"<<L.publics<<", Etat : "<<L.etat;
}
void Livre :: changer_etat(string etat){
    this -> etat = etat;
}

void Livre :: affiche(){
    cout<<"Code : "<< code << ", Auteur : " << auteur <<", Titre : "<< titre <<
    ", Editeur : "<< editeur << ", ISBN : " << isbn<<", Public :"<<publics<<", Etat : "<< etat<<endl;
}

int Livre :: getcode(){
    return code;
}

string Livre :: getetat(){
    return etat;
}

void Livre :: etatlibre(){
    etat = "libre";
}

void Livre :: etatemprunte(){
    etat = "emprunte";
}

void Livre :: etatprete(){
    etat = "prete";
}