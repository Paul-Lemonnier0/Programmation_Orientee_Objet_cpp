#include "tailleposition.hh"

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

std::string Position::tostring(){
    std::ostringstream out;
    out <<"("<<_x<<","<<_y<<")";
    return out.str();
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

std::string Taille::tostring(){
    std::ostringstream out;
    out <<"["<<_hauteur<<","<<_largeur<<"]";
    return out.str();
}


