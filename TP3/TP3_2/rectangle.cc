#include "rectangle.hh"

Rectangle::Rectangle(Figure const & f, int largeur, int hauteur):
    Figure(f),
    _largeur(largeur),
    _hauteur(hauteur)
{
    std::cout<<"Rectangle créé par le constructeur par Figure / Points \n";
}


Rectangle::Rectangle(Couleur const & couleur, Point const & point, int largeur, int hauteur):
    Figure(couleur, point),
    _largeur(largeur),
    _hauteur(hauteur)
{
    std::cout<<"Rectangle créé par le constructeur par Points \n";
}

Rectangle::~Rectangle(){
    std::cout<<"Rectangle détruit \n";
}

int Rectangle::largeur(){
    return _largeur;
}

int Rectangle::hauteur(){
    return _hauteur;
}

void Rectangle::setLargeur(int largeur){
    _largeur = largeur;
}

void Rectangle::setHauteur(int hauteur){
    _hauteur = hauteur;
}

std::string Rectangle::typeFigure(){
    return "rectangle ";
}

std::string Rectangle::tostring(){
    return typeFigure() + Figure::tostring() + " || (L,H): " + std::to_string(_largeur) + "," + std::to_string(_hauteur) + ")\n";
}

bool Rectangle::estCarre1(){
    return _largeur == _hauteur;
}

bool Rectangle::estCarre2(){
    return estCarre1();
}


