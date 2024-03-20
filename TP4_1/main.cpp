#include "piece.h"
#include "echiquier.h"
#include <iostream>
#include <fstream>

int main()
{
    position p1(4,4);
    position p2(0,0);
    position p3(4,2);
    position p4(6,6);

    pion p(couleur::blanc, p1);
    p.afficheDeplacementsPossibles();

    std::cout<<"############################################"<<std::endl;


    dame d(couleur::noir, p2);
    d.afficheDeplacementsPossibles();

    std::cout<<"############################################"<<std::endl;

    cavalier c(couleur::noir, p3);
    c.afficheDeplacementsPossibles();


    std::cout<<"############################################"<<std::endl;

    roi r(couleur::noir, p4);
    r.afficheDeplacementsPossibles();

    echiquier e;
    e.ajoutPiece(p.clone());
    e.ajoutPiece(d.clone());
    e.ajoutPiece(c.clone());
    e.ajoutPiece(r.clone());

    e.affichage(std::cout);

    echiquier e2 (e);
    e2.deplacer(p1, position(4,3));

    e2.affichage(std::cout);

    e.affichage(std::cout);

    std::string filename = "test.txt";
    std::ofstream ofstrmFile(filename);
    e.sauvegarde(ofstrmFile);
    ofstrmFile.close();

    echiquier e3;

    std::ifstream ifstrmFile(filename);
    if(ifstrmFile)
    {
        e3.chargement(ifstrmFile);
        ifstrmFile.close();

        e3.affichage(std::cout);
    }

    else std::cout<<"Impossible d'ouvrir le fichier : ";

    return 0;
}
