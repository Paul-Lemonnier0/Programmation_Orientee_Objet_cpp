#ifndef OBJETRAMASSABLE_HH
#define OBJETRAMASSABLE_HH

#include "element.hh"

class ObjetRamassable: public Element{
    private: int _nbPoints;

    public:
        ObjetRamassable(Position p, Taille t, int nbPoints);
        ObjetRamassable(coordonnee x, coordonnee y, coordonnee h, coordonnee l, int nbPoints);

        void setNbPoints(int points);
        int nbPoints();

        std::string tostring();
};

#endif // OBJETRAMASSABLE_HH
