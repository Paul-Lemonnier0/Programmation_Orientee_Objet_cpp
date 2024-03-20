#ifndef FIGURE_HH
#define FIGURE_HH
#pragma once
#include "point.hh"

struct Couleur{
    unsigned int R;
    unsigned int G;
    unsigned int B;
};

class Figure
{
    private:
        Couleur _couleur;
        Point _point;

    public:
        Figure(Couleur const & couleur, coordonnee x, coordonnee y);
        Figure(Couleur const & couleur, Point const & point);
        Figure(Figure const & f);
        ~Figure();

        Couleur couleur();
        Point point();

        void setCouleur(Couleur couleur);
        void setPoint(Point point);

        bool memeOrigine(Figure const & f);

        void translation(Point const & vecteur);

        bool estCarre2();

        virtual std::string typeFigure() const;
        std::string tostring();
};

#endif // FIGURE_HH
