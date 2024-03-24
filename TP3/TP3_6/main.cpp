#include "ensemble.hh"
#include "ensembletableau.hh"
#include "ensemblevector.hh"

void testEnsemble(Ensemble &e1, Ensemble &e2){

    std::cout<<"Est vide : "<<e1.vide()<<"\n";
    std::cout<<"Est vide : "<<e2.vide()<<"\n";

    e1.ajouter(5);
    e2.ajouter(5);

    std::cout<<"Appartient : "<<e1.appartient(3)<<"\n";
    std::cout<<"Appartient : "<<e2.appartient(3)<<"\n";

    e1.ajouter(3);
    e2.ajouter(3);

    std::cout<<"Appartient : "<<e1.appartient(5)<<"\n";
    std::cout<<"Appartient : "<<e2.appartient(5)<<"\n";

    e1.enlever(5);
    e2.enlever(5);

    e1.afficher();
    e2.afficher();

    e1.ajouter(2);
    e1.ajouter(4);
    e1.ajouter(5);
    e2.ajouter(7);

    e2.ajouter(2);
    e2.ajouter(4);
    e2.ajouter(5);
    e2.ajouter(6);


    std::cout<<"Parcours tab : ";

    for(auto p = e1.commencer(); !e1.estfini(p); e1.suivant(p)){
        std::cout<<e1.courant(p)<<" ";
    }

    std::cout<<"\n";

    std::cout<<"Parcours vector : ";

    for(auto p = e2.commencer(); !e2.estfini(p); e2.suivant(p)){
        std::cout<<e2.courant(p)<<" ";
    }

    std::cout<<"\n";


    EnsembleVector test_method_vector;

    test_method_vector.unionEnsemble(e1, e2);
    std::cout<<"Union : ";
    test_method_vector.afficher();
    std::cout<<"\n";

    test_method_vector.interEnsemble(e1, e2);
    std::cout<<"Inter : ";
    test_method_vector.afficher();
    std::cout<<"\n";

    test_method_vector.diffEnsemble(e1, e2);
    std::cout<<"Diff : ";
    test_method_vector.afficher();
    std::cout<<"\n";


    e1.creerEnsembleVide();
    e2.creerEnsembleVide();


    std::cout<<"Est vide : "<<e1.vide()<<"\n";
    std::cout<<"Est vide : "<<e2.vide()<<"\n";
}


int main()
{
    EnsembleTableau eT;
    EnsembleVector eV;

    testEnsemble(eT, eV);
}
