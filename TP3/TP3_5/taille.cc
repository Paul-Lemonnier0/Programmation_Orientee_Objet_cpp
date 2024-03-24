#include "taille.hh"

unsigned int Taille::w()
{
    return _largeur;
}

unsigned int Taille::h()
{
    return _hauteur;
}

void Taille::setW(unsigned int w){
    _largeur = w;
}

void Taille::setH(unsigned int h){
    _hauteur = h;
}

std::string Taille::tostring(){
    return "[" + std::to_string(_largeur) + ";" + std::to_string(_hauteur) + "]";
}
