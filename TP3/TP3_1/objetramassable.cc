#include "objetramassable.hh"

ObjetRamassable::ObjetRamassable(Position p, Taille t, int nbPoints):
    Element(p, t), _nbPoints(nbPoints){}

ObjetRamassable::ObjetRamassable(coordonnee x, coordonnee y, coordonnee h, coordonnee l, int nbPoints):
    Element(x, y, h, l), _nbPoints(nbPoints){}

void ObjetRamassable::setNbPoints(int points){
    _nbPoints = points;
}

int ObjetRamassable::nbPoints(){
   return  _nbPoints;
}

std::string ObjetRamassable::tostring() {
    std::ostringstream out;
    out <<"objet "<<Element::tostring()<<" "<<this->_nbPoints<<"pts";
    return out.str();
}
