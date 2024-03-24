#include "societe.h"

societe::societe()
{

}

std::string societe::nom() const
{
    return _nom;
}

void societe::setNom(const std::string &nom)
{
    _nom = nom;
}

std::string societe::getString() const
{
    return string;
}

void societe::setString(const std::string &value)
{
    string = value;
}

std::shared_ptr<personne> societe::gerant() const
{
    return _gerant;
}

void societe::setGerant(const std::shared_ptr<personne> &gerant)
{
    _gerant = gerant;
}
