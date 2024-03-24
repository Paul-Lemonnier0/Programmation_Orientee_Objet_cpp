#include "position.hh"

coordonnee Position::x(){
    return _x;
}

coordonnee Position::y(){
    return _y;
}

void Position::setX(int x){
    _x = x;
}

void Position::setY(int y){
    _y = y;
}

bool Position::egale(const Position &p){
    return _x == p._x && _y == p._y;
}

bool Position::differente(const Position &p){
    return !egale(p);
}

std::string Position::tostring(){
    return "(" + std::to_string(_x) + ";" + std::to_string(_y) + ")";
}
