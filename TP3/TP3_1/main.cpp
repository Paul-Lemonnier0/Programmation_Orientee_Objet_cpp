#include "element.hh"
#include "personnage.hh"
#include "objetramassable.hh"
#include "obstacle.hh"

int main()
{
    Personnage p(0,0,3,3, "Paul");
    std::cout<<p.tostring()<<"\n";

    ObjetRamassable obj(1,1,1,1, 15);
    std::cout<<obj.tostring()<<"\n";

    Obstacle obs(5,5,2,2);
    std::cout<<obs.tostring()<<"\n";

    p.ramasser(obj);
    std::cout<<p.tostring()<<"\n";

    return 0;
}
