#include "element.hh"
#include "personnage.hh"
#include "objetramassable.hh"
#include "obstacle.hh"
#include "carte.hh"

int main()
{
    Personnage p(0,0,3,3, "Paul");

    ObjetRamassable obj(1,1,1,1, 15);

    Obstacle obs(5,5,2,2);

    Carte carte(30,30);
    carte.ajouter(p);
    carte.ajouter(obj);
    carte.ajouter(obs);

    p.ramasser(obj);
    std::cout<<p.tostring()<<"\n";

    return 0;
}
