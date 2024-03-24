#include "arrayint.h"
#include <vector>
#include <iostream>

std::vector<int> arrayint::array() const
{
    return _array;
}

signed int arrayint::imin() const
{
    return _imin;
}

signed int arrayint::imax() const
{
    return _imax;
}

std::string arrayint::tostring() const
{
    return "[" + std::to_string(_imin) + ", " + std::to_string(_imax) + "]";
}

int arrayint::at(signed int index) const
{
    try{
        if(index < _imin || index > _imax){
            throw exceptionarrayint(index);
        }

        else{
            return _array[index - _imin];
        }
    }

    catch(exceptionarrayint& e){
        std::cout<<e.what();
        return -1;
    }
}

void arrayint::set(signed int index, int value)
{
    try{
        if(index < _imin || index > _imax){
            throw exceptionarrayint(index);
        }

        else{
            _array[index - _imin] = value;
        }
    }

    catch(std::exception& e){
        std::cout<<e.what();
    }
}

int arrayint::at_throw_error(signed int index) const
{
    if(index < _imin || index > _imax){
        throw exceptionarrayint(index);
    }

    else{
        return _array[index - _imin];
    }
}

std::ostream& arrayint::operator<<(std::ostream & out){
    std::string str = "";

    try{
        signed int index= imin();

        while(true){
            int value = at_throw_error(index);
            str += "Valeur en " + std::to_string(index) + " : " + std::to_string(value) + "\n";

            ++index;
        }

        out<<str;
        return out;
    }

    catch(std::exception &e){
        out<<str;
        return out;
    }
}
