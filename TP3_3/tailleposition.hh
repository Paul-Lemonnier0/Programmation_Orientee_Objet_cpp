#ifndef TAILLEPOSITION_HH
#define TAILLEPOSITION_HH
#pragma once
#include <sstream>
#include <string>
#include <iostream>

using coordonnee = int;

class Position {
    private: coordonnee _x, _y;

    public:
        Position(coordonnee x, coordonnee y) {
            _x = x;
            _y = y;
        }

        Position(Position const & p){
            _x = p._x;
            _y = p._y;
        }

        coordonnee getX();
        coordonnee getY();
        void setX(coordonnee x);
        void setY(coordonnee y);
        bool comparaison(Position p);
        std::string tostring();
};


class Taille {
    private: coordonnee _largeur, _hauteur;

    public:
        Taille(coordonnee h, coordonnee l){
            _largeur = l;
            _hauteur = h;
        }

        Taille(Taille const & t){
            _largeur = t._largeur;
            _hauteur = t._hauteur;
        }

        coordonnee getLargeur();
        coordonnee getHauteur();

        void setHauteur(coordonnee h);
        void setlargeur(coordonnee l);
        std::string tostring();
};




#endif // TAILLEPOSITION_HH
