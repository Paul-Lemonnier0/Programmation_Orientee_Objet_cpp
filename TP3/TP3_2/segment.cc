#include "segment.hh"

Segment::Segment(Figure const & f, Point const & point2):
    Figure(f),
    _point2(point2)
{
    std::cout<<"Segment créé par le constructeur par Figure / Points \n";
}

Segment::Segment(Couleur couleur, Point const & point, Point const & point2):
    Figure(couleur, point),
    _point2(point2)
{
    std::cout<<"Segment créé par le constructeur par Points \n";
}

Segment::~Segment(){
    std::cout<<"Segment détruit \n";
}

Point Segment::point2(){
    return _point2;
}

void Segment::setPoint2(Point point){
    _point2 = point;
}
