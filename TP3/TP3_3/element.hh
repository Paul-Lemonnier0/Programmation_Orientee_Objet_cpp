#ifndef ELEMENT_HH
#define ELEMENT_HH
#pragma once

#include "tailleposition.hh"

class Element {
  private:
       Position _position;
       Taille _taille;

  public:
       Element(coordonnee x, coordonnee y, coordonnee h, coordonnee l):
           _position(Position(x,y)),
           _taille(Taille(h,l)){}

       Element(Position p, Taille t):
           _position(p),
           _taille(t){}

       void setPosition(Position p);
       void setTaille(Taille t);

       Position accesposition();
       Taille accestaille();

       bool contientPosition(Position p);

       std::string tostring();
};

#endif // ELEMENT_HH
