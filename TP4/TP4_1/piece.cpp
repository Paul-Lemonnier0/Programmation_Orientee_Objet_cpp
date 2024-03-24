#include "piece.h"
#include <iostream>
#include <algorithm>



bool piece::accepterPosition(const position &p)
{
    std::vector<position> deplacementsPossibles = deplacementsPossible();
    for (auto elem : deplacementsPossibles)
    {
        if (p == elem)
        {
            return true;
        }
    }

    return false;
}

bool piece::deplacement(const position &p)
{
    if(accepterPosition(p)){
        pos().setX(p.x());
        pos().setY(p.y());
    }

    return false;
}

void piece::setPos(const position &pos)
{
    _pos = pos;
}

couleur piece::coul() const
{
    return _couleur;
}

position piece::pos() const
{
    return _pos;
}

int piece::valeur() const
{
    return _valeur;
}

std::string piece::symbole() const
{
    return _symbole;
}

std::string piece::toshortstring() const
{
    std::string color = "N";
    if(_couleur == couleur::blanc) color="B";

    return _symbole + color;
}

std::string piece::tostring() const
{
    return toshortstring() + " " + std::to_string(_valeur) + " " + std::to_string(_pos.x()) + " " + std::to_string(_pos.y());
}



void piece::afficheDeplacementsPossibles()
{
    std::cout<<"  12345678"<<std::endl;

    std::string labels[8] {"A", "B", "C", "D", "E", "F", "G", "H"};

    for(int i = 0; i<8; ++i){
        std::cout<<labels[i]<<" ";
        for(int j = 0; j<8; ++j){

            position temp(j,i);

            if(temp == pos()){
                std::cout<<"O";
            }

            else{
                if(accepterPosition(temp)){
                    std::cout<<"x";
                }

                else std::cout<<" ";
            }
        }

        std::cout<<std::endl;
    }
}


std::vector<position> pion::deplacementsPossible() const
{
    std::vector<position> depPossibles;
    if(coul() == couleur::noir){
        position newPos(pos());

        newPos.setY((newPos.y()+1));
        if(newPos.estValide()){
            depPossibles.push_back(newPos);
        }
    }

    else{
        position newPos(pos());

        newPos.setY((newPos.y()-1));
        if(newPos.estValide()){
            depPossibles.push_back(newPos);
        }
    }

    return depPossibles;
}

std::vector<position> cavalier::deplacementsPossible() const
{
    std::vector<position> depPossibles;

    for(int i = -2; i<=2; ++i){
        if(i!=0){
            position newPosTop(pos());
            position newPosBottom(pos());

            if(i != -2 && i != 2){
                newPosTop.setY((newPosTop.y()+2));
                newPosBottom.setY((newPosBottom.y()-2));
            }

            else {
                newPosTop.setY((newPosTop.y()+1));
                newPosBottom.setY((newPosBottom.y()-1));
            }

            newPosTop.setX((newPosTop.x()+i));
            newPosBottom.setX((newPosBottom.x()+i));


            if(newPosTop.estValide()){
                depPossibles.push_back(newPosTop);
            }

            if(newPosBottom.estValide()){
                depPossibles.push_back(newPosBottom);
            }
       }
    }

    return depPossibles;
}


std::vector<position> dame::deplacementsPossible() const
{
    std::vector<position> depPossibles;

    position newPos(pos());
    newPos.setX(newPos.x()-1);

    //Gauche
    while(newPos.estValide()){
        depPossibles.push_back(newPos);
        newPos.setX(newPos.x()-1);
    }

    newPos.setX(pos().x());
    newPos.setX(newPos.x()+1);

    //Droite
    while(newPos.estValide()){
        depPossibles.push_back(newPos);
        newPos.setX(newPos.x()+1);
    }

    newPos.setX(pos().x());
    newPos.setY(newPos.y()-1);

    //Haut
    while(newPos.estValide()){
        depPossibles.push_back(newPos);
        newPos.setY(newPos.y()-1);
    }

    newPos.setY(pos().y());
    newPos.setY(newPos.y()+1);

    //Bas
    while(newPos.estValide()){
        depPossibles.push_back(newPos);
        newPos.setY(newPos.y()+1);
    }

    //Diagonale Haut Gauche

    newPos.setY(pos().y());
    newPos.setY(newPos.y()-1);
    newPos.setX(newPos.x()-1);

    //Bas
    while(newPos.estValide()){
        depPossibles.push_back(newPos);
        newPos.setY(newPos.y()-1);
        newPos.setX(newPos.x()-1);
    }

    //Diagonale Haut Droite

    newPos.setY(pos().y());
    newPos.setX(pos().x());

    newPos.setY(newPos.y()-1);
    newPos.setX(newPos.x()+1);

    //Bas
    while(newPos.estValide()){
        depPossibles.push_back(newPos);
        newPos.setY(newPos.y()-1);
        newPos.setX(newPos.x()+1);
    }

    //Diagonale Bas gauche

    newPos.setY(pos().y());
    newPos.setX(pos().x());

    newPos.setY(newPos.y()+1);
    newPos.setX(newPos.x()-1);

    //Bas
    while(newPos.estValide()){
        depPossibles.push_back(newPos);
        newPos.setY(newPos.y()+1);
        newPos.setX(newPos.x()-1);
    }

    //Diagonale Bas Gauche

    newPos.setY(pos().y());
    newPos.setX(pos().x());

    newPos.setY(newPos.y()+1);
    newPos.setX(newPos.x()+1);

    //Bas
    while(newPos.estValide()){
        depPossibles.push_back(newPos);
        newPos.setY(newPos.y()+1);
        newPos.setX(newPos.x()+1);
    }

    return depPossibles;
}


std::vector<position> roi::deplacementsPossible() const
{
    std::vector<position> depPossibles;

    for(int i = -1; i<=1; ++i){
        for(int j = -1; j<=1; ++j){
            if(j!= 0 || i!=0){
                position newPos(pos());
                newPos.setY(pos().y() + i);
                newPos.setX(pos().x() + j);

                if(newPos.estValide()){
                    depPossibles.push_back(newPos);
                }
            }
        }
    }

    return depPossibles;
}

