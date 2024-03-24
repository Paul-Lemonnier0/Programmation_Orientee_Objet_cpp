#include "tailleposition.hh"
#include <iostream>


//POSITION


coordonnee Position::getX() {
    return _x;
}

coordonnee Position::getY() {
    return _y;
}

void Position::setX(coordonnee x) {
    _x = x;
}

void Position::setY(coordonnee y) {
    _y = y;
}

bool Position::comparaison(Position p){
    return (_x == p.getX() and _y == p.getY());
}

void Position::afficher(){
    std::cout<<"X: "<<_x<<" ; Y: "<<_y<<std::endl;
}


//TAILLE


coordonnee Taille::getLargeur(){
    return _largeur;
}

coordonnee Taille::getHauteur(){
    return _hauteur;
}

void Taille::setHauteur(coordonnee h){
    _hauteur = h;
}

void Taille::setlargeur(coordonnee l){
    _largeur = l;
}

