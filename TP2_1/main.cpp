#include <iostream>
#include "tailleposition.hh"

using namespace std;

int main()
{
    Position p (0,2);
    Position p2 (0,2);

    p.afficher();
    p2.afficher();
    std::cout<<"Comparaison : "<<p.comparaison(p2)<<std::endl;

    p.setX(p.getX() + 2);
    p.setY(p.getY() + 2);
    p.afficher();
    p2.afficher();
    std::cout<<"Comparaison : "<<p.comparaison(p2)<<std::endl;


    return 0;
}
