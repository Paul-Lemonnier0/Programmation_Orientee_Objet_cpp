#include "ensembletableau.hh"
#include "ensemblevector.hh"

void EnsembleTableau::ajouter(int x)
{
    int * temp = _tab;

    _taille += 1;
    _tab = new int[_taille];

    for(std::size_t i = 0 ; i<_taille-1; ++i){
        _tab[i] = temp[i];
    }

    _tab[_taille-1] = x;
    delete []temp;
}

void EnsembleTableau::afficher() const{
    for(std::size_t i = 0 ; i<_taille; ++i){
        std::cout<<_tab[i]<< " ";
    }

    std::cout<<"\n";
}

void EnsembleTableau::enlever(int x){
    bool isFound = false;
    int * temp = new int[_taille-1];
    int index = -1;

    for(std::size_t i = 0 ; i<_taille; ++i){
        if(isFound){
            ++index;
            temp[index] = _tab[i];
        }

        else{
            if(_tab[i] == x){
                isFound = true;
            }

            else{
                ++index;
                temp[index] = _tab[i];
            }
        }
    }

    if(isFound){
        delete[] _tab;
        _taille -= 1;
        _tab = new int[_taille];
        _tab = temp;

    }

    else delete[] temp;
}

bool EnsembleTableau::estfini(ParcoursElements const & p) const
{
    return (p.positionCourante() >= _taille);
}

int EnsembleTableau::courant(ParcoursElements const & p) const
{
    return _tab[p.positionCourante()];
}

bool EnsembleTableau::vide() const{
    return _taille == 0;
}

bool EnsembleTableau::appartient(int x) const{
    for(std::size_t i = 0 ; i<_taille; ++i){
        if(_tab[i] == x) return true;
    }

    return false;
}

void EnsembleTableau::creerEnsembleVide(){
    delete[] _tab;
    _taille = 0;
    _tab = new int[0];
}
