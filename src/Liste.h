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
    // Constructeurs et destructeur
    Liste(){
        tete=nullptr;
    }

    ~Liste(){
        while (tete != nullptr) {
            Noeud<T>* aSupprimer = tete;
            tete = tete->getSuivant();
            delete aSupprimer; 
        }
    }

    // Interdiction de copie
    Liste(const Liste<T>&) = delete;
    Liste&operator=(const Liste<T>&liste)=delete;

    // Ajout et suppression de noeuds
    void ajouter(T info){
        Noeud<T>* nouveau = new Noeud<T>(info);
        nouveau->setSuivant(tete);
        tete=nouveau;
    }

    void supprimer(T info){
        //Liste vide
        if(tete==nullptr) throw string("Liste vide");

        Noeud<T>*precedent=nullptr;
        Noeud<T>*courant=tete;

        //Suppression du premiere noeud
        if(courant->getInfo()==info){
            tete=courant->getSuivant();
            delete courant;
            return;
        }
        //Cas general
        while(courant!=nullptr&&(courant->getInfo()!=info)){
            precedent=courant;
            courant=courant->getSuivant();  
        }
        
        if(courant==nullptr) throw string("L'element n'a pas ete trouve");

        precedent->setSuivant(courant->getSuivant());
        delete courant;
    }

    void afficherTout() const {
        Noeud<T>*courant=tete;
        while(courant!=nullptr){
            cout<<*courant->getInfo()<<"\n";
            courant=courant->getSuivant();
        }
    }

    Noeud<T>* getTete(){
        return tete;
    }
};

#endif