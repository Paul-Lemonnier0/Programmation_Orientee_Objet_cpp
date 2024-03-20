#pragma once
#include <string>

enum class typeSupport {DVD, BluRay, BluRay3D};

class document
{

    protected:
        bool _empruntable;
        float _cout;
        std::string _titre;
        std::string _nomAuteur;

    public:
        document(float cout, std::string const & titre, std::string const & nomAuteur, bool empruntable):
            _empruntable(empruntable), _cout(cout), _titre(titre), _nomAuteur(nomAuteur){};

        virtual ~document() = default;
        virtual document * clone() const = 0;

        virtual void affiche(std::ostream &out) const;
        virtual std::string getTypeDocument() const = 0;
};

class documentEcris: public document{

    private:
        int _nbPages;

    public:
        documentEcris(int nbPages, std::string const & titre, std::string const & nomAuteur, bool empruntable):
           document((0.5 * nbPages), titre, nomAuteur, empruntable), _nbPages(nbPages){};

        void affiche(std::ostream &out) const override;
};

class livre: public documentEcris{

    public:
        livre(int nbPages, std::string const & titre, std::string const & nomAuteur, bool empruntable):
           documentEcris(nbPages, titre, nomAuteur, empruntable){};

        void affiche(std::ostream &out) const override;
        std::string getTypeDocument() const override;

        document *clone() const override {
            return new livre(*this);
        };
};

class periodique: public documentEcris{

    private:
        int _numero;

    public:
        periodique(int nbPages, int numero, std::string const & titre, std::string const & nomAuteur):
           documentEcris(nbPages, titre, nomAuteur, false), _numero(numero){};

        void affiche(std::ostream &out) const override;
        std::string getTypeDocument() const override;

        document *clone() const override {
            return new periodique(*this);
        };
};


class video: public document{

    private:
        typeSupport _support;

    public:
        video(typeSupport support, std::string const & titre, std::string const & nomAuteur):
           document(70, titre, nomAuteur, true), _support(support){};

        void affiche(std::ostream &out) const override;
        std::string getTypeDocument() const override;

        std::string getSupportString() const;

        void setTitre(std::string s){
            _titre = s;
        }

        document *clone() const override {
            return new video(*this);
        };

        typeSupport getSupport() const;
};




