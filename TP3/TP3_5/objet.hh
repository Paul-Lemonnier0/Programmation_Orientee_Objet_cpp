#ifndef OBJET_HH
#define OBJET_HH
#include "position.hh"
#include "taille.hh"

enum class direction {stop, droite, gauche};

class Objet
{
    protected:
        Position _position;
        Taille _taille;

    public:
        Objet(Position const & p, Taille const & t):_position(p), _taille(t){};
        Position position();
        Taille taille();

        std::string tostring();

        bool contientPosition(Position p);

        virtual std::string typeObjet() = 0;
        void sortieFlux(std::ostream &out);
};

#endif // OBJET_HH
