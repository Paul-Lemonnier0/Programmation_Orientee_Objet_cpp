#pragma once
#include "ensemble.hh"
#include "parcourselements.hh"
#include <iostream>

class Ensemble
{
    public:
        virtual bool appartient(int x) const = 0;
        virtual bool vide() const = 0;
        virtual void afficher() const = 0;

        virtual void creerEnsembleVide() = 0;
        virtual void ajouter(int x) = 0;
        virtual void enlever(int x) = 0;

        virtual ParcoursElements commencer() const;
        virtual void suivant(ParcoursElements &p) const;
        virtual bool estfini(ParcoursElements const & p) const = 0;
        virtual int courant(ParcoursElements const & p) const = 0;

        void unionEnsemble(Ensemble const &e1, Ensemble const &e2);
        void interEnsemble(Ensemble const &e1, Ensemble const &e2);
        void diffEnsemble(Ensemble const &e1, Ensemble const &e2);
};
