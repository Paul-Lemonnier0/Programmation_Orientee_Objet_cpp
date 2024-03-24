#include "parcourselements.hh"

std::size_t ParcoursElements::positionCourante() const
{
    return _positionCourante;
}

void ParcoursElements::passerausuivant()
{
    ++_positionCourante;
}
