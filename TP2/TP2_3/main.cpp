#include <iostream>
#include <vector>

std::vector<int> ajoute(std::vector<int> vector, int e){
    std::vector<int> v2(vector);
    v2.push_back(e);
    return v2;
}

void ajoute_ref(std::vector<int> &vector, int e){
    vector.push_back(e);
}

int max1(std::vector<int> vector){

    int max = vector[0];

    for (std::vector<int>::size_type i(0); i<vector.size(); ++i)
    {
        if(max < vector[i]) max = vector[i];
    }

    return max;
}

int max2(std::vector<int> vector){

    int max = vector[0];

    for (std::vector<int>::const_iterator i(vector.begin()); i!=vector.end(); ++i)
    {
        if(max < *i) max = *i;
    }

    return max;
}

int max3(std::vector<int> vector){

    int max = vector[0];

    for (auto i : vector)
    {
        if(max < i) max = i;
    }

    return max;
}

int main() {
    std::vector<int> v1; // Construction à vide
    for (int i(0); i<10; i++)
    v1.push_back(i);
    std::vector<int> v2(v1); // Construction par recopie
    // Parcours par indice
    std::cout<<"Indices : "<<std::endl;
    for (std::vector<int>::size_type i(0); i<v1.size(); ++i)
    std::cout << v1[i];
    std::cout<<std::endl;
    std::cout<<std::endl;

    // Parcours par itérateur
    std::cout<<"Itérateur : "<<std::endl;
    for (std::vector<int>::const_iterator i(v1.begin()); i!=v1.end(); ++i)
    std::cout << *i;
    std::cout<<std::endl;
    std::cout<<std::endl;


    // Parcours et modification par itérateur
    for (std::vector<int>::iterator i(v1.begin()); i!=v1.end(); ++i)
    *i = *i +1;
    // Parcours et modification par itérateur
    for (auto i(v1.begin()); i!=v1.end(); ++i)
    *i = *i +1;
    // Parcours par boucle for d'intervalle (valeur)
    std::cout<<"Boucle : "<<std::endl;
    for (auto i : v1)
    std::cout << i;
    std::cout<<std::endl;
    std::cout<<std::endl;


    // Parcours par boucle for d'intervalle (référence)
    for (auto & i : v1)
    i *= 2;
    // Utilisation de l'opérateur d'affectation.
    v2 = v1;

    std::vector<int> v3 = ajoute(v1, 120);

    for (auto i : v3)
        std::cout << i << " ";

    std::cout<<std::endl;
    std::cout<<std::endl;

    ajoute_ref(v3, 121);

    for (auto i :v3)
        std::cout << i << " ";

    std::cout<<"MAX : "<<std::endl;

    std::cout<<max1(v3)<<std::endl;
    std::cout<<max2(v3)<<std::endl;
    std::cout<<max3(v3)<<std::endl;

    return 0;
}
