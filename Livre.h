#ifndef Livre_h
#define Livre_h
#include <iostream>
#include <string> 
using namespace std;

class Livre{
    protected :
        int code;
        string auteur;
        string titre;
        string editeur;
        int isbn;
        string publics;
        string etat;
    public : 
        // Constructeurs
        Livre();
        Livre(int code_livre,string auteur_livre,string titre_livre,string editeur_livre,int isbn_livre,string public_livre);

        // Permet de changer d'etat ("libre","emprunté","prêté")
        void changer_etat(string);
        void etatlibre();
        void etatemprunte();
        void etatprete();
        
        // Virtual functions
        virtual void affiche();

        // friend operator
        friend ostream& operator<<(ostream& out, Livre &L);

        // getters
        int getcode();
        string getetat();
    };

#endif