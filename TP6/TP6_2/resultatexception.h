#pragma once
#include <exception>
#include <string>

enum class errorType {
    noSpaceLeft,
    outRangeNumber,
    valueAlreadyAdded
};

class resultatexception: public std::exception
{
private:
    std::string _msg;

public:
    resultatexception(errorType e, int value){
        switch(e){
            case errorType::noSpaceLeft:
                _msg = "Liste pleines. Impossible d'ajouter la valeur : " + std::to_string(value);
                break;

            case errorType::outRangeNumber:
                 _msg = "Valeur en dehors de l'interval [1, 49]. Impossible d'ajouter la valeur : " + std::to_string(value);
                break;

            case errorType::valueAlreadyAdded:
                 _msg = "Valeur en dehors de l'interval [1, 49]. Impossible d'ajouter la valeur : " + std::to_string(value);
                break;
        }
    }

    const char *what() const noexcept;
};
