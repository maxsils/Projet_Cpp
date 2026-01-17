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
        Reseau* reseau;
    public:
        // Constructeurs
        Bibliotheque();
        Bibliotheque(string nom,string adresse);

        // Affichages
        void afficherLivres();
        void afficherLivres(string categorie);
        friend ostream& operator<<(ostream& out, const Bibliotheque&biblio);

        // Getter
        Livre& getLivre(int code_livre);
        int getCode() const;

        // Setter
        void setReseau(Reseau* reseau);

        // Ajout et suppression de livres
        void achatLivre(Livre& livre);
        void supprimerLivre(int code_livre);
        
        // Methodes liees au pret
        Livre* chercherLivrePretable(int ISBN);
        bool demandePret(int ISBN);
        void rendreUnPret(Livre& livre);
        void rendreLesPrets();

        // Creation d'un pret
        void envoyerPret(Livre& livre);
        void recevoirPret(Livre& livre);

        // Fin d'un pret
        void rendrePret(Livre& livre);
        void retourPret(Livre& livre);
};

#endif