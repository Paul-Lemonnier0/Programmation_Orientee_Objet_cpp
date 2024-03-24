#pragma once
#include <string>

enum class direction {stop, droite, gauche, haut, bas};

class project
{
public:
    project();
};

class position{

private:
    unsigned int _x, _y;

public:
    position(unsigned int x, unsigned int y):
        _x(x), _y(y){};

    position(position const & p) = default;


    unsigned int x() const;
    unsigned int y() const;
    void setX(unsigned int x);
    void setY(unsigned int y);

    std::string tostring() const;

    bool operator ==(position const & p){
        return _x == p._x && _y == p._y;
    }

    bool operator !=(position const & p){
        return _x != p._x || _y != p._y;
    }

    friend std::ostream& operator <<(std::ostream& os, position const & p);

};

class taille{

private:
    int _w, _h;

public:
    taille(int w, int h):
        _w(w), _h(h){}

    taille(taille const & t) = default;

    int w() const;
    int h() const;

    std::string tostring() const;

    friend std::ostream& operator <<(std::ostream& os, taille const & t);
};
