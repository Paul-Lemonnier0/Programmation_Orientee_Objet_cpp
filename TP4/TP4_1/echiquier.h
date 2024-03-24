#pragma once
#include "piece.h"
#include <memory>


class echiquier
{
private:
    std::vector<std::unique_ptr<piece>> _pieces;

public:
    echiquier();
    ~echiquier() = default;
    echiquier(echiquier const & e);

    void ajoutPiece(std::unique_ptr<piece> p);
    int valeurdujoueur(couleur c) const;
    bool deplacer(position const & source, position const & destination);
    void affichage(std::ostream &out) const;

    void sauvegarde(std::ofstream &file) const;
    void chargement(std::ifstream &file);

    void start();
    bool roiPris(couleur c) const;
};
