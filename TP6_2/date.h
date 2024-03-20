#pragma once
#include <string>

class date
{
private:
    int _month, _year, _day;

public:
    date(int year, int month, int day){

        if(day)

        _year = year;
        _month = month;
        _day = day;
    };

    int month() const;
    int year() const;
    int day() const;

    void operator =(date const & d){
       _month = d._month;
       _year = d._year;
       _day = d._day;
    }

    friend std::ostream& operator <<(std::ostream& os, date const & d);
};

