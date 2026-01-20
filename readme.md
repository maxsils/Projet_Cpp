# Gestion de Reseau de Bibliotheques (C++)

Ce projet est une application C++ simulant la gestion d'un reseau de bibliotheques interconnectees. Il permet de gerer les adherents, les stocks de livres varies, les emprunts locaux, ainsi que les echanges de livres entre bibliotheques via un reseau centralise.

## Fonctionnalites Principales

### 1. Gestion des Ressources (Livres)
Le projet utilise le polymorphisme pour gerer differents types d'ouvrages heritant d'une classe abstraite de base.
* Types supportes : Romans, Bandes Dessinees (BD), Pieces de theatre, Recueils de poesie, Albums.
* Gestion d'etat : Un livre peut etre "libre", "emprunte" ou "prete" (a une autre bibliotheque).

### 2. Systeme de Bibliotheques
Chaque bibliotheque est une entite autonome qui :
* Gere son propre catalogue de livres.
* Gere ses adherents (inscriptions, limites d'emprunt).
* Gere les emprunts et retours locaux.

### 3. Reseau Inter-Bibliotheques
Un objet Reseau connecte plusieurs bibliotheques entre elles :
* Emprunt Distant : Si un livre n'est pas disponible dans la bibliotheque de l'adherent, le systeme interroge le reseau pour le trouver ailleurs.
* Gestion de Transactions : Le reseau stocke les transactions de prets entre bibliotheques (qui a prete quoi a qui).

### 4. Structures de Donnees Personnalisees
Le projet n'utilise pas les conteneurs de la STL (std::vector, std::list) mais implemente sa propre structure de donnees generique :
* Liste Chainee Template (Liste<T>) : Utilisee pour stocker les livres, les adherents et les bibliotheques.
* Gestion manuelle de la memoire (pointeurs et destructeurs).

## Architecture Technique

Le projet repose sur une conception Orientee Objet stricte.

### Structure des Classes
* Reseau : Contient une liste de bibliotheques (Aggregation).
* Bibliotheque : Contient un catalogue de livres (Composition) et pointe vers le Reseau.
* Adherent : Inscrit dans une bibliotheque, possede une liste d'emprunts.
* Livre (Classe Abstraite) : Classe mere definissant les attributs communs (ISBN, auteur, titre).
  * Classes derivees : Roman, BD, Album, Piece_theatre, Recueil_poesie.
* Liste<T> & Noeud<T> : Implementation generique des listes chainees pour la gestion des collections.

### Fichiers Sources
* Reseau.h/cpp : Gestionnaire central des echanges.
* Bibliotheque.h/cpp : Gestionnaire local (adherents, catalogue).
* Adherent.h/cpp : Acteur effectuant les emprunts.
* Livre.h : Definition abstraite.
* Sous-classes (BD.h, Roman.h, etc.) : Implementations specifiques.
* Liste.h & Noeud.h : Structure de donnees.

## Installation et Compilation

### Prerequis
* Un compilateur C++ compatible C++11 ou superieur (g++, clang++).

### Compilation manuelle
Placez-vous dans le dossier racine du projet contenant les sources :

g++ -o exe_files/main.exe main.cpp src/*.cpp -std=c++11 -Wall

### Execution
exe_files/main.exe

## Exemple d'Utilisation

Le main.cpp execute le scenario suivant :

1. Creation du reseau.
2. Ajout de plusieurs bibliotheques au reseau (ex: "Biblio Marseille", "Biblio Lille").
3. Achat de livres par les bibliotheques (BD, Romans, etc.).
4. Inscription d'un adherent.
5. Emprunt local : L'adherent emprunte un livre disponible dans sa bibliotheque.
6. Demande reseau : L'adherent demande un livre absent localement. Sa bibliotheque interroge le Reseau, qui localise le livre ailleurs et effectue le transfert.

## Auteurs
**RODRIGUES Nicola** & **SOLLIER Jules**

Projet realise dans un cadre academique pour demontrer la maitrise de la Programmation Orientee Objet (POO), de la gestion de la memoire et des structures de donnees en C++.