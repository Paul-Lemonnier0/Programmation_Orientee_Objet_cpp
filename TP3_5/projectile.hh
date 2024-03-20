#ifndef PROJECTILE_HH
#define PROJECTILE_HH

#include "objet.hh"

class Projectile: public Objet {
    public:
        Projectile(Position const & p):
            Objet(p, Taille(1, 1)){};

        std::string typeObjet() override;
};

#endif // PROJECTILE_HH
