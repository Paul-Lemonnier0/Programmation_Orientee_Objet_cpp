#ifndef POINT_HH
#define POINT_HH
#pragma once

#include <iostream>
#include <string>

using coordonnee = int;

class Point
{
    private:
        coordonnee _x, _y;

    public:
        Point();
        Point(coordonnee x, coordonnee y);
        Point(Point const & p);
        ~Point();

        coordonnee x();
        coordonnee y();

        void setX(coordonnee x);
        void setY(coordonnee y);

        bool memePoint(Point const & p);
        void translation(Point const & v);

        std::string tostring();
};

#endif // POINT_HH
