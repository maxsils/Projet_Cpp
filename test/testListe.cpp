#include "../src/Noeud.h"
#include "../src/Liste.h"
#include "../src/Album.h"
#include "../src/BD.h"
#include "../src/Piece_theatre.h"
#include "../src/Recueil_poesie.h"
#include "../src/Roman.h"
#include "../src/Bibliotheque.h"
#include "../src/Reseau.h"
#include "../src/Adherent.h"
using namespace std ;

int main(){
    
    Liste<int*> liste;
    int*a=new int(2);
    int*b=new int(3);
    int*c=new int(4);
    int*d=new int(5);

    liste.ajouter(a);
    liste.ajouter(b);
    liste.ajouter(d);
    liste.ajouter(c);

    try {
        cout << "Liste apres ajout :\n";
        liste.afficherTout();

        cout << "Suppression de 1 (tete) :\n";
        liste.supprimer(a);
        liste.afficherTout();

        cout << "Suppression de 3 (milieu) :\n";
        liste.supprimer(c);
        liste.afficherTout();

        cout << "Suppression de 2 :\n";
        liste.supprimer(d);
        liste.afficherTout();

        cout << "Suppression de 4 (milieu) :\n";
        liste.supprimer(b);
        liste.afficherTout();
        liste.supprimer(d);
    }
    catch(string e){
        cout<<e<<"\n";
    }
    cout<<"FIN";
}