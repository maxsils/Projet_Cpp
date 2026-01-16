#include "Noeud.h"
#include "Liste.h"

int main() {
    Liste<int> liste;
    liste.ajouter(2); // a
    liste.ajouter(3); // b
    liste.ajouter(4); // c
    liste.ajouter(1); // d

    try {
        cout << "Liste apres ajout :\n";
        liste.afficherTout();

        cout << "Suppression de 1 (tete) :\n";
        liste.supprimer(1);
        liste.afficherTout();

        cout << "Suppression de 3 (milieu) :\n";
        liste.supprimer(3);
        liste.afficherTout();

        cout << "Suppression de 2 :\n";
        liste.supprimer(2);
        liste.afficherTout();

        cout << "Suppression de 4 (milieu) :\n";
        liste.supprimer(4);
        liste.afficherTout();
        liste.supprimer(1);
    }
    catch(char const* e){
        cout<<e<<"\n";
    }
    cout<<"FIN";
}