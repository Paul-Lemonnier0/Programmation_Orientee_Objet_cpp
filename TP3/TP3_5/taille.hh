#ifndef TAILLE_HH
#define TAILLE_HH
#include <string>


class Taille
{

private:
    unsigned int _largeur, _hauteur;

public:
    Taille(unsigned int largeur, unsigned int hauteur): _largeur(largeur), _hauteur(hauteur){};
    Taille(Taille const & t): _largeur(t._largeur), _hauteur(t._hauteur){};

    unsigned int w();
    unsigned int h();

    void setW(unsigned int w);
    void setH(unsigned int h);

    std::string tostring();
};

#endif // TAILLE_HH
