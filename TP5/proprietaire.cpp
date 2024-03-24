#include "proprietaire.h"


std::string proprietaire::etiquetteexpedition() const { return nom() + " " + adresse(); }

void proprietaire::sortieFlux(std::ostream &out) const
{
    std::string str = "";
    out<<str;
}

std::shared_ptr<proprietaire> proprietaire::fabriquepersonne(const std::string &nom, const std::string &adresse, const std::string &dateNaissance)
{
    return std::make_shared<personne>(new personne(nom, adresse, dateNaissance));
}

std::shared_ptr<proprietaire> proprietaire::fabriquesociete(const std::string &nom, const std::string &adresse, std::shared_ptr<proprietaire> gerant)
{
    return nullptr;

}

std::shared_ptr<proprietaire> proprietaire::fabriquecouple(std::shared_ptr<proprietaire> prop1, std::shared_ptr<proprietaire> prop2)
{




    return nullptr;
}
