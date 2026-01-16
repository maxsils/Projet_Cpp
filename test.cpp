#include <iostream>
#include "Livre.h"
#include "BD.h"
#include "Album.h"
#include <string>
using namespace std ;

main(){
    BD asterix = BD(Livre(2684,"MOI","Asterix","Editions",5972800,"tout public"),"Nico");
    asterix.affiche();
    cout << asterix;
    Album album_perso = Album(Livre(82,"bernard","hif","nfi",3591,"tout public"),"photos");
    album_perso.affiche();
    cout<<album_perso;
}