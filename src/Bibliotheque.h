#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <iostream>
using namespace std;
#include "Liste.h"
#include "Livre.h"

class Bibliotheque{
    private:
        static int compteur;
        int code;
        string nom,adresse;
        Liste<Livre*> liste_livres;
    public:
        Bibliotheque();
        Bibliotheque(string nom,string adresse);

        void afficherLivres();
        void afficherLivres(string categorie);
        void demanderLivre(int ISBN,int code_bibliotheque);
        void achatLivre(Livre& livre);
        void supprimerLivre(int code_livre);
        void rendreLivresPretes();

        Livre& getLivre(int code_livre);
};

#endif