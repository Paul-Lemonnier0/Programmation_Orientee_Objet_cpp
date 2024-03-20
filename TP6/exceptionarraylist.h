#pragma once
#include <string>
#include <exception>

class exceptionarrayint: public std::exception{
    private:
        std::string _msg;

    public:
        exceptionarrayint(signed int indice):
            _msg("Erreur d'indice => indice donné : " + std::to_string(indice) + "\n"){};

        const char * what() const noexcept;
};
