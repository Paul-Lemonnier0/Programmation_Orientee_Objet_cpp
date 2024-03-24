#include "figure.hh"
#include "rectangle.hh"
#include "triangle.hh"
#include "segment.hh"

int main()
{
    Couleur c;
    c.R = 10;
    c.G = 5;
    c.B = 4;

    Point p1;
    Figure f (c, p1);

    Point p2(1,1);
    Figure f2 (c, p2);

    Rectangle r (f, 3, 3);
    Rectangle r2 (f2, 2, 3);
    std::cout<<r.tostring();

    std::cout<<"Meme origine : "<<r.memeOrigine(r2)<<"\n";

    Point v(3,3);
    r.translation(v);
    std::cout<<r.tostring();

    std::cout<<"Est carrée 1 : "<<r.estCarre1()<<"\n";

    return 0;
}
