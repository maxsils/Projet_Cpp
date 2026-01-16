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

    Liste(const Liste<T>& liste){
        tete=nullptr;
        if(liste.tete==nullptr) return;

        this->tete=new Noeud<T>(liste.tete->getInfo());
        Noeud<T>*courant=tete;
        Noeud<T>*courantCopier=liste.tete->getSuivant();

        while(courantCopier!=nullptr){
            Noeud<T>*nouveau=new Noeud<T>(courantCopier->getInfo());
            courant->setSuivant(nouveau);
            courant=nouveau;
            courantCopier=courantCopier->getSuivant();
        }
    }

    Liste&operator=(const Liste<T>&liste){
        if(this!=&liste){
            Liste<T>copie(liste);
            Noeud<T>*aSupprimer=tete;
            tete=copie.getTete();
            copie.tete=aSupprimer;
        }
        return *this;
    }

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