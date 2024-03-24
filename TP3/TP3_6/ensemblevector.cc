#include "ensemblevector.hh"
#include <algorithm>

void EnsembleVector::ajouter(int x)
{
    _tab.push_back(x);
}

void EnsembleVector::afficher() const{
    for(int i: _tab){
        std::cout<<i<<" ";
    }

    std::cout<<"\n";
}

void EnsembleVector::enlever(int x){

    int index = -1;

    for(unsigned int i = 0; i<_tab.size(); ++i){
        if(_tab[i] == x) index = i;
    }

    if(index != -1){
        _tab.erase(_tab.begin()+index);
    }
}

bool EnsembleVector::vide() const{
    return _tab.size() == 0;
}


bool EnsembleVector::appartient(int x) const{
    return std::find(_tab.begin(), _tab.end(), x) != _tab.end();

}

void EnsembleVector::creerEnsembleVide(){
    _tab.clear();
}

bool EnsembleVector::estfini(ParcoursElements const & p) const
{
    return (p.positionCourante() == _tab.size());
}

int EnsembleVector::courant(ParcoursElements const &p) const{
    return _tab[p.positionCourante()];
}

