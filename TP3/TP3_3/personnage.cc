#include "personnage.hh"

Personnage::Personnage(Position p, Taille t, std::string nom):
    Element(p, t), _nbPoints(0), _nom(nom){}

Personnage::Personnage(coordonnee x, coordonnee y, coordonnee h, coordonnee l, std::string nom):
    Element(x, y, h, l), _nbPoints(0), _nom(nom){}

void Personnage::setNbPoints(int points){
    _nbPoints = points;
}

int Personnage::nbPoints(){
   return  _nbPoints;
}

void Personnage::setNom(std::string nom){
    _nom = nom;
}

std::string Personnage::nom(){
    return _nom;
}

std::string Personnage::tostring() {
    std::ostringstream out;
    out <<"personnage "<<_nom<<" "<<Element::tostring()<<" "<<this->_nbPoints<<"pts";
    return out.str();
}

void Personnage::ramasser(ObjetRamassable obj){
    if(this->contientPosition(obj.accesposition())){
        _nbPoints += obj.nbPoints();
    }
}

