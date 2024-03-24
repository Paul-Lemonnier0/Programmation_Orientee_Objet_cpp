#pragma once
#include <string>

using coordonee = int;

class position
{
private:
    coordonee _x, _y;

public:
    position(coordonee x, coordonee y):_x(x), _y(y){};
    position(position const & p): _x(p._x), _y(p._y){};

    coordonee x() const;
    void setX(const coordonee &x);
    coordonee y() const;
    void setY(const coordonee &y);

    bool operator==(position const & p) const;
    bool operator!=(position const & p) const;
    std::string tostring() const;
    void affiche(std::ostream &out) const;

    bool estValide() const;
};
