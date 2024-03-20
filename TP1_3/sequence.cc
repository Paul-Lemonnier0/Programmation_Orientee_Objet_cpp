#import "sequence.hh"
#include <iostream>

void sc_initialiservide(sequence & sec){
    sec.taille = 0;
    sec.tailleAllouee = 5;
    sec.couleurs = new couleur[sec.tailleAllouee];
}

void sc_vider(sequence & sec){
    delete []sec.couleurs;
    sec.taille = 0;
    sec.tailleAllouee = 0;
}

void sc_ajouter(sequence & sec, couleur c){

    if(sec.taille == sec.tailleAllouee){
        couleur * old_couleurs = sec.couleurs;
        sec.tailleAllouee += 5;
        sec.couleurs = new couleur[sec.tailleAllouee];

        for(indicesequence i = 0; i<sec.taille; ++i){
            sec.couleurs[i] = old_couleurs[i];
        }

        sec.couleurs[sec.taille] = c;
        delete []old_couleurs;
    }

    else {
        sec.couleurs[sec.taille] = c;
        sec.taille += 1;
    }
}

couleur sc_acces(sequence sec, indicesequence index){
    return sec.couleurs[index];
}

void sc_afficher(couleur c){
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

void sc_afficher(sequence sec){
    for(indicesequence i = 0; i<sec.taille; ++i)
    {
        sc_afficher(sc_acces(sec, i));
        std::cout<<" ";
    }
}

void sc_copier(sequence & b, sequence a){

    if(b.taille < a.taille){
        couleur * temp = b.couleurs;
        b.couleurs = new couleur[a.taille];
        delete []temp;
    }

    for(indicesequence i = 0; i<a.taille; ++i)
    {
        b.couleurs[i] = a.couleurs[i];
    }
    
    b.taille = a.taille;
}

bool sc_comparer(sequence a, sequence b){

    if(a.taille != b.taille) return false;

    else{
        for(indicesequence i = 0; i<a.taille; ++i)
        {
            if(a.couleurs[i] != b.couleurs[i]) return false;
        }
    }

    return true;
}

