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
    Reseau reseau=Reseau("Super");
    Bibliotheque* Marseille=new Bibliotheque("Marseille","2 rue de La Rose");
    Bibliotheque* Lille=new Bibliotheque("Lille","4 avenue de la bière");

    reseau.ajouterBibliotheque(*Marseille);

    BD bd=BD("Nicola R","Le mangeur de chiens","Goliatte",12345,"Aldulte","Jules S");
    Album album=Album("Jean Batiste","Photo de chiens","Miam",2222,"Chien","Chien");

    Adherent Michel=Adherent("Michel","Michel","Adressze",10,Marseille,4);

    Marseille->achatLivre(bd);
    Marseille->achatLivre(album);

    cout<<"On montre la liste de livre de la biblio de Marseille\n";
    Marseille->afficherLivres();
    cout<<"\n";

    cout<<"Michel emprunte l'album\n";
    Michel.empruntLivre(2222);
    cout<<"\n";

    cout<<"On montre la liste de livre de la biblio de Marseille apres l'emprunt\n";
    Marseille->afficherLivres();
    cout<<"\n";

    cout<<"On affiche les livres de Michel\n";
    Michel.afficherLivres();
    cout<<"\n";

    cout<<"Michel rend son album\n";
    Michel.rendreLivre(2);
    cout<<"\n";

    cout<<"On affiche les livres de Michel\n";
    Michel.afficherLivres();
    cout<<"\n";

    cout<<"On montre la liste de livre de la biblio de Marseille apres le retour\n";
    Marseille->afficherLivres();

}