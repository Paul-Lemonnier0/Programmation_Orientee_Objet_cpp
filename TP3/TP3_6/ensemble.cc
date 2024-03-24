#include "ensemble.hh"


void Ensemble::unionEnsemble(Ensemble const &e1, Ensemble const &e2){
    creerEnsembleVide();

    for(auto p = e1.commencer(); !e1.estfini(p); e1.suivant(p)){
       ajouter(e1.courant(p));
    }

    for(auto p = e2.commencer(); !e2.estfini(p); e2.suivant(p)){
        if(appartient(e2.courant(p)) == false){
            ajouter(e2.courant(p));
        }
    }
}

void Ensemble::interEnsemble(Ensemble const &e1, Ensemble const &e2){
    creerEnsembleVide();

    for(auto p = e1.commencer(); !e1.estfini(p); e1.suivant(p)){
        if(e2.appartient(e1.courant(p)))
            ajouter(e1.courant(p));
    }
}

void Ensemble::diffEnsemble(const Ensemble &e1, const Ensemble &e2){
    creerEnsembleVide();

    for(auto p = e1.commencer(); !e1.estfini(p); e1.suivant(p)){
        if(!e2.appartient(e1.courant(p))){
            std::cout<<"hello";
            ajouter(e1.courant(p));
        }
    }
}

ParcoursElements Ensemble::commencer() const{
    ParcoursElements p;
    return p;
}

void Ensemble::suivant(ParcoursElements & p) const{
    p.passerausuivant();
}



