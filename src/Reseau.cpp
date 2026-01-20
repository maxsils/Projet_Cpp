#include "Reseau.h"
#include "Bibliotheque.h"

int Reseau::compteur=1;

Reseau::Reseau(){
    code=-1;
    nom="";
};

Reseau::Reseau(string nom){
    code=compteur;
    this->nom=nom;
    compteur++;
}

void Reseau::ajouterBibliotheque(Bibliotheque& biblio){
    liste_bibliotheques.ajouter(&biblio);
    biblio.setReseau(this);
}

void Reseau::supprimerBibliotheque(Bibliotheque& biblio){
    try{
        liste_bibliotheques.supprimer(&biblio);
        biblio.setReseau(nullptr);
    }
    catch(string e){
        cout<<e;
    }
}

void Reseau::afficher() {
    liste_bibliotheques.afficherTout();
}

ostream& operator<<(ostream& out, const Reseau& reseau){
    out<<"Code: "<<reseau.code<<", Nom : "<<reseau.nom;
    return out;
}

Livre* Reseau::traiterDemandePret(int ISBN,Bibliotheque* demandeur){
    if(this==nullptr) return nullptr;                             //On teste que le reseau dont la bibliotheque appartient n'est pas nul
    Noeud<Bibliotheque*>*courant=liste_bibliotheques.getTete();
    // Parcours des bibliotheques
    while(courant!=nullptr){
        Bibliotheque* biblio=courant->getInfo();
        if(biblio->getCode()!=demandeur->getCode()){            // On verifie que biblio n'est pas le demandeur
            Livre* livre=biblio->chercherLivrePretable(ISBN);   // On cherche dans le catalogue de la biblio si elle a un livre libre avec ce ISBN
            if(livre!=nullptr){                                 // On verifie que ce livre existe
                biblio->envoyerPret(*livre);                    // La bibliotheque prete le livre       
                demandeur->recevoirPret(*livre);                // Le demandeur recoit le pret
                ajouterTransaction(livre->getcode(),biblio->getCode(),demandeur->getCode());
                return livre;
            }
        }
        courant=courant->getSuivant();
    }
    return nullptr;
}

bool Reseau::traiterRetourPret(Livre& livre,Bibliotheque* emprunteuse){
    int*transaction=chercherTransaction(livre.getcode());       // On cherche la transaction
    int code_biblio_preteuse=transaction[1];
    Noeud<Bibliotheque*>*courant=liste_bibliotheques.getTete();
    // Parcours des bibliotheques
    while(courant!=nullptr){
        Bibliotheque*biblio=courant->getInfo();
        if(biblio->getCode()==code_biblio_preteuse){            // On verifie s'il s'agit de la biblio qui a prete le livre
            emprunteuse->rendrePret(livre);                     // La biblio emprunteuse rend le livre
            biblio->retourPret(livre);                          // La biblio preteuse revoit son livre 
            supprimerTransaction(*transaction);                 // La transaction est supprimee
            return true;
        }
        courant=courant->getSuivant();
    }
    return false;
}

void Reseau::ajouterTransaction(int code_livre,int code_preteur,int code_receveur){
    int*trasaction=new int[3];

    trasaction[0]=code_livre;
    trasaction[1]=code_preteur;
    trasaction[2]=code_receveur;

    liste_pret.ajouter(trasaction);
}

void Reseau::supprimerTransaction(int code_livre){
    try{
    int*transaction=chercherTransaction(code_livre);
    liste_pret.supprimer(transaction);
    delete[]transaction;
    }
    catch(string e){
        throw e;
    } 
}

int* Reseau::chercherTransaction(int code_livre){
    Noeud<int*>*courant=liste_pret.getTete();
    while(courant!=nullptr){
        int*transaction=courant->getInfo();
        if(transaction[0]==code_livre){
            return transaction;
        }
        courant=courant->getSuivant();
    }
    throw string("Aucune transaction trouvee avec ce livre");
}

bool Reseau :: livrePrete(int code_livre){
    try{
        chercherTransaction(code_livre);
        return true;
    }
    catch(string e){
        return false;
    }
}