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
        while (tete != nullptr) {
            Noeud<T>* aSupprimer = tete;
            tete = tete->getSuivant();
            delete aSupprimer; 
        }
    }

    Liste(const Liste<T>&) = delete;

    Liste&operator=(const Liste<T>&liste)=delete;

    void ajouter(T info){
        Noeud<T>* nouveau = new Noeud<T>(info);
        nouveau->setSuivant(tete);
        tete=nouveau;
    }

    void supprimer(T info){
        //Liste vide
        if(tete==nullptr) throw "Liste vide";

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
        
        if(courant==nullptr) throw "L'element n'a pas ete trouve";

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