#ifndef ADHERENT_H
#define ADHERENT_H
#include <iostream>
using namespace std;

class Adherent
{
    private:
        string nom,prenom,adresse;
        int num_adherent;
        int code_bibliotheque;
        //Livre* liste de livre
        int nbr_emprunt_max;
    public:
        Adherent();
        void EmpruntLivre(int code_livre);
        void RendreLivre(int code_livre);
};

#endif