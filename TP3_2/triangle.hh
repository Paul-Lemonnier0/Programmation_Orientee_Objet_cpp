#ifndef TRIANGLE_HH
#define TRIANGLE_HH

#include "figure.hh"

class Triangle: public Figure{

    private:
        Point _point2, _point3;

    public:
        Triangle(Figure const & f, Point const & point2, Point const & point3);
        Triangle(Couleur couleur, Point const & point, Point const & point2, Point const & point3);
        ~Triangle();

        Point point2();
        Point point3();
        void setPoint2(Point point);
        void setPoint3(Point point);

        std::string tostring();
};

#endif // TRIANGLE_HH
