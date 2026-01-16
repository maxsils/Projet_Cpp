#ifndef NOEUD_H
#define NOEUD_H

template <typename T>
class Noeud {
    private:
        T info;
        Noeud<T>* suivant;


    public:
        Noeud(const T& info){
            this->info=info;
            suivant=nullptr;
        }

        Noeud(const T& info,Noeud<T>*suiv){
        this->info=info;
        suivant=suiv;
        }

        ~Noeud(){};

        T getInfo(){
            return info;
        }

        Noeud*getSuivant(){
            return suivant;
        }

        void setInfo(T info){
            this->info=info;
        }

        void setSuivant(Noeud*suiv){
            suivant=suiv;
        }
};

#endif