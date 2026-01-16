#ifndef BD_h
#define BD_h
#include "Livre.h"
#include <iostream>
#include <string> 
using namespace std;

class BD : public Livre {
    private :
        string dessinateur;
    public :
        BD(const Livre&l, string);
        void affiche();
        string getdessinateur();
        friend ostream& operator<<(ostream& out, BD &bd);
};

#endif