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
    cout << "Lancement du programme..." << std::endl;
    BD bd;
    Album album;
    Recueil_poesie recueil_poesie;
    Bibliotheque biblio;
    try{
    biblio.achatLivre(bd);
    biblio.achatLivre(album);
    biblio.achatLivre(recueil_poesie);
    biblio.afficherLivres();
    }
    catch(string a){cout<<a;}

    try{biblio.supprimerLivre(0);}
    catch(string e){cout<<e;}

    cout<<"Essaie categorie BD"<<endl;
    biblio.afficherLivres("BD");
    cout<<"Essaie categorie Recueil de poesie"<<endl;
    biblio.afficherLivres("Recueil de poesie");
}