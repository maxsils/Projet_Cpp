#include "Livre.h"
#include <cmath>

int Livre::compteur = 1;

Livre :: Livre(){
    code = -1;
    auteur = "";
    titre = "";
    editeur = "";
    isbn = -1;
    publics = "";
    etat = "";
}

Livre :: Livre(string a,string t,string e,int i,string p){
    code = compteur;
    auteur = a;
    titre = t;
    editeur = e;
    isbn = i;
    publics = p;
    etat = "libre";
    compteur++;
}

void Livre::afficher(ostream& out) const {
    out << "Code : "<< this->code << ", Auteur : " << this->auteur <<", Titre : "<< this->titre <<
    ", Editeur : "<< this->editeur << ", ISBN : " <<this->isbn<<", Public :"<<this->publics<<", Etat : "<<this->etat;
}

ostream& operator<<(ostream& out, const Livre &L){
    L.afficher(out);
    return out;
}
bool Livre :: operator== (const Livre& L) const{
    return (this -> code== L.code);
}

bool Livre :: operator!= (const Livre& L) const{
    return (this -> code!= L.code);
}

void Livre :: changer_etat(string etat){
    this -> etat = etat;
}

void Livre :: affiche(){
    cout<<"Code : "<< code << ", Auteur : " << auteur <<", Titre : "<< titre <<
    ", Editeur : "<< editeur << ", ISBN : " << isbn<<", Public :"<<publics<<", Etat : "<< etat;
}

int Livre :: getcode() const{
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