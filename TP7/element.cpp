#include "element.h"

void element::setpos(unsigned int x, unsigned int y)
{
    _p.setX(x);
    _p.setY(y);
}

position element::pos() const
{
    return _p;
}

taille element::tai() const
{
    return _t;
}

direction elementamovible::dir() const
{
    return _d;
}

void elementamovible::setdir(const direction &d)
{
    _d = d;
}

std::ostream& operator <<(std::ostream& os, element const & e){
    std::string str = e.typeobjet() + e.pos().tostring() + e.tai().tostring() + "\n";
    os << str;
    return os;
}
