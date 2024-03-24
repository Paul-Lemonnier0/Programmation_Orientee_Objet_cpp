#ifndef JOUEUR_HH
#define JOUEUR_HH
#include "objet.hh"

class Joueur: public Objet {

    private:
        int _xmin, _xmax;
        direction _direction;

    public:
        Joueur(Position const & p, Taille const & t, int xmin, int xmax, direction const & d):
            Objet(p, t), _xmin(xmin), _xmax(xmax), _direction(d){};

        void setTaille(unsigned int w, unsigned int h);

        int xmin();
        int xmax();
        direction dir();

        void malus();
        void bonus();

        std::string typeObjet() override;
};

#endif // JOUEUR_HH
