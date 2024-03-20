#ifndef PERSONNAGE_HH
#define PERSONNAGE_HH
#pragma once
#include "element.hh"
#include "objetramassable.hh"

class Personnage: public Element{
    private:
        int _nbPoints;
        std::string _nom;

    public:
        Personnage(Position p, Taille t, std::string nom);
        Personnage(coordonnee x, coordonnee y, coordonnee h, coordonnee l, std::string nom);

        void setNbPoints(int points);
        int nbPoints();

        void setNom(std::string nom);
        std::string nom();

        std::string tostring();

        void ramasser(ObjetRamassable obj);
};

#endif // PERSONNAGE_HH
