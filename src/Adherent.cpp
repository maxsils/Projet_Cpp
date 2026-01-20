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
    if (livres_empruntes.getTaille() >= limite_emprunt ){
        cout<<"Erreur : la limite de livres est déà atteinte"<<endl;
    }
    else{
        Livre* livre =biblio->livreEmprunte(ISBN);
        if(livre!=nullptr){
            cout<<"Emprunt realise"<<endl;
            livres_empruntes.ajouter(livre);
        }
        else{
            cout<<"Aucun livre n'est disponible dans notre reseau"<<endl;
        }
    }
}

void Adherent::rendreLivre(int code_livre){
    cout<<"Livre rendu"<<endl;
    return biblio->retourEmprunt(code_livre);
}