#include "figure.hh"

Figure::Figure(Couleur const & couleur, coordonnee x, coordonnee y):
    _couleur(couleur),
    _point(x, y)
{
    std::cout<<"Figure créé par le constructeur par coordonnées \n";
}

Figure::Figure(Couleur const & couleur, Point const & point):
    _couleur(couleur),
    _point(point)
{
    std::cout<<"Figure créé par le constructeur par Point \n";
}

Figure::Figure(Figure const & f):
    _couleur(f._couleur),
    _point(f._point)
{
    std::cout<<"Figure créé par le constructeur par recopie \n";
}

Figure::~Figure(){
    std::cout<<"Figure détruit \n";
}

Couleur Figure::couleur(){
    return _couleur;
}

Point Figure::point(){
    return _point;
}

void Figure::setCouleur(Couleur couleur){
    _couleur = couleur;
}
void Figure::setPoint(Point point){
    _point = point;
}

std::string Figure::tostring(){
    return "RGB(" + std::to_string(_couleur.R) + ", " + std::to_string(_couleur.G) + ", " + std::to_string(_couleur.B) + ") || position: " + _point.tostring();
}

bool Figure::memeOrigine(Figure const &f){
    return _point.memePoint(f._point);
}

void Figure::translation(Point const & vecteur){
    _point.translation(vecteur);
}

bool Figure::estCarre2(){
    return false;
}

std::string Figure::typeFigure(){
    return "figure ";
}
