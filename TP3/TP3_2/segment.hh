#ifndef SEGMENT_HH
#define SEGMENT_HH

#include "figure.hh"

class Segment: public Figure{

    private:
        Point _point2;

    public:
        Segment(Figure const & f, Point const & point2);
        Segment(Couleur couleur, Point const & point, Point const & point2);
        ~Segment();

        Point point2();
        void setPoint2(Point point);

        std::string tostring();
};

#endif // SEGMENT_HH
