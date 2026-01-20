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
#include <iostream>
using namespace std ;

int main(){
    cout<<"----------------------DEBUT----------------------\n";
    Reseau* reseau=new Reseau("Biblio Super");
    
    Bibliotheque* biblio1=new Bibliotheque("Lille","rue de Lille");
    Bibliotheque* biblio2=new Bibliotheque("Marseille","rue de Marseille");

    reseau->ajouterBibliotheque(*biblio1);
    reseau->ajouterBibliotheque(*biblio2);        //Probleme on peut acheter plusieurs fois le meme livre avec differentes bibliotheques

    BD maBD=BD("Nicola R","Le mangeur de chiens","Goliatte",12345,"Aldulte","Jules S");

    cout<<"On ajoute\n";
    cout<<maBD<<"\n";
    cout<<"a la biblio de Lille\n";
    biblio1->achatLivre(maBD);
    // biblio2.achatLivre(maBD);

    cout<<"\n";
    cout<<"On regarde les livre de la biblio de Lille\n";
    cout<<"Debut\n";
    biblio1->afficherLivres();
    cout<<"fin\n";

    cout<<"\n";
    cout<<"On regarde les livre de la biblio de Marseille\n";
    cout<<"Debut\n";
    biblio2->afficherLivres();
    cout<<"fin\n";

    cout<<"\n";
    cout<<"Marseille demande un pret pour 12345\n";
    biblio2->demandePret(12345);
    biblio2->demandePret(1234);

    cout<<"\n";
    cout<<"On regarde une nouvelle fois les livres de Marseille\n";
    cout<<"Debut\n";
    biblio2->afficherLivres();
    cout<<"fin\n";

    cout<<"\n";
    cout<<"On regarde ceux de Lille\n";
    cout<<"Debut\n";
    biblio1->afficherLivres();
    cout<<"fin\n";

    cout<<"\n";
    cout<<"Marseille rend le livre\n";
    biblio2->rendreUnPret(maBD);

    cout<<"\n";
    cout<<"On regarde les livres de Marseille\n";
    cout<<"Debut\n";
    biblio2->afficherLivres();
    cout<<"fin\n";

    cout<<"\n";
    cout<<"On regarde ceux de Lille\n";
    cout<<"Debut\n";
    biblio1->afficherLivres();
    cout<<"fin\n";



    cout<<"-------------FIN-------------";
}