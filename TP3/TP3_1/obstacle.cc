#include "obstacle.hh"

Obstacle::Obstacle(Position p, Taille t):
    Element(p, t){}

Obstacle::Obstacle(coordonnee x, coordonnee y, coordonnee h, coordonnee l):
    Element(x, y, h, l){}
