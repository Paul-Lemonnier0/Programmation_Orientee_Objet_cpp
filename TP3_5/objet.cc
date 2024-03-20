#include "objet.hh"
#include <iostream>

Position Objet::position(){
    return _position;
}

Taille Objet::taille(){
    return _taille;
}

std::string Objet::tostring(){
    return _position.tostring() + _taille.tostring();
}

bool coordonneeInInterval(coordonnee c, coordonnee start_interval, coordonnee end_interval){
    return c >= start_interval && c <= end_interval;
}

bool Objet::contientPosition(Position p){
    return coordonneeInInterval(p.x(), _position.x(), _position.x() + _taille.w())
    && coordonneeInInterval(p.y(), _position.y(), _position.y() - _taille.h());
}

void Objet::sortieFlux(std::ostream &out){
    out << typeObjet() << " " << _position.tostring();
}
