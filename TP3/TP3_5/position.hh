#pragma once
#include <string>

using coordonnee = unsigned int;

class Position
{
    private:
        coordonnee _x, _y;

    public:
        Position(int x, int y): _x(x), _y(y){};
        Position(Position const & p): _x(p._x), _y(p._y){};

        coordonnee x();
        coordonnee y();

        void setX(int x);
        void setY(int y);

        std::string tostring();
        bool egale(Position const & p);
        bool differente(Position const & p);
};
