#pragma once
#include <map>
#include <vector>
#include "resultatexception.h"
#include <iostream>
#include <string>

class resultat
{
private:
    std::vector<int> _entiers;

public:
    resultat();
    resultat(resultat const & r) = default;

    std::vector<int> entiers() const;
    void ajouternumero(int x);

    friend std::ostream& operator <<(std::ostream& os, const resultat & r);
    void sort();
};


