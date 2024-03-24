#include "project.h"
#include "element.h"
#include <iostream>
int main()
{
    std::cout<<"----------TEST----------"<<std::endl;

    position pos(2,3);
    taille tai(4,6);
    std::cout << pos;
    std::cout << tai;

    std::cout<<"----------ELEMENT----------"<<std::endl;

    pacman p(direction::bas, pos);
    fantome f(direction::bas, 1,2);
    pacgommes g(4,1);
    std::unique_ptr<mur> m = mur::fabrique(pos, tai);

    std::cout<<p;
    std::cout<<f;
    std::cout<<g;
    std::cout<<*m;


    return 0;
}
