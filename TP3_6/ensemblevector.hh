#ifndef ENSEMBLEVECTOR_HH
#define ENSEMBLEVECTOR_HH
#include "ensemble.hh"
#include <vector>

class EnsembleVector: public Ensemble {
    private:
        std::vector<int> _tab;

    public:
        EnsembleVector():
            _tab(){};

        EnsembleVector(EnsembleVector const & ensembleVector):
            _tab(ensembleVector._tab){};

        bool appartient(int x) const override;
        void afficher() const override;
        bool vide() const override;
        void enlever(int x) override;
        void ajouter(int x) override;
        void creerEnsembleVide() override;

        bool estfini(ParcoursElements const & p) const override;
        int courant(ParcoursElements const & p) const override;
};

#endif // ENSEMBLEVECTOR_HH
