#pragma once
#include "project.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <memory>


class element
{

private:
    position _p;
    taille _t;

public:
    element(position const & p, taille const & t):
        _p(p), _t(t){}

    element(unsigned int x, unsigned int y, int w, int h):
        _p(x,y), _t(w,h){}

    position pos() const;
    taille tai() const;
    void setpos(unsigned int x, unsigned int y);

    virtual char typeobjet() const = 0;

    friend std::ostream& operator <<(std::ostream &os, element const & e);
};

class elementamovible: public element{

private:
    direction _d;

public:
    elementamovible(direction const & d, unsigned int x, unsigned int y, int w, int h):
        element(x,y,w,h), _d(d){};

    elementamovible(direction const & d, position const & p, taille const & t):
        element(p,t), _d(d){};

    direction dir() const;
    void setdir(const direction &d);

};

class pacman: public elementamovible{

private:
    int _invicibilite;

public:
    pacman(direction const & d, unsigned int x, unsigned int y):
        elementamovible(d,x,y,13,13), _invicibilite(0){}

    pacman(direction const & d, position const & pos):
        elementamovible(d, pos, taille(13,13)){}

    char typeobjet() const override {
        return 'P';
    }

    bool invicible() const {
        return _invicibilite > 0;
    }

    void decrementerinvincible() {
        if(invicible()){
            --_invicibilite;
        }
    }

    void devenirinvincible() {
        _invicibilite += 200;
    }

};

class fantome: public elementamovible{

public:
    fantome(direction const & d, unsigned int x, unsigned int y):
        elementamovible(d,x,y,20,20){}

    fantome(direction const & d, position const & pos, taille const & tai):
        elementamovible(d, pos, tai){}

    char typeobjet() const override {
        return 'F';
    }
};

class pacgommes: public element{

public:
    pacgommes(unsigned int x, unsigned int y):
        element(x,y,3,3){}

    char typeobjet() const override {
        return 'G';
    }
};

class mur: public element{

private:
    mur(position const & p, taille const & t):
        element(p,t){};

    /*
    mur(int x, int y, unsigned int w, unsigned int h):
        element(x,y,w,h){};*/

public:

    static std::unique_ptr<mur> fabrique(position const & p, taille const & t){
        if(t.w() < 10 || t.h() < 10){
            return std::unique_ptr<mur>(new mur(p,t));
        }

        return std::unique_ptr<mur>(nullptr);
    }

    /*
    static std::unique_ptr<mur> fabrique(int x, int y, unsigned int w, unsigned int h){
        if(w < 10 || h < 10){
            return std::make_unique<mur>(new mur(x,y,w,h));
        }

        return std::make_unique<mur>(nullptr);
    }*/

    char typeobjet() const override {
        return 'M';
    }

    ~mur() = default;
};


