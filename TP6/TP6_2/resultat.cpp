#include "resultat.h"
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <iostream>

std::vector<int> resultat::entiers() const
{
    return _entiers;
}

void resultat::ajouternumero(int x)
{
    try{
        if(x < 1 || x > 49){
            throw std::invalid_argument("Valeur en dehors de l'interval [1, 49]. Impossible d'ajouter la valeur : " + std::to_string(x));
        }

        else if(_entiers.size() == 5){
            throw std::invalid_argument("Liste pleines. Impossible d'ajouter la valeur : " + std::to_string(x));
        }

        else{
            if(std::find(_entiers.begin(), _entiers.end(),  x) != _entiers.end()){
                throw std::invalid_argument("Valeur déjà présente dans la liste. Impossible d'ajouter la valeur : " + std::to_string(x));
            }

            else _entiers.push_back(x);
        }
    }

    catch(std::invalid_argument const & ex){
        std::cout<<ex.what()<<"\n";
    }
}

void resultat::sort()
{
    std::sort(_entiers.begin(), _entiers.end());
}

std::ostream& operator <<(std::ostream& os, const resultat & r){
    std::string str = "[";
    for(auto i: r._entiers){
        str += std::to_string(i);
        if(i != (r._entiers.back())){
            str += ", ";
        }
    }

    str += "] \n";

    os<<str;

    return os;
}

resultat::resultat()
{

}
