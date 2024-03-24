#include <array>

#ifndef SEQUENCE_H
#define SEQUENCE_H

enum class couleur { null, rouge, bleu, jaune, vert };
using indicesequence = unsigned char;

const int sizeSequenceMax = 100;

struct sequence{
    std::array<couleur, sizeSequenceMax> T;
    indicesequence taille = sizeSequenceMax;
};

void sc_initialiservide(sequence & sec);
void sc_ajouter(sequence & sec, couleur c);
void sc_copier(sequence & b, sequence a);
couleur sc_acces(sequence sec, indicesequence index);
void sc_afficher(couleur c);
void sc_afficher(sequence sec);
void sc_vider(sequence & sec);
bool sc_comparer(sequence a, sequence b);

#endif // SEQUENCE_H
