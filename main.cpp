#include "src/Noeud.h"
#include "src/Liste.h"
#include "src/Album.h"
#include "src/BD.h"
#include "src/Piece_theatre.h"
#include "src/Recueil_poesie.h"
#include "src/Roman.h"
#include "src/Bibliotheque.h"
#include "src/Reseau.h"
#include "src/Adherent.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "=== DEMARRAGE DU SYSTEME DE GESTION DE BIBLIOTHEQUE ===\n" << endl;

    // ---------------------------------------------------------
    // 1. Creation du reseau
    // ---------------------------------------------------------
    cout << "1. [Creation] Initialisation du Reseau national..." << endl;
    Reseau monReseau("Reseau National de France");

    // ---------------------------------------------------------
    // 2. Ajout de plusieurs bibliotheques au reseau
    // ---------------------------------------------------------
    cout << "2. [Configuration] Creation et connexion des bibliotheques..." << endl;
    
    // Création des bibliothèques
    Bibliotheque biblioParis("Biblio Paris", "Paris");
    Bibliotheque biblioLyon("Biblio Lyon", "Lyon");

    // Connexion bidirectionnelle (Le réseau connait la biblio, la biblio connait le réseau)
    monReseau.ajouterBibliotheque(biblioParis);
    biblioParis.setReseau(&monReseau);

    monReseau.ajouterBibliotheque(biblioLyon);
    biblioLyon.setReseau(&monReseau);

    // ---------------------------------------------------------
    // 3. Achat de livres par les bibliotheques
    // ---------------------------------------------------------
    cout << "3. [Stock] Achat des livres..." << endl;

    // Livre 1 : Un Roman acheté par Paris (ISBN 100)
    // On utilise 'new' car la Liste stocke des pointeurs et gérera la mémoire
    Roman* roman1 = new Roman("Victor Hugo", "Les Miserables", "Gallimard", 100, "Adulte", "Historique");
    biblioParis.achatLivre(*roman1);
    cout << "   -> Paris a achete : Les Miserables (ISBN 100)" << endl;

    // Livre 2 : Une BD achetée par Lyon (ISBN 200)
    BD* bd1 = new BD("Herge", "Tintin au Tibet", "Casterman", 200, "Jeunesse", "Herge");
    biblioLyon.achatLivre(*bd1);
    cout << "   -> Lyon a achete : Tintin au Tibet (ISBN 200)" << endl;

    // Livre 3 : Une Pièce de théâtre achetée par Lyon (ISBN 300)
    Piece_theatre* piece1 = new Piece_theatre("Moliere", "L'Avare", "Larousse", 300, "Tout public", 17);
    biblioLyon.achatLivre(*piece1);
    cout << "   -> Lyon a achete : L'Avare (ISBN 300)" << endl;

    cout << endl;

    // ---------------------------------------------------------
    // 4. Inscription d'un adherent
    // ---------------------------------------------------------
    cout << "4. [Inscription] Nouvel adherent a Paris..." << endl;
    // Adherent inscrit à la bibliothèque de Paris avec une limite de 3 livres
    Adherent adherentJean("Dupont", "Jean", "Paris 14eme", 1, &biblioParis, 3);
    
    cout << "   -> Adherent cree : Jean Dupont (Inscrit a Biblio Paris)" << endl;
    cout << endl;

    // ---------------------------------------------------------
    // 5. Emprunt local
    // ---------------------------------------------------------
    cout << "5. [Emprunt Local] Tentative d'emprunt d'un livre local..." << endl;
    cout << "   -> Jean veut 'Les Miserables' (ISBN 100) qui est a Paris." << endl;
    
    // Jean emprunte le livre 100 directement
    adherentJean.empruntLivre(100);
    
    cout << "   -> Verification des emprunts de Jean :" << endl;
    adherentJean.afficherLivres();
    cout << endl;

    // ---------------------------------------------------------
    // 6. Demande reseau
    // ---------------------------------------------------------
    cout << "6. [Emprunt Reseau] Tentative d'emprunt d'un livre distant..." << endl;
    cout << "   -> Jean veut 'Tintin' (ISBN 200). Ce livre est a Lyon, PAS a Paris." << endl;

    // Etape A : On vérifie si le livre est dispo localement (Simulé ici par une recherche qui échouerait)
    // Etape B : La bibliothèque de Paris demande au réseau
    cout << "   -> [Biblio Paris] : Livre absent. Interrogation du Reseau..." << endl;
    
    // La méthode demandePret va chercher le livre ailleurs, le changer de biblio, et le rendre dispo à Paris
    Livre* livreTransfere = biblioParis.demandePret(200);

    if (livreTransfere != nullptr) {
        cout << "   -> [Succes Reseau] Le livre a ete transfere de Lyon vers Paris !" << endl;
        
        // Etape C : Maintenant que le livre est arrivé à Paris, Jean peut l'emprunter
        cout << "   -> Jean finalise l'emprunt..." << endl;
        adherentJean.empruntLivre(200);
    } else {
        cout << "   -> [Echec] Le livre est introuvable sur le reseau." << endl;
    }

    // ---------------------------------------------------------
    // Verification finale
    // ---------------------------------------------------------
    cout << "\n=== ETAT FINAL ===" << endl;
    cout << "Livres empruntes par Jean :" << endl;
    adherentJean.afficherLivres();

    cout << "\nTransactions sur le Reseau :" << endl;
    monReseau.afficher(); // Affiche les échanges entre bibliothèques

    return 0;
}