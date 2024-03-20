#include "sequence.hh"

sequence::sequence():_taille(0), _tailleAllouee(5), _couleurs(new couleur[_tailleAllouee]){}
sequence::sequence(sequence & s){
    _taille = s.taille();
    _tailleAllouee = s.tailleAllouee();

    _couleurs = new couleur[s.tailleAllouee()];

    for(indicesequence i = 0; i< s.taille(); ++i){
        _couleurs[i] = s.acces(i);
    }
}

indicesequence sequence::taille(){
    return _taille;
}

indicesequence sequence::tailleAllouee(){
    return _tailleAllouee;
}

couleur * sequence::couleurs(){
    return _couleurs;
}

void sequence::setTaille(indicesequence taille){
    _taille = taille;
}

void sequence::setTailleAllouee(indicesequence tailleAllouee){
    _tailleAllouee = tailleAllouee;
}

void sequence::setCouleurs(couleur * couleurs){
    _couleurs = couleurs;
}

void sequence::ajouter(couleur c){
    if(_taille == _tailleAllouee){

        couleur * old_couleurs = _couleurs;
        _tailleAllouee += 5;
        _couleurs = new couleur[_tailleAllouee];

        for(indicesequence i = 0; i<_taille; ++i){
            _couleurs[i] = old_couleurs[i];
        }

        _couleurs[_taille] = c;
        delete []old_couleurs;
    }

    else {
        _couleurs[_taille] = c;
        _taille += 1;
    }
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

    for (indicesequence i=0; i< _taille; ++i) {
        afficher(acces(i));
        aff << " ";
    }
}

void sequence::vider() {
    delete []_couleurs;
    _taille = 0;
    _tailleAllouee = 0;
}

bool sequence::comparer(sequence a){

    if(_taille != a.taille()) return false;

    else{
        for(indicesequence i = 0; i<_taille; ++i)
        {
            if(_couleurs[i] != a.couleurs()[i]) return false;
        }
    }

    return true;
}

void sequence::copier(sequence a){

    _taille = a.taille();
    _tailleAllouee = a.tailleAllouee();

    couleur * temp = _couleurs;
    _couleurs = new couleur[a.tailleAllouee()];
    delete []temp;


    for(indicesequence i = 0; i< a.taille(); ++i){
        _couleurs[i] = a.acces(i);
    }

}

