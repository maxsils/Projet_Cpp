#ifndef Livre_h
#define Livre_h
#include <iostream>
#include <string> 
using namespace std;

class Livre{
    private :
        int code;
        string auteur;
        string titre;
        string editeur;
        int isbn;
        string publics;
        string etat;
    public : 
        Livre(int,string,string,string,int,string);
        void changer_etat(string);
        
        // Virtual functions
        virtual void affiche();

        // friend operators
        friend ostream& operator<<(ostream& out, Livre &L);
    };

#endif