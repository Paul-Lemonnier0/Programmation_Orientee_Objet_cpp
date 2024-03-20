#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "exceptionarraylist.h"


class arrayint
{

private:
    std::vector<int> _array;
    signed int _imin, _imax;

public:
    arrayint(signed int imin, signed int imax):
        _imin(imin), _imax(imax){
        int interval = imax - imin;

        for(int i = 1; i<= interval+1; ++i){
            _array.push_back(i);
        }
    };

    arrayint(arrayint const & tab) = default;

    signed int imin() const;
    signed int imax() const;

    std::string tostring() const;

    int at(signed int index) const;
    int at_throw_error(signed int index) const;

    int operator [](int index){
        return at(index);
    }

    void set (signed int index, int value);
    void operator =(arrayint const & tab){

        _imin = tab._imin;
        _imax = tab._imax;
        _array = tab._array;

    }

    bool operator ==(arrayint const & tab){
        return
                _imin == tab._imin
                && _imax == tab._imax
                && _array == tab._array;
    }

    typedef std::vector<int>::const_iterator const_iterator;

    std::vector<int>::const_iterator begin(){

        return _array.begin();
    }
    std::vector<int>::const_iterator end(){
        return _array.end();
    }


    std::vector<int> array() const;
    std::ostream& operator<<(std::ostream & out);
};
