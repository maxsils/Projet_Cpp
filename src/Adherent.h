#ifndef ADHERENT_H
#define ADHERENT_H

#include <iostream>
using namespace std;
#include "Liste.h"
#include "Livre.h"

class Adherent
{
    private:
        string nom,prenom,adresse;
        int num_adherent;
        int code_bibliotheque;
        Liste<Livre> livres_empruntes;
        int limite_emprunt;
    public:
        Adherent();
        Adherent(string nom,string prenom,string adresse,int num_adherent,int code_bibliotheque,int limite_emprunt);
        void empruntLivre(int code_livre);
        void rendreLivre(int code_livre);
};

#endif