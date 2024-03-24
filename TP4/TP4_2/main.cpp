#include "document.h"
#include <iostream>
#include "bibliotheque.h"

int main()
{
    video v(typeSupport::BluRay, "Interstellar", "Nolan");
    video v2(typeSupport::BluRay3D, "zazdazda", "Nolan");

    livre l(15, "Misérables", "Victor Hugo", true);
    periodique p(17, 6, "Trop nul l'actu", "Le Monde");
/*
    v.affiche(std::cout);
    std::cout<<std::endl;

    l.affiche(std::cout);
    std::cout<<std::endl;

    p.affiche(std::cout);
    std::cout<<std::endl;
*/
    bibliotheque b;

    b.ajouterDocument(v);
    b.ajouterDocument(l);
    b.ajouterDocument(p);

    b.getDocuments().clear();

    b.afficherBibliothèque(std::cout);
    int nb = b.nbInstancesSupportvideo(typeSupport::DVD);
    std::cout<<"Nb : "<< nb << std::endl;

    bibliotheque bib_BIS = b.clone();

    bib_BIS.ajouterDocument(v2);
    bib_BIS.afficherBibliothèque(std::cout);

    std::cout<<"################################"<<std::endl;

    b.afficherBibliothèque(std::cout);

    return 0;
}
