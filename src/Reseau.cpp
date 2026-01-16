#include "Reseau.h"

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

bool Reseau::traiterDemandePret(int ISBN,Bibliotheque* demandeur){
    if(this==nullptr) return false;                             //On teste que le reseau dont la bibliotheque appartient n'est pas nul

    Noeud<Bibliotheque*>*courant=liste_bibliotheques.getTete();

    // Parcours des bibliotheques
    while(courant!=nullptr){
        Bibliotheque* biblio=courant->getInfo();
        if(biblio->getCode()!=demandeur->getCode()){            // On verifie que biblio n'est pas le demandeur
            Livre* livre=biblio->chercherLivrePretable(ISBN);   // On cherche dans le catalogue de la biblio si elle a un livre libre avec ce ISBN
            if(livre!=nullptr){                                 // On vérifie que ce livre existe
                biblio->preterLivre(*livre);                    // La bibliotheque prete le livre       
                demandeur->recevoirPret(*livre);                // Le demandeur recoit le pret
                return true;
            }
        }
        courant=courant->getSuivant();
    }
    return false;
}

bool Reseau::traiterRetourPret(Livre& livre,Bibliotheque retourneur){
    // A finir
    return true;
}