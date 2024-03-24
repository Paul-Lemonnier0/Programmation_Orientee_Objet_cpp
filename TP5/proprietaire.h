#pragma once
#include <string>
#include <memory>

class proprietaire
{

public:
    enum class type{
        personne,
        societe,
        couple
    };

    virtual ~proprietaire() = default;

    virtual type typeprop() const = 0;
    virtual std::string nom() const = 0;
    virtual std::string adresse() const = 0;

    std::string etiquetteexpedition() const;
    virtual void sortieFlux(std::ostream & out) const;
    static std::shared_ptr<proprietaire> fabriquepersonne(std::string const & nom,
             std::string const & adresse, std::string const & dateNaissance);

    static std::shared_ptr<proprietaire> fabriquesociete(std::string const & nom,
             std::string const & adresse, std::shared_ptr<proprietaire> gerant);

    static std::shared_ptr<proprietaire> fabriquecouple(std::shared_ptr<proprietaire> prop1,
             std::shared_ptr<proprietaire> prop2);

};


std::ostream & operator<<(std::ostream & out, proprietaire::type t);
std::ostream & operator<<(std::ostream & out, proprietaire const & p);

class personne: public proprietaire{
private:
    std::string _nom, _adresse, _dateNaissance;
    personne(std::string const & nom, std::string const & adresse, std::string const & dateNaissance):
        _nom(nom), _adresse(adresse), _dateNaissance(dateNaissance){}

public:
    std::string nom() const override { return _nom; }
    std::string adresse() const override { return _adresse; }
    type typeprop() const override { return type::personne; }

friend proprietaire;

};


