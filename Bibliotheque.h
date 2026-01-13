#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#include <iostream>
using namespace std;

class Bibliothque{
    private:
        string nom,adresse;
        int code;
        //Liste* liste de livre
    public:
        Bibliothque();
        void AfficherLivres();
        void AfficherLivres(string catégorie);
        //bool Livre EstLibre(int code_livre);
        void DemanderLivre(int ISBN,int code_bibliotheque);
        void AchatLivre(int ISBN);
        void SupprimerLivre(int code_livre);
        void RendreLivre();
};

#endif