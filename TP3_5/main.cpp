#include "position.hh"
#include <iostream>

#include "joueur.hh"
#include "projectile.hh"
#include "invaders.hh"

int main()
{
    Position p(5,3);
    Taille t(5,5);
    direction d = direction::droite;

    Invaders I(p, 2, 3, d);
    I.sortieFlux(std::cout);
    std::cout<<"\n";

    Joueur J(p, t, 10, 10, d);
    J.sortieFlux(std::cout);
    std::cout<<"\n";

    Projectile P(p);
    P.sortieFlux(std::cout);
    std::cout<<"\n";

}
