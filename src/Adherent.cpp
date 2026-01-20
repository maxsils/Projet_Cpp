#include "Adherent.h"

Adherent::Adherent(){
    nom="";
    prenom="";
    adresse="";
    limite_emprunt=-1;
}

Adherent::Adherent(string nom,string prenom,string adresse,int num_adherent,Bibliotheque* biblio,int limite_emprunt){
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->num_adherent=num_adherent;
    this->biblio=biblio;
    this->limite_emprunt=limite_emprunt;
}

void Adherent::empruntLivre(int ISBN){
    Livre* livre = biblio->chercherLivreEmpruntable(ISBN);
    if (livre!=nullptr){
        livre->etatemprunte();
    }
    else{
        Livre* livre = biblio->demandePret(ISBN);
        if (livre!=nullptr){
            livre->etatemprunte();
        }
        else{
            throw string("Aucun livre n'est disponible dans notre reseau");
        }
    }

}

void Adherent::rendreLivre(int code_livre){}