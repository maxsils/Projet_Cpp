#ifndef Roman_h
#define Roman_h
#include "Livre.h"
#include <iostream>
#include <string> 
using namespace std;

class Roman : public Livre {
    private :
        string genre;
    public :
        Roman();
        Roman(const Livre&l, string);
        void affiche();
        string getgenre();
        friend ostream& operator<<(ostream& out, Roman &r);
};

#endif