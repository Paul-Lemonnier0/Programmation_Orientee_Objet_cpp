#include <array>
#include <iostream>
#ifndef SEQUENCE_HH
#define SEQUENCE_HH

enum class couleur { null, rouge, bleu, jaune, vert };
using indicesequence = std::size_t;

class sequence
{
    private:
        indicesequence _taille, _tailleAllouee;
        couleur * _couleurs;

    public:
        sequence();
        sequence(sequence & s);

        indicesequence taille();
        indicesequence tailleAllouee();
        couleur * couleurs();

        void setTaille(indicesequence taille);
        void setTailleAllouee(indicesequence tailleAllouee);
        void setCouleurs(couleur * couleurs);

        void ajouter(couleur c);
        void afficher(couleur c);
        void afficher(std::ostream &aff);
        void vider();
        void copier(sequence a);
        bool comparer(sequence a);
        couleur acces(indicesequence index);
};

#endif // SEQUENCE_HH
