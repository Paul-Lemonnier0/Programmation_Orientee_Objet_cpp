#include "grille.hh"
#include <string>

int main()
{
    coordonnnee largeur = 80, hauteur = 60;
    Grille grille(largeur, hauteur);
    grille.afficher();

    std::cout<<"BIENVENUE DANS LE JEU DE LA VIE MOUAHAHAHAHA"<<std::endl;
    grille.ajouterStructure(structure::canon, 0, 0);

    grille.afficher();

    std::string stopStr = "";
    do{
        Grille nouvelleGrille(grille.largeur(), grille.hauteur());
        std::getline(std::cin, stopStr);

        grille.evolution(nouvelleGrille);
        grille = nouvelleGrille;
        grille.afficher();
    }


    while(stopStr != "stop");

    return 0;
}
