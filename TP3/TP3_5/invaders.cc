#include "invaders.hh"

direction Invaders::dir(){
    return _direction;
}

int Invaders::xmax(){
    return _xmax;
}

int Invaders::xmin(){
    return _xmin;
}

std::string Invaders::typeObjet(){
    return "I";
}
