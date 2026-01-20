#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <iostream>
using namespace std;
#include "Liste.h"
#include "Livre.h"
#include "Reseau.h"

class Adherent;

class Bibliotheque{
    private:
        static int compteur_code_biblio;
        int code;
        int compteur_adherent;
        string nom,adresse;
        Liste<Livre*> catalogue;
        Reseau* reseau;

        // Creation d'un pret
        void envoyerPret(Livre& livre);
        void recevoirPret(Livre& livre);

        // Fin d'un pret
        void rendrePret(Livre& livre);
        void retourPret(Livre& livre);

        // On laisse ces deux fonctions utiliser les methodes liees au pret
        friend Livre* Reseau::traiterDemandePret(int ISBN,Bibliotheque* demandeuse);
        friend bool Reseau::traiterRetourPret(Livre& livre,Bibliotheque* emprunteuse);

    public:
        // Constructeurs
        Bibliotheque();
        Bibliotheque(string nom,string adresse);

        // Affichages
        void afficherLivres();
        void afficherLivres(string categorie);
        friend ostream& operator<<(ostream& out, const Bibliotheque&biblio);

        // Getter
        int getCode() const;

        // Setter
        void setReseau(Reseau* reseau);

        // Methode pour retrouver un livre via son code
        Livre& getLivre(int code_livre);

        // Ajout et suppression de livres
        void achatLivre(Livre& livre);
        void supprimerLivre(int code_livre);

        // Ajout d'un adherent
        Adherent* creationAdherent(string nom,string prenom,string adresse);
        
        // Methodes liees au pret
        Livre* chercherLivrePretable(int ISBN);
        Livre* demandePret(int ISBN);
        void rendreUnPret(Livre& livre);
        void rendreLesPrets();

        // Methodes d'emprunt
        Livre* livreEmprunte(int ISBN);
        void retourEmprunt(int code_livre);
        Livre* chercherLivreEmpruntable(int ISBN);
};

#endif