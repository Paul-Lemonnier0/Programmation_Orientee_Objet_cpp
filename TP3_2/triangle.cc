#include "triangle.hh"

Triangle::Triangle(Figure const & f, Point const & point2, Point const & point3):
    Figure(f),
    _point2(point2),
    _point3(point3)
{
    std::cout<<"Triangle créé par le constructeur par Figure / Points \n";
}

Triangle::Triangle(Couleur couleur, Point const & point, Point const & point2, Point const & point3):
    Figure(couleur, point),
    _point2(point2),
    _point3(point3)
{
    std::cout<<"Triangle créé par le constructeur par Points \n";
}

Triangle::~Triangle(){
    std::cout<<"Triangle détruit \n";
}

Point Triangle::point2(){
    return _point2;
}

Point Triangle::point3(){
    return _point3;
}

void Triangle::setPoint2(Point point){
    _point2 = point;
}

void Triangle::setPoint3(Point point){
    _point3 = point;
}
