#include "Reseau.h"

Reseau::Reseau(){};

void Reseau::ajouterBibliotheque(Bibliotheque& biblio){
    liste_bibliotheques.ajouter(&biblio);
}

void Reseau::supprimerBibliotheque(Bibliotheque& biblio){
    try{
        liste_bibliotheques.supprimer(&biblio);
    }
    catch(string e){
        cout<<e;
    }
}

void Reseau::afficher() {
    liste_bibliotheques.afficherTout();
}

bool Reseau::traiterDemandePret(int ISBN,Bibliotheque* demandeur){
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
}