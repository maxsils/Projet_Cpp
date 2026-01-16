#ifndef RESEAU_H
#define RESEAU_H

#include "Bibliotheque.h"

class Reseau {
private:
    Liste<Bibliotheque*> liste_bibliotheques;

public:
    // Constructeur
    Reseau();

    // Ajout et suppression d'une bibliotheque au reseau
    void ajouterBibliotheque(Bibliotheque&);
    void supprimerBibliotheque(Bibliotheque&);

    // Affichage
    void afficher();

    // Traitement des pret : emprunt et retour
    bool traiterDemandePret(int ISBN,Bibliotheque* demandeur);
    bool traiterRetourPret(Livre& livre,Bibliotheque retourneur);
};

#endif