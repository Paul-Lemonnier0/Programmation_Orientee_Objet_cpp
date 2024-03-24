#include "sequence.hh"

sequence::sequence(){}
sequence::sequence(sequence & s){
    _couleurs = s.couleurs();
}



std::vector<couleur> sequence::couleurs(){
    return _couleurs;
}

indicesequence sequence::taille(){
    return _couleurs.size();
}


void sequence::setCouleurs(std::vector<couleur> couleurs){
    _couleurs = couleurs;
}

void sequence::ajouter(couleur c){
    _couleurs.push_back(c);
}

couleur sequence::acces(indicesequence i){
    return _couleurs[i];
}

void sequence::afficher(couleur c){

    switch (c){
        case couleur::rouge:
            std::cout<<"Rouge";
            break;
        case couleur::bleu:
            std::cout<<"Bleu";
            break;

        case couleur::vert:
            std::cout<<"Vert";
            break;

        case couleur::jaune:
            std::cout<<"Jaune";
            break;

        default:
            break;
    }
}

void sequence::afficher(std::ostream &aff){

    for (indicesequence i=0; i< _couleurs.size(); ++i) {
        afficher(acces(i));
        aff << " ";
    }
}

void sequence::vider() {
    _couleurs.clear();
}

bool sequence::comparer(sequence a){
    return _couleurs == a.couleurs();
}

void sequence::copier(sequence a){
    _couleurs = a.couleurs();
}

