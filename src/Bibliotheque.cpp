#include "Bibliotheque.h"
#include "Reseau.h"

int Bibliotheque::compteur_code_biblio = 1;

Bibliotheque::Bibliotheque(){
    code=-1;
    nom="";
    adresse="";
}

Bibliotheque::Bibliotheque(string nom,string adresse){
    this->code=compteur_code_biblio;
    this->nom=nom;
    this->adresse=adresse;
    compteur_code_biblio++;
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

ostream& operator<<(ostream& out, const Bibliotheque& biblio){
    out << "Code : "<< biblio.code << ", Nom : " << biblio.nom <<", Adresse : "<<biblio.adresse<<", Reseau : "<<*biblio.reseau;
    return out;
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

void Bibliotheque::setReseau(Reseau* reseau){
    this->reseau=reseau;
}

void Bibliotheque::achatLivre(Livre& livre){
    if(livre.getcode()==-1) throw string("Erreur : Tentative d'ajout d'un livre sans donnees (code -1)\n");
    Noeud<Livre*>*courant=catalogue.getTete();
    while(courant!=nullptr){
        if(courant->getInfo()->getcode()==livre.getcode()) throw string("Achat deja fait\n");
        courant=courant->getSuivant();
    }
    catalogue.ajouter(&livre);
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
    return reseau->traiterDemandePret(ISBN,this);           // On demande au reseau un pret//Si c'est true pret se réalise
}

void Bibliotheque::rendreUnPret(Livre&livre){
    if(livre.getetat()=="prete"){                           // Attention potentiel changement : etat !!!!
        reseau->traiterRetourPret(livre,this);                   // On envoie notre demande de retour au reseau
    }
}

void Bibliotheque::rendreLesPrets(){
    Noeud<Livre*>*courant=catalogue.getTete();
    while(courant!=nullptr){
        Livre*livre=courant->getInfo();
        rendrePret(*livre);
    }
}

void Bibliotheque::envoyerPret(Livre& livre){
    livre.etatprete();
    supprimerLivre(livre.getcode());
}

void Bibliotheque::recevoirPret(Livre& livre){
    catalogue.ajouter(&livre);                              // On ajoute le livre a notre catalogue
}

void Bibliotheque::rendrePret(Livre& livre){
    catalogue.supprimer(&livre);
}

void Bibliotheque::retourPret(Livre&livre){
    catalogue.ajouter(&livre);
    livre.etatlibre();
}