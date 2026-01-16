#include <iostream>
#include "Livre.h"
#include "BD.h"
#include <string>
using namespace std ;

main(){
    BD asterix = BD(Livre(2684,"MOI","Asterix","Editions",5972800,"tout public"),"Nico");
    asterix.affiche();
}