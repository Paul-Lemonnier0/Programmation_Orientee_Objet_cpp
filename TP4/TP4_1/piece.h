#pragma once
#include "position.h"
#include <memory>
#include <vector>

enum class couleur {blanc, noir};

class piece
{
    private:
        couleur _couleur;
        position _pos;
        int _valeur;
        std::string _symbole;


    public:
        piece(couleur color, position const & pos, int valeur, std::string const & sym):
            _couleur(color), _pos(pos), _valeur(valeur), _symbole(sym){};

        virtual ~piece() = default;
        virtual std::unique_ptr<piece> clone() const = 0;

        couleur coul() const;
        position pos() const;
        void setPos(const position &pos);
        int valeur() const;
        std::string symbole() const;

        std::string tostring() const;
        std::string toshortstring() const;

        virtual std::vector<position> deplacementsPossible() const = 0;

        void afficheDeplacementsPossibles();
        void setDeplacements(const std::vector<position> &deplacements);
        bool accepterPosition(position const & p);
        bool deplacement(position const & p);

};

class pion: public piece{
public:
    pion(couleur color, position const & pos):
            piece(color, pos, 1, "P"){};

    std::unique_ptr<piece> clone() const override{
        return std::make_unique<pion>(*this);
    };

    std::vector<position> deplacementsPossible() const override;
};

class cavalier: public piece{
    public:
        cavalier(couleur color, position const & pos):
            piece(color, pos, 3, "C"){};

        std::unique_ptr<piece> clone() const override{
            return std::make_unique<cavalier>(*this);
        }

        std::vector<position> deplacementsPossible() const override;
};

class dame: public piece{
    public:
        dame(couleur color, position const & pos):
            piece(color, pos, 9, "D"){};

        std::unique_ptr<piece> clone() const override{
            return std::make_unique<dame>(*this);
        }

        std::vector<position> deplacementsPossible() const override;
};

class roi: public piece{
    public:
        roi(couleur color, position const & pos):
            piece(color, pos, 20, "R"){};

        std::unique_ptr<piece> clone() const override{
            return std::make_unique<roi>(*this);
        }

        std::vector<position> deplacementsPossible() const override;
};


