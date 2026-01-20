#ifndef ADHERENT_H
#define ADHERENT_H

#include <iostream>
using namespace std;
#include "Liste.h"
#include "Livre.h"
#include "Bibliotheque.h"

class Adherent
{
    private:
        string nom,prenom,adresse;
        int num_adherent;
        Bibliotheque* biblio;
        Liste<Livre*> livres_empruntes;
        int limite_emprunt;
    public:
        Adherent();
        Adherent(string nom,string prenom,string adresse,int num_adherent,Bibliotheque* biblio,int limite_emprunt);
        void empruntLivre(int code_livre);
        void rendreLivre(int code_livre);
};

#endif