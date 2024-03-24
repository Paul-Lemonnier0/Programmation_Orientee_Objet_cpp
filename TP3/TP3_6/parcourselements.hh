#ifndef PARCOURSELEMENTS_HH
#define PARCOURSELEMENTS_HH
#include <vector>

class ParcoursElements
{
    private:
        std::size_t _positionCourante;

    public:
        ParcoursElements():
            _positionCourante(0){};

        std::size_t positionCourante() const;
        void passerausuivant();
};

#endif // PARCOURSELEMENTS_HH
