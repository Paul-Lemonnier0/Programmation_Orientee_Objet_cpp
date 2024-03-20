#include "date.h"

int date::day() const
{
    return _day;
}

int date::year() const
{
    return _year;
}

int date::month() const
{
    return _month;
}

std::ostream& operator <<(std::ostream& os, date const & d){
    std::string str = std::to_string(d._day) + "/" + std::to_string(d._month) + "/" + std::to_string(d._year);
    os << str;
    return os;
}
