#include "carte.hh"

void Carte::ajouter(Personnage const & personnage){
    _personnages.push_back(personnage);
}

void Carte::ajouter(ObjetRamassable const & objet){
    _objetsRamassables.push_back(objet);
}

void Carte::ajouter(Obstacle const & obstacle){
    _obstacles.push_back(obstacle);
}

void Carte::afficherPersonnages(){

    std::cout<<_taille.tostring()<<" => ";

    for(Personnage personnage: _personnages){
        std::cout<<personnage.tostring()<<" ";
    }

    std::cout<<"\n";
}

bool Carte::intersectionElements(Element e1, Element e2){
    return e1.contientPosition(e2.accesposition()) || e2.contientPosition(e1.accesposition());
}
