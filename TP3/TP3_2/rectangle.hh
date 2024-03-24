#ifndef RECTANGLE_HH
#define RECTANGLE_HH

#include "figure.hh"

class Rectangle: virtual public Figure{
    private:
        int _largeur, _hauteur;

    public:
        Rectangle(Figure const & f, int largeur, int hauteur);
        Rectangle(Couleur const & couleur, Point const & point, int largeur, int hauteur);

        int largeur();
        int hauteur();
        void setLargeur(int largeur);
        void setHauteur(int hauteur);

        ~Rectangle();

        std::string typeFigure() const override;
        std::string tostring() const;

        bool estCarre1();
        bool estCarre2();
};

#endif // RECTANGLE_HH
