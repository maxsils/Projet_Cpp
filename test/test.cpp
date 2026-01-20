#include <iostream>
#include "../src/Livre.h"
#include "../src/BD.h"
#include "../src/Album.h"
#include "../src/Piece_theatre.h"
#include "../src/Recueil_poesie.h"
#include "../src/Roman.h"
#include <string>
using namespace std ;

main(){
    BD asterix = BD("MOI","Asterix","Editions",5972800,"tout public","Nico");
    asterix.affiche();
    cout << asterix<<endl;
    Album album_perso = Album("bernard","hif","nfi",3591,"tout public","photos");
    album_perso.affiche();
    cout<<album_perso<<endl;
    Piece_theatre piece1 = Piece_theatre("hjghi","hif","nfi",398761,"ihie",19);
    piece1.affiche();
    cout<<piece1<<endl;
    BD bd1;
    cout<<bd1;
    cout<<1;
}