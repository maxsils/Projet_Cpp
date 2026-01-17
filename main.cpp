#include "src/Noeud.h"
#include "src/Liste.h"
#include "src/Album.h"
#include "src/BD.h"
#include "src/Piece_theatre.h"
#include "src/Recueil_poesie.h"
#include "src/Roman.h"
#include "src/Bibliotheque.h"
#include "src/Reseau.h"

int main() {
    // Liste<int> liste;
    // liste.ajouter(2); // a
    // liste.ajouter(3); // b
    // liste.ajouter(4); // c
    // liste.ajouter(1); // d

    // try {
    //     cout << "Liste apres ajout :\n";
    //     liste.afficherTout();

    //     cout << "Suppression de 1 (tete) :\n";
    //     liste.supprimer(1);
    //     liste.afficherTout();

    //     cout << "Suppression de 3 (milieu) :\n";
    //     liste.supprimer(3);
    //     liste.afficherTout();

    //     cout << "Suppression de 2 :\n";
    //     liste.supprimer(2);
    //     liste.afficherTout();

    //     cout << "Suppression de 4 (milieu) :\n";
    //     liste.supprimer(4);
    //     liste.afficherTout();
    //     liste.supprimer(1);
    // }
    // catch(char const* e){
    //     cout<<e<<"\n";
    // }
    // cout<<"FIN";
    // std::cout << "Lancement du programme..." << std::endl;
    // BD bd;
    // Album album;
    // Recueil_poesie recueil_poesie;
    // Bibliotheque biblio;
    // try{
    // biblio.achatLivre(bd);
    // biblio.achatLivre(album);
    // biblio.achatLivre(recueil_poesie);
    // biblio.afficherLivres();
    // }
    // catch(string a){cout<<a;}

    // try{biblio.supprimerLivre(0);}
    // catch(string e){cout<<e;}

    // cout<<"Essaie categorie BD"<<endl;
    // biblio.afficherLivres("BD");
    // cout<<"Essaie categorie Recueil de poesie"<<endl;
    // biblio.afficherLivres("Recueil de poesie");

    cout<<"----------------------DEBUT----------------------\n";
    Reseau res2=Reseau("i");
    Reseau reseau=Reseau("Biblio Super");
    
    Bibliotheque biblio1=Bibliotheque("Lille","rue de Lille");
    Bibliotheque biblio2=Bibliotheque("Marseille","rue de Marseille");

    reseau.ajouterBibliotheque(biblio1);
    // reseau.ajouterBibliotheque(biblio2);        //Probleme on peut acheter plusieurs fois le meme livre avec differentes bibliotheques

    BD maBD=BD("Nicola R","Le mangeur de chiens","Goliatte",12345,"Aldulte","Jules S");

    cout<<"On ajoute\n";
    cout<<maBD<<"\n";
    cout<<"a la biblio de Lille\n";
    biblio1.achatLivre(maBD);
    biblio2.achatLivre(maBD);

    cout<<"\n";
    cout<<"On regarde les livre de la biblio de Lille\n";
    cout<<"Debut\n";
    biblio1.afficherLivres();
    cout<<"fin\n";

    cout<<"\n";
    cout<<"On regarde les livre de la biblio de Marseille\n";
    cout<<"Debut\n";
    biblio2.afficherLivres();
    cout<<"fin\n";

    cout<<"\n";
    cout<<"Marseille demande un pret pour 12345\n";
    biblio2.demandePret(12345);
    biblio2.demandePret(1234);

    cout<<"\n";
    cout<<"On regarde une nouvelle fois les livres de Marseille\n";
    cout<<"Debut\n";
    biblio2.afficherLivres();
    cout<<"fin\n";

    cout<<"\n";
    cout<<"On regarde ceux de Lille\n";
    cout<<"Debut\n";
    biblio1.afficherLivres();
    cout<<"fin\n";

    cout<<"\n";
    cout<<"Marseille rend le livre\n";
    biblio2.rendreUnPret(maBD);

    cout<<"\n";
    cout<<"On regarde les livres de Marseille\n";
    cout<<"Debut\n";
    biblio2.afficherLivres();
    cout<<"fin\n";

    cout<<"\n";
    cout<<"On regarde ceux de Lille\n";
    cout<<"Debut\n";
    biblio1.afficherLivres();
    cout<<"fin\n";



    cout<<"-------------FIN-------------";
}