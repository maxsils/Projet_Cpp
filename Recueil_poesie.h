#ifndef Recueil_poesie_h
#define Recueil_poesie_h
#include "Livre.h"
#include <iostream>
#include <string> 
using namespace std;

class Recueil_poesie : public Livre {
    private :
        string indicateur;
};

#endif