#ifndef LISTE_H
#define LISTE_H

#include "Noeud.h"
#include <iostream>
using namespace std;

template <typename T>
class Liste {
private:
    Noeud<T>* tete;
public:
    Liste(){
        tete=nullptr;
    }

    ~Liste(){
        Noeud<T>* courant = tete;
        while (courant != nullptr) {
            Noeud<T>* aSupprimer = courant;
            courant = courant->getSuivant();
            delete aSupprimer; 
        }
    }

    void ajouter(T info){
        Noeud<T>* nouveau = new Noeud<T>(info);
        nouveau->setSuivant(tete);
        tete=nouveau;
    }

    void afficherTout(){
        Noeud<T>*courant=tete;
        while(courant!=nullptr){
            cout<<courant->getInfo()<<"\n";
            courant=courant->getSuivant();
        }
    }

    Noeud<T>* getTete(){
        return tete;
    }
};

#endif