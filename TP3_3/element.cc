#include "element.hh"

Position Element::accesposition(){
    return _position;
}

Taille Element::accestaille(){
    return _taille;
}

void Element::setPosition(Position p){
    _position.setX(p.getX());
    _position.setY(p.getY());
}

void Element::setTaille(Taille t){
    _taille.setHauteur(t.getHauteur());
    _taille.setlargeur(t.getLargeur());
}

std::string Element::tostring(){
    std::ostringstream out;
    out << _position.tostring() << _taille.tostring();
    return out.str();
}

bool Element::contientPosition(Position p){
    return p.getX() >= _position.getX()
    && p.getY() >= _position.getY()
    && p.getX() <= (_position.getX() + _taille.getLargeur())
    && p.getY() <= (_position.getY() + _taille.getHauteur());
}
