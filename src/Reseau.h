#ifndef RESEAU_H
#define RESEAU_H

#include "Bibliotheque.h"

class Reseau {
private:
    static int compteur;
    int code;
    string nom;
    Liste<Bibliotheque*> liste_bibliotheques;

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
    bool traiterDemandePret(int ISBN,Bibliotheque* demandeur);
    bool traiterRetourPret(Livre& livre,Bibliotheque retourneur);
};

#endif