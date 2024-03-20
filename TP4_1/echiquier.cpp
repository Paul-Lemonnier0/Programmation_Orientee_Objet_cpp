#include "echiquier.h"
#include "array"
#include <iostream>
#include <fstream>
#include <sstream>

const int N = 8;
using ligne = std::array<std::string, N>;
using grille = std::array<ligne, N>;

echiquier::echiquier()
{

}

echiquier::echiquier(const echiquier &e)
{
    for(auto const & p: e._pieces){
        _pieces.push_back(p->clone());
    }
}


void echiquier::ajoutPiece(std::unique_ptr<piece> p)
{
    _pieces.push_back(std::move(p));
}

int echiquier::valeurdujoueur(couleur c) const
{
    int total = 0;

    for(auto const & p: _pieces){
        if(p->coul() == c){
            total += p->valeur();
        }
    }

    return total;
}

bool echiquier::deplacer(const position &source, const position &destination)
{
    if(!destination.estValide() || !source.estValide()) return false;

    for(auto it(_pieces.begin()); it!=_pieces.end(); ++it){
        if((*it)->pos() == source){

            if(!(*it)->accepterPosition(destination)){
                return false;
            }

           for(auto it2(_pieces.begin()); it2!=_pieces.end(); ++it2){
               if((*it2)->pos() == destination){


                   if((*it2)->coul() != (*it)->coul()){
                       (*it)->setPos(destination);

                       _pieces.erase(it2);
                       //(*it).reset();

                       return true;
                   }

                   else return false;
               }
           }

           (*it)->setPos(destination);

           return true;
        }
    }

    return false;
}

void echiquier::affichage(std::ostream &out) const
{
    grille E;
    std::string str = "";


    for(int i = 0; i<8; ++i){
        for(int j = 0; j<8; ++j){
            E[i][j] = " ";
        }
    }

    for(auto const & p: _pieces){
        E[p->pos().y()][p->pos().x()] = p->toshortstring();
    }

    str += "  A-B-C-D-E-F-G-H-\n";

    for(int i = 0; i<8; ++i){
        str += std::to_string(i+1) + " ";
        for(int j = 0; j<8; ++j){
            str += E[i][j];
        }

        str += "\n";
    }

    out << str;
}

void echiquier::sauvegarde(std::ofstream &file) const
{
    std::string str;

    for(auto const & p: _pieces){
        file << p->tostring();
        file << "\n";
    }
}

void echiquier::chargement(std::ifstream &file)
{
    while(!file.eof()){

        std::string piece_temp;
        std::string value_temp;
        std::string x_temp;
        std::string y_temp;

        std::string line;
        std::getline(file, line);

        std::stringstream ss(line);

        std::getline(ss, piece_temp, ' ');
        std::getline(ss, value_temp, ' ');
        std::getline(ss, x_temp, ' ');
        std::getline(ss, y_temp, ' ');

        if(!y_temp.empty()){
            couleur couleur_temp = couleur::blanc;
            if(piece_temp[1] == 'N'){
                 couleur_temp = couleur::noir;
            }

            position p (std::stoi(x_temp), std::stoi(y_temp));

            if(piece_temp[0] == 'P'){
                pion pion_temp (couleur_temp, p);
                ajoutPiece(pion_temp.clone());
            }

            else if(piece_temp[0] == 'D'){
                dame dame_temp (couleur_temp, p);
                ajoutPiece(dame_temp.clone());
            }

            else if(piece_temp[0] == 'R'){
                roi roi_temp (couleur_temp, p);
                ajoutPiece(roi_temp.clone());
            }

            else{
                cavalier cavalier_temp (couleur_temp, p);
                ajoutPiece(cavalier_temp.clone());
            }
        }

    }
}

bool echiquier::roiPris(couleur c) const{
    for(auto const & p: _pieces){
        if(p->symbole() == "R" && p->coul() == c){
            return false;
        }
    }

    return true;
}

void echiquier::start()
{
    for(int i = 0; i < 8; ++i){
        position posN (1, i);
        pion pN (couleur::noir, posN);
        _pieces.push_back(pN.clone());

        position posB (6, i);
        pion pB (couleur::blanc, posB);
        _pieces.push_back(pN.clone());
    }

    for(int i = 1; i<8; i+=5){
        position posN (0, i);
        cavalier cN (couleur::noir, posN);
        _pieces.push_back(cN.clone());

        position posB (6, i);
        cavalier cB (couleur::blanc, posB);
        _pieces.push_back(cB.clone());
    }

    position posN (0, 3);
    cavalier dN (couleur::noir, posN);
    _pieces.push_back(dN.clone());

    position posB (6, 3);
    cavalier dB (couleur::blanc, posB);
    _pieces.push_back(dB.clone());

    posN.setX(posN.x()+1);
    posB.setX(posB.x()+1);

    cavalier rN (couleur::noir, posN);
    _pieces.push_back(rN.clone());

    cavalier rB (couleur::blanc, posB);
    _pieces.push_back(rB.clone());

    while(!roiPris(couleur::blanc) && !roiPris(couleur::noir)){
        //jouer
    }
}
