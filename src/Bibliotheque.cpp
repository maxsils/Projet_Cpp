#include "Bibliotheque.h"
#include "Reseau.h"

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
    catalogue.afficherTout();
}

void Bibliotheque::afficherLivres(string categorie){
    Noeud<Livre*>*courant=catalogue.getTete();
    while(courant!=nullptr){
        if(courant->getInfo()->getCategorie()==categorie){
            cout<<*courant->getInfo()<<"\n";
        }
        courant=courant->getSuivant();
    }
}

Livre& Bibliotheque::getLivre(int code_livre){
    Noeud<Livre*>*courant=catalogue.getTete();

    while(courant!=nullptr&&courant->getInfo()->getcode()!=code_livre){
        courant=courant->getSuivant();
    }
    if(courant==nullptr) throw string("Ce livre n'existe pas\n");
    return *courant->getInfo();
}

int Bibliotheque::getCode() const {
    return code;
}

void Bibliotheque::achatLivre(Livre& livre){
    if(livre.getcode()==-1) throw string("Erreur : Tentative d'ajout d'un livre sans donnees (code -1)\n");
    Noeud<Livre*>*courant=this->catalogue.getTete();
    while(courant!=nullptr){
        if(courant->getInfo()->getcode()==livre.getcode()) throw string("Achat deja fait\n");
        courant=courant->getSuivant();
    }
    this->catalogue.ajouter(&livre);
}

void Bibliotheque::supprimerLivre(int code_livre){
    try{
        Livre& aSupprimer=getLivre(code_livre);
        catalogue.supprimer(&aSupprimer);
    }
    catch(string e){
        cout<<e;
    }
}

Livre* Bibliotheque::chercherLivrePretable(int ISBN){
    Noeud<Livre*>*courant=catalogue.getTete();
    while(courant!=nullptr){
        Livre*livre=courant->getInfo();
        if(livre->getISBN()==ISBN){
            if(livre->getetat()=="libre") return livre;
        }
        courant=courant->getSuivant();
    }
    return nullptr;
}

bool Bibliotheque::demandePret(int ISBN){
    return reseau.traiterDemandePret(ISBN,this);
}

void Bibliotheque::preterLivre(Livre& livre){
    livre.etatprete();
}

void Bibliotheque::recevoirPret(Livre& livre){
    this->catalogue.ajouter(&livre);                    // On ajoute le livre a notre catalogue
    this->liste_prets_recus.ajouter(&livre);            // On ajoute egalement livre a notre catalogue de prets recus
}

void Bibliotheque::rendrePret(Livre& livre){
    if(livre.getetat()=="emprunter"){                   // Attention potentiel changement etat !!!!
        catalogue.enlever(&livre);
        liste_prets_recus.enlever(&livre);
        livre.etatlibre();
    }
}

void Bibliotheque::rendreLivresPretes(){
    Noeud<Livre*>*courant=this->liste_prets_recus.getTete();
    while(courant!=nullptr){
        Livre* livre=courant->getInfo();
        if(livre->getetat()=="preter"){                 // Attention potentiel changement etat !!!!
            rendrePret(*livre);
        }
        courant=courant->getSuivant();
    }
}