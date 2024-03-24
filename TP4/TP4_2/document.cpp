#include "document.h"

void document::affiche(std::ostream &out) const
{
    std::string empruntable = "non";
    if(_empruntable) empruntable = "oui";

    std::string str = "Type : " + getTypeDocument();
     str += " | Titre : " + _titre;
     str += " | Auteur : " + _nomAuteur;
     str += " | Empruntable : " + empruntable;
     str += " | Coût : " + std::to_string(_cout);

     out<<str;
}

std::string video::getTypeDocument() const
{
    return "Video";
}

std::string livre::getTypeDocument() const
{
    return "Livre";
}

std::string periodique::getTypeDocument() const
{
    return "Périodique";
}


typeSupport video::getSupport() const
{
    return _support;
}

void video::affiche(std::ostream &out) const
{
    document::affiche(out);
    std::string str =  " | Support : " + getSupportString();

    out << str;
}

std::string video::getSupportString() const
{
    switch(_support){
        case(typeSupport::BluRay):
            return "BluRay";
            break;
        case(typeSupport::BluRay3D):
            return "BluRay3D";
            break;

        case(typeSupport::DVD):
            return "DVD";
            break;
    }

    return "";
}

void livre::affiche(std::ostream &out) const
{
    documentEcris::affiche(out);
}

void periodique::affiche(std::ostream &out) const
{
    documentEcris::affiche(out);
    std::string str = "| Num : " + std::to_string(_numero);
    out <<str;
}

void documentEcris::affiche(std::ostream &out) const
{
    document::affiche(out);
    std::string str = " | Nb pages : " + std::to_string(_nbPages);

    out << str;
}
