#include <array>

#ifndef SEQUENCE_HH
#define SEQUENCE_HH

enum class couleur { null, rouge, bleu, jaune, vert };
using indicesequence = std::size_t;

struct sequence{
    couleur * couleurs;
    indicesequence taille;
    indicesequence tailleAllouee;
};

void sc_initialiservide(sequence & sec);
void sc_ajouter(sequence & sec, couleur c);
void sc_afficher(couleur c);
void sc_afficher(sequence sec);
void sc_vider(sequence & sec);
void sc_copier(sequence & b, sequence a);
bool sc_comparer(sequence a, sequence b);
couleur sc_acces(sequence sec, indicesequence index);

#endif // SEQUENCE_HH
