#include "position.h"
#include <iostream>

coordonee position::x() const
{
    return _x;
}

void position::setX(const coordonee &x)
{
    _x = x;
}

coordonee position::y() const
{
    return _y;
}

void position::setY(const coordonee &y)
{
    _y = y;
}

bool position::operator==(const position &p) const
{
      return _x == p._x && _y == p._y;
}

bool position::operator!=(const position &p) const
{
    return _x != p._x || _y != p._y;
}

std::string position::tostring() const
{
    return "(" + std::to_string(_x) + "," + std::to_string(_y) + ")";
}

void position::affiche(std::ostream &out) const{
    out<<this->tostring();
}

bool position::estValide() const
{
    return (_x>=0 && _x<8) && (_y>=0 && _y<8);
}
