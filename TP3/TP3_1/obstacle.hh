#ifndef OBSTACLE_HH
#define OBSTACLE_HH
#include "element.hh"


class Obstacle: public Element{

    public:
        Obstacle(Position p, Taille t);
        Obstacle(coordonnee x, coordonnee y, coordonnee h, coordonnee l);
};

#endif // OBSTACLE_HH
