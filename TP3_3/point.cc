#include "point.hh"

Point::Point():
    _x(0),
    _y(0)
{
    //std::cout<<"Point créé par le constructeur par défaut \n";
};

Point::Point(coordonnee x, coordonnee y):
    _x(x),
    _y(y)
{
    //std::cout<<"Point créé par le constructeur par coordonnées \n";
};

Point::Point(Point const & p):
    _x(p._x),
    _y(p._y)
{
    //std::cout<<"Point créé par le constructeur par recopie \n";
}

Point::~Point(){
    //std::cout<<"Point détruit \n";
}

coordonnee Point::x(){
    return _x;
}

coordonnee Point::y(){
    return _y;
}

void Point::setX(coordonnee x){
    _x = x;
}

void Point::setY(coordonnee y){
    _y = y;
}

std::string Point::tostring(){
    return "(" + std::to_string(_x) + ";" + std::to_string(_y) + ")";
}

bool Point::memePoint(Point const & p){
    return p._x == _x && p._y == _y;
}

void Point::translation(const Point &v){
    _x = _x + v._x;
    _y = _y + v._y;
}
