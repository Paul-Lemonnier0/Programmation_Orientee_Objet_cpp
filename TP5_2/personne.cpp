#include "personne.h"

std::string personne::dateNaissance() const
{
    return _dateNaissance;
}

void personne::setDateNaissance(const std::string &dateNaissance)
{
    _dateNaissance = dateNaissance;
}

std::string personne::getAdresse() const
{
    return adresse;
}

void personne::setAdresse(const std::string &value)
{
    adresse = value;
}

std::string personne::nom() const
{
    return _nom;
}

void personne::setNom(const std::string &nom)
{
    _nom = nom;
}

personne::personne()
{

}
