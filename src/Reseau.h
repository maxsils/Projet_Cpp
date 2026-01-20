#ifndef RESEAU_H
#define RESEAU_H

#include <iostream>
using namespace std;
#include "Liste.h"
#include "Livre.h"

class Bibliotheque;

class Reseau {
private:
    static int compteur;
    int code;
    string nom;
    Liste<Bibliotheque*> liste_bibliotheques;
    Liste<int*> liste_pret;

    // Methoder liees aux transactions
    void ajouterTransaction(int code_livre,int code_preteur,int code_receveur);
    void supprimerTransaction(int code_livre);
    int* chercherTransaction(int code_livre);

public:
    // Constructeur
    Reseau();
    Reseau(string nom);

    // Ajout et suppression d'une bibliotheque au reseau
    void ajouterBibliotheque(Bibliotheque&);
    void supprimerBibliotheque(Bibliotheque&);

    // Affichage
    void afficher();
    friend ostream& operator<<(ostream& out, const Reseau& reseau);

    // Traitement des pret : emprunt et retour
    Livre* traiterDemandePret(int ISBN,Bibliotheque* demandeuse);
    bool traiterRetourPret(Livre& livre,Bibliotheque* emprunteuse);
};

#endif