#include <array>
#include <iostream>
#include <vector>

#ifndef SEQUENCE_HH
#define SEQUENCE_HH

enum class couleur { null, rouge, bleu, jaune, vert };
using indicesequence = std::vector<int>::size_type;

class sequence
{
    private:
        std::vector<couleur> _couleurs;

    public:
        sequence();
        sequence(sequence & s);

        indicesequence taille();
        std::vector<couleur> couleurs();


        void setCouleurs(std::vector<couleur> couleurs);

        void ajouter(couleur c);
        void afficher(couleur c);
        void afficher(std::ostream &aff);
        void vider();
        void copier(sequence a);
        bool comparer(sequence a);
        couleur acces(indicesequence index);
};

#endif // SEQUENCE_HH
