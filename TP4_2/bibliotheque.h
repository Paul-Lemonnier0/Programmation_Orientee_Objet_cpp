#pragma once
#include "document.h"
#include <vector>

class bibliotheque
{
private:
    std::vector<document *> _documents;

public:
    bibliotheque();
    ~bibliotheque();

    void ajouterDocument(document const & d);
    void afficherBibliothèque(std::ostream &out) const;
    int nbInstancesSupportvideo(typeSupport support) const;
    std::vector<document *> getDocuments() const;

    bibliotheque clone() const;

};
