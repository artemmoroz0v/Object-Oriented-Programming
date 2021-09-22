#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"
#include <iostream>


class Hexagon : public Figure {
    public:
    Hexagon(std::istream &InputStream);

    virtual ~Hexagon();

    size_t VertexesNumber();
    double Area();
    void Print(std::ostream &OutputStream);


        private:
    Point a;
    Point b;
    Point c;
    Point d;
    Point e;
    Point f;
};

#endif