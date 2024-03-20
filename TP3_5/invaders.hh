#ifndef INVADERS_HH
#define INVADERS_HH
#include "objet.hh"

class Invaders: public Objet {
    private:
        int _xmin, _xmax;
        direction _direction;

    public:
        Invaders(Position const & p, int xmin, int xmax, direction const & d):
            Objet(p, Taille(11, 8)), _xmin(xmin), _xmax(xmax), _direction(d){};

        int xmin();
        int xmax();
        direction dir();

        std::string typeObjet() override;
};

#endif // INVADERS_HH
