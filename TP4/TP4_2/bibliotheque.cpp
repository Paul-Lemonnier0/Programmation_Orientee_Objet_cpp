#include "bibliotheque.h"

bibliotheque::bibliotheque()
{

}

bibliotheque::~bibliotheque()
{
    for(auto doc : _documents){
        delete doc;
    }
}

void bibliotheque::ajouterDocument(const document &d)
{
    _documents.push_back(d.clone());
}

std::vector<document *> bibliotheque::getDocuments() const{
    std::vector<document *> docs;

    for(auto d: _documents){
        docs.push_back(d->clone());
    }

    return docs;
}

bibliotheque bibliotheque::clone() const
{
    bibliotheque newBibliotheque;
    newBibliotheque._documents = getDocuments();

    return newBibliotheque;
}

void bibliotheque::afficherBibliothèque(std::ostream &out) const
{
    std::vector<document *> docs = getDocuments();

    std::string jumpLine = "\n";
    for(auto d: docs){
        d->affiche(out);
        out<<jumpLine;
    }
}


int bibliotheque::nbInstancesSupportvideo(typeSupport support) const
{
    int nb = 0;
    for(auto d: _documents){
        if(dynamic_cast<video const *>(d)){
            video * v = new video(*(dynamic_cast<video const *>(d)));
            if(v->getSupport() == support){
                ++nb;
            }
        }
    }

    return nb;
}
