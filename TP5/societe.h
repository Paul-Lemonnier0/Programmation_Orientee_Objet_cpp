#pragma once
#include "personne.h"
#include <string>
#include <memory>

class societe
{

private:
    std::string _nom, std::string _adresse, std::shared_ptr<personne> _gerant;

public:
    societe(std::string nom, std::string adresse, personne * gerant):
        _nom(nom), _adresse(adresse), _gerant(gerant){};

    std::string nom() const;
    void setNom(const std::string &nom);
    std::string getString() const;
    void setString(const std::string &value);
    std::shared_ptr<personne> gerant() const;
    void setGerant(const std::shared_ptr<personne> &gerant);
};
