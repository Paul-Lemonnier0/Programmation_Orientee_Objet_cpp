#include <vector>
#include <iostream>
#pragma once
#ifndef GRILLE_HH
#define GRILLE_HH

using coordonnnee = int;
enum class etatcellule {vivant, mort};
enum class structure {oscillateurligne, floraison, planeur, oscillateurcroix, canon};

class Grille
{

   private:
        coordonnnee _largeur, _hauteur;
        std::vector<std::vector<etatcellule>> _grille;

    public:
        Grille(coordonnnee largeur, coordonnnee hauteur);

        coordonnnee largeur();
        coordonnnee hauteur();
        std::vector<std::vector<etatcellule>> grille();

        void setLargeur(coordonnnee largeur);
        void setHauteur(coordonnnee hauteur);
        void setGrille(std::vector<std::vector<etatcellule>> grille);

        void afficher();
        void afficher(etatcellule e);
        void vider();

        bool estDansLaGrille(coordonnnee Y, coordonnnee X);
        bool vivante(coordonnnee Y, coordonnnee X);
        void generer(coordonnnee Y, coordonnnee X);
        void tuer(coordonnnee Y, coordonnnee X);

        void ajouterStructure(structure s, coordonnnee Y, coordonnnee X);
        int vivantes(coordonnnee Y, coordonnnee X);
        void evolution(Grille &g);
};

#endif // GRILLE_HH
