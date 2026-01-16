#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <iostream>
using namespace std;
#include "Liste.h"
#include "Livre.h"

class Bibliotheque{
    private:
        int code;
        string nom,adresse;
        Liste<Livre*> liste_livres;
    public:
        Bibliotheque();
        Bibliotheque(int code_bibliotheque,string nom,string adresse);

        void afficherLivres();
        void afficherLivres(string categorie);
        //bool Livre EstLibre(int code_livre);
        void demanderLivre(int ISBN,int code_bibliotheque);
        void achatLivre(Livre& livre);
        void supprimerLivre(int code_livre);
        void rendreLivresPretes();

        Livre* getLivre(int code_livre);
};

#endif