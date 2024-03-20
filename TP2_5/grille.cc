#include "grille.hh"

Grille::Grille(coordonnnee largeur, coordonnnee hauteur): _largeur(largeur), _hauteur(hauteur){

    std::vector<etatcellule> cols;

    for(coordonnnee i = 0; i<largeur; ++i){
        cols.push_back(etatcellule::mort);
    }

    for(coordonnnee i = 0; i<hauteur; ++i){
        _grille.push_back(cols);
    }
}

void Grille::afficher(etatcellule e){


    switch (e){
        case etatcellule::mort:
           std::cout<<" ";
           break;
        case etatcellule::vivant:
           std::cout<<"*";
           break;
    }
}

void Grille::afficher(){
     for(auto ligne: _grille){
         for(auto cell: ligne){
             afficher(cell);
             std::cout<<" ";
         }

         std::cout<<std::endl;
     }
}

void Grille::vider(){
    for(auto & ligne: _grille){
        for(auto & cell: ligne){
           if(cell == etatcellule::vivant){
               cell = etatcellule::mort;
           }
        }
    }
}

void Grille::tuer(coordonnnee Y, coordonnnee X){
    if(estDansLaGrille(Y,X)){
        _grille[Y][X] = etatcellule::mort;
    }
}

void Grille::generer(coordonnnee Y, coordonnnee X){
    if(estDansLaGrille(Y,X)){
        _grille[Y][X] = etatcellule::vivant;
    }
}

bool Grille::estDansLaGrille(coordonnnee Y, coordonnnee X){
    if(Y<_hauteur && Y>= 0 && X>=0 && X<_largeur) return true;

 //   std::cout<<"("<<X<<","<<Y<<") pas dans la grille."<<std::endl;
    return false;
}


coordonnnee Grille::largeur(){
    return _largeur;
}

coordonnnee Grille::hauteur(){
    return _hauteur;
}

void Grille::setHauteur(coordonnnee hauteur){
    _hauteur = hauteur;
}

void Grille::setLargeur(coordonnnee largeur){
    _largeur = largeur;
}

void Grille::setGrille(std::vector<std::vector<etatcellule>> grille){
    _grille = grille;
}

std::vector<std::vector<etatcellule>> Grille::grille(){
    return _grille;
}

void Grille::ajouterStructure(structure s, coordonnnee Y, coordonnnee X){

    if(estDansLaGrille(Y,X)){

        switch (s){
            case structure::floraison:
                if(vivante(Y,X) == false){
                    for(coordonnnee i = 1; i<= 3; ++i){
                        generer(Y,X+i);
                        generer(Y+2,X+i);
                    }

                    for(coordonnnee i = 0; i< 6; i +=2){
                        generer(Y+1,X+i);
                    }
                }
                break;

            case structure::oscillateurcroix:

                if(vivante(Y,X) == true) tuer(Y,X);

                for(coordonnnee i = 0; i< 3; ++i){
                    generer(Y+1, X+i);
                }

                for(coordonnnee i = 0; i< 3; ++i){
                    generer(Y+i, X+1);
                }

                break;

            case structure::oscillateurligne:
                for(coordonnnee i = 0; i< 3; ++i){
                    generer(Y, X+i);
                }

                break;
            case structure::planeur:
                for(coordonnnee i = 0; i< 3; ++i){
                    generer(Y, X+i);
                }

                generer(Y+1, X+2);
                generer(Y+2, X+1);
                break;

            case structure::canon:


                generer(Y+4, X);
                generer(Y+4, X+1);
                generer(Y+5, X);
                generer(Y+5, X+1);

                generer(Y+4, X+11);
                generer(Y+5, X+11);
                generer(Y+6, X+11);

                generer(Y+3, X+12);
                generer(Y+7, X+12);

                generer(Y+2, X+13);
                generer(Y+8, X+13);
                generer(Y+2, X+14);
                generer(Y+8, X+14);

                generer(Y+5, X+15);

                generer(Y+3, X+16);
                generer(Y+7, X+16);

                generer(Y+4, X+17);
                generer(Y+5, X+17);
                generer(Y+6, X+17);

                generer(Y+5, X+18);

                generer(Y+2, X+21);
                generer(Y+3, X+21);
                generer(Y+4, X+21);
                generer(Y+2, X+22);
                generer(Y+3, X+22);
                generer(Y+4, X+22);

                generer(Y+1, X+23);
                generer(Y+5, X+23);

                generer(Y+0, X+25);
                generer(Y+1, X+25);
                generer(Y+5, X+25);
                generer(Y+6, X+25);

                generer(Y+2, X+34);
                generer(Y+3, X+34);
                generer(Y+2, X+35);
                generer(Y+3, X+35);

                break;
        }
    }
}

bool Grille::vivante(coordonnnee Y, coordonnnee X){
    if(estDansLaGrille(Y,X)){
        if(_grille[Y][X] == etatcellule::vivant) {
            return true;
        }
    }

    return false;
}

int Grille::vivantes(coordonnnee Y, coordonnnee X){
    int nbVivantes = 0;

    for(coordonnnee y = (Y-1); y<=(Y + 1); ++y){
        for(coordonnnee x = X-1; x<=(X + 1); ++x){
            if(!(y==Y && x==X)){
                if(vivante(y,x)) {
                    nbVivantes += 1;
                }
            }
        }
    }

    return nbVivantes;
}

void Grille::evolution(Grille & newGrille){

    for(int Y = 0; Y< _hauteur; ++Y){
        for(int X = 0; X< _largeur; ++X){
            if(!vivante(Y,X)){
                if(vivantes(Y,X) == 3){
                    newGrille.generer(Y,X);
                }
            }

            else{
                int nbCellulesVivantes = vivantes(Y,X);
                if(nbCellulesVivantes == 2 || nbCellulesVivantes == 3){
                    newGrille.generer(Y,X);
                }
            }
        }
    }
}

