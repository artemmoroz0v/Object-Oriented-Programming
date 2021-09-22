#include <iostream>
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"

int main ()
{
    Pentagon a (std:: cin);
    std:: cout << "The amount of vertices in your figure is : " << a.VertexesNumber() << std:: endl;
    a.Print (std::cout);
    std:: cout << "The area of your figure is : " << a.Area() << std:: endl;
        
    Hexagon b (std:: cin);
    std:: cout << "The amount of vertices in your figure is : " << b.VertexesNumber() << std:: endl;
    b.Print (std:: cout);
    std:: cout << "The area of your figure is : " << b.Area() << std:: endl;

    Octagon c (std:: cin);
    std:: cout << "The amount of vertices in your figure is : " << c.VertexesNumber() << std:: endl;
    c.Print (std:: cout);
    std:: cout << "The area of your figure is : " << c.Area() << std:: endl;
    return 0;
}
