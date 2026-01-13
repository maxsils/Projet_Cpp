#ifndef Album_h
#define Album_h
#include "Livre.h"
#include <iostream>
#include <string> 
using namespace std;

class Album : public Livre {
    private :
        string illustrations;
};

#endif