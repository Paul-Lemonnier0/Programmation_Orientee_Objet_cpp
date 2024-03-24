#include "resultat.h"
#include "date.h"
#include <iostream>

int main()
{
    resultat r;

    r.ajouternumero(1);
    r.ajouternumero(-5);
    r.ajouternumero(4);
    r.ajouternumero(3);
    r.ajouternumero(2);
    r.ajouternumero(3);
    r.ajouternumero(5);
    r.ajouternumero(6);

    std::cout<<"----------------------INITIAL----------------------\n";
    std::cout<<r;
    std::cout<<"----------------------SORT----------------------\n";
    r.sort();
    std::cout<<r;

    date d(2024, 01, 11);
    date d1(2022, 12, 3);

    d=d1;

    std::cout<<d;

    return 0;
}
