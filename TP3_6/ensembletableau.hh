#ifndef ENSEMBLETABLEAU_HH
#define ENSEMBLETABLEAU_HH
#include "ensemble.hh"
#include <array>

class EnsembleTableau: public Ensemble {
    private:
        std::size_t _taille;
        int * _tab;

    public:
        EnsembleTableau():
            _taille(0),
            _tab(new int[0]){};

        EnsembleTableau(EnsembleTableau const & ensembleTableau):
            _tab(ensembleTableau._tab),
            _taille(ensembleTableau._taille){};

        bool appartient(int x) const override;
        bool vide() const override;
        void afficher() const override;
        void creerEnsembleVide() override;
        void ajouter(int x) override;
        void enlever(int x) override;

        bool estfini(ParcoursElements const & p) const override;
        int courant(ParcoursElements const & p) const override;
};

#endif // ENSEMBLETABLEAU_HH
