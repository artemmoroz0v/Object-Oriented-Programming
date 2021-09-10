#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"
#include <iostream>


class Octagon : public Figure {
    public:
    Octagon(std::istream &InputStream);

    virtual ~Octagon();

    size_t VerticesNumber();
    double Area();
    void Print(std::ostream &OutputStream);


        private:
    Point a;
    Point b;
    Point c;
    Point d;
    Point e;
    Point f;
    Point g;
    Point h;
};

#endif