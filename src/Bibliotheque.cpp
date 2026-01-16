#include "Bibliotheque.h"

int Bibliotheque::compteur = 1;

Bibliotheque::Bibliotheque(){
    code=-1;
    nom="";
    adresse="";
}

Bibliotheque::Bibliotheque(string nom,string adresse){
    this->code=compteur;
    this->nom=nom;
    this->adresse=adresse;
    compteur++;
}

void Bibliotheque::afficherLivres(){
    liste_livres.afficherTout();
}

void Bibliotheque::afficherLivres(string categorie){
    Noeud<Livre*>*courant=liste_livres.getTete();
    while(courant!=nullptr){
        if(courant->getInfo()->getCategorie()==categorie){
            cout<<*courant->getInfo()<<"\n";
        }
        courant=courant->getSuivant();
    }
}

void Bibliotheque::demanderLivre(int ISBN,int code_bibliotheque){
    //A finir
}

void Bibliotheque::achatLivre(Livre& livre){//Ajouter une securite : bloquer l'ajout du meme livre ou livre-1
    this->liste_livres.ajouter(&livre);
}

void Bibliotheque::supprimerLivre(int code_livre){
    try{
        Livre& aSupprimer=getLivre(code_livre);
        liste_livres.supprimer(&aSupprimer);
    }
    catch(const char*e){
        cout<<e;
    }
}

void Bibliotheque::rendreLivresPretes(){
    
}

Livre& Bibliotheque::getLivre(int code_livre){
    Noeud<Livre*>*courant=liste_livres.getTete();

    while(courant!=nullptr&&courant->getInfo()->getcode()!=code_livre){
        courant=courant->getSuivant();
    }
    if(courant==nullptr) throw "Ce livre n'existe pas";
    return *courant->getInfo();
}