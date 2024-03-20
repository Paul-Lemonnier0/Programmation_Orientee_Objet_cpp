#include "project.h"

project::project()
{

}

void position::setY(unsigned int y)
{
    _y = y;
}

void position::setX(unsigned int x)
{
    _x = x;
}

unsigned int position::x() const
{
    return _x;
}

unsigned int position::y() const
{
    return _y;
}

std::string position::tostring() const
{
    return "(" + std::to_string(_x) + "," + std::to_string(_y) + ")";
}

std::ostream& operator <<(std::ostream& os, position const & p){
    std::string str = p.tostring() + "\n";
    os << str;
    return os;
}

std::string taille::tostring() const
{
    return "[" + std::to_string(_w) + "," + std::to_string(_h) + "]";
}

std::ostream& operator <<(std::ostream& os, taille const & t){
    std::string str = t.tostring() + "\n";
    os << str;
    return os;
}

int taille::w() const
{
    return _w;
}

int taille::h() const
{
    return _h;
}
