#include "Bibliotheque.h"

Bibliotheque::Bibliotheque(){
    code=-1;
    nom="";
    adresse="";
    liste_livres=Liste<Livre>();
}

Bibliotheque::Bibliotheque(int code,string nom,string adresse){
    this->code=code;
    this->nom=nom;
    this->adresse=adresse;
    liste_livres=Liste<Livre>();
}

void Bibliotheque::afficherLivres(){
    liste_livres.afficherTout();
}

void Bibliotheque::afficherLivres(string categorie){
    // Noeud<Livre>*courant=liste_livres.getTete();
    // while(courant!=nullptr){
    //     if(courant->getInfo().getCategorie()==categorie){        Implementer Livre.getCategorie()
    //         cout<<courant->getInfo()<<"\n";                      Implementer cout<<Livre()
    //     }
    //     courant=courant->getSuivant();
    // }
}

void Bibliotheque::demanderLivre(int ISBN,int code_bibliotheque){
    //A finir
}

void Bibliotheque::achatLivre(string auteur_livre,string titre_livre,string editeur_livre,int isbn_livre,string public_livre){
    liste_livres.ajouter(Livre(auteur_livre,titre_livre,editeur_livre,isbn_livre,public_livre)); 
}

void Bibliotheque::supprimerLivre(int code_livre){
    try{
        Livre aSupprimer=getLivre(code_livre);
        liste_livres.supprimer(aSupprimer);
    }
    catch(const char*e){
        cout<<"e";
    }
}

void Bibliotheque::rendreLivresPretes(){
    
}

Livre Bibliotheque::getLivre(int code_livre){
    Noeud<Livre>*courant=liste_livres.getTete();
    while(courant!=nullptr&&courant->getInfo().getcode()!=code_livre){
        courant=courant->getSuivant();
    }
    if(courant==nullptr) throw "Ce livre n'existe pas";
    return courant->getInfo();
}