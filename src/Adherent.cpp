#include "Adherent.h"

Adherent::Adherent(){
    nom=nullptr;
    prenom=nullptr;
    adresse=nullptr;
    limite_emprunt=-1;
    livres_empruntes=Liste<Livre>();
}

Adherent::Adherent(string nom,string prenom,string adresse,int num_adherent,int code_bibliotheque,int limite_emprunt){
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->num_adherent=num_adherent;
    this->code_bibliotheque=code_bibliotheque;
    this->limite_emprunt=limite_emprunt;
    livres_empruntes=Liste<Livre>();
}

void Adherent::empruntLivre(int code_livre){
    
}

void Adherent::rendreLivre(int code_livre){}