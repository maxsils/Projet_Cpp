#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

class Reseau;

#include <iostream>
using namespace std;
#include "Liste.h"
#include "Livre.h"

class Bibliotheque{
    private:
        static int compteur;
        int code;
        string nom,adresse;
        Liste<Livre*> catalogue;
        Liste<Livre*> liste_prets_recus;
        Reseau reseau;
    public:
        // Constructeurs
        Bibliotheque();
        Bibliotheque(string nom,string adresse);

        // Affichages
        void afficherLivres();
        void afficherLivres(string categorie);

        // Getter
        Livre& getLivre(int code_livre);
        int getCode() const;

        // Ajout et suppression de livres
        void achatLivre(Livre& livre);
        void supprimerLivre(int code_livre);
        
        // Methodes liees au pret
        Livre* chercherLivrePretable(int ISBN);
        bool demandePret(int ISBN);

        // Pret et retour de livres
        void preterLivre(Livre& livre);
        void recevoirPret(Livre& livre);
        void rendrePret(Livre& livre);

        void rendreLivresPretes();
};

#endif