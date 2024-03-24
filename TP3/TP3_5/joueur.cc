#include "joueur.hh"

void Joueur::setTaille(unsigned int w, unsigned int h){
    _taille.setW(w);
    _taille.setH(h);
}

direction Joueur::dir(){
    return _direction;
}

int Joueur::xmax(){
    return _xmax;
}

int Joueur::xmin(){
    return _xmin;
}

void Joueur::malus(){
    unsigned int new_width = _taille.w() * 2;
    if(new_width > 100) new_width = 100;

    setTaille(new_width, _taille.h());
}

void Joueur::bonus(){
    unsigned int new_width = _taille.w() / 2;
    if(new_width < 3) new_width = 3;

    setTaille(new_width, _taille.h());
}

std::string Joueur::typeObjet(){
    return "J";
}
