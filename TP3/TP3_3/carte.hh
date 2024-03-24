#ifndef CARTE_HH
#define CARTE_HH
#pragma once

#include <list>
#include "element.hh"
#include "personnage.hh"
#include "objetramassable.hh"
#include "obstacle.hh"
#include "point.hh"

class Carte
{
    private:
        Point _origin;
        Taille _taille;
        std::list<Personnage> _personnages;
        std::list<ObjetRamassable> _objetsRamassables;
        std::list<Obstacle> _obstacles;


    public:
        Carte(Taille const & t)
            :_taille(Taille (t))
        {};

        Carte(coordonnee largeur, coordonnee hauteur):
            _taille(Taille (largeur, hauteur))
        {};

        Point origine();
        Taille taille();
        std::list<Personnage> personnages();
        std::list<ObjetRamassable> objetsRamassables();
        std::list<Obstacle> obstacles();

        void setTaille(coordonnee largeur, coordonnee hauteur);

        void ajouter(Personnage const & personnage);
        void ajouter(ObjetRamassable const & objet);
        void ajouter(Obstacle const & obstacle);

        void afficherPersonnages();
        bool intersectionElements(Element e1, Element e2);
};

#endif // CARTE_HH
