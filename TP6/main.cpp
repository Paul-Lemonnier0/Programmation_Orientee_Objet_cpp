#include "arrayint.h"
#include <iostream>

int main()
{
    arrayint tab(-10, 10);
    arrayint tab_copy(tab);

    std::cout<<tab.tostring()<<std::endl;
    std::cout<<tab_copy.tostring()<<std::endl;

    std::cout<<"Equal ? : "<<(tab_copy == tab)<<std::endl;

    tab.set(-9, 666);
    std::cout<<tab[-9]<<std::endl;

    std::cout<<"Equal ? : "<<(tab_copy == tab)<<std::endl;

    tab_copy = tab;
    std::cout<<tab_copy[-9]<<std::endl;

    std::cout<<"Equal ? : "<<(tab_copy == tab)<<std::endl;

    tab<<std::cout;

    for (arrayint::const_iterator i=tab.begin(); i!=tab.end(); ++i){
        std::cout << (*i) << "\n";
    }

    return 0;
}
