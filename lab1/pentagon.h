#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"
#include <iostream>


class Pentagon : public Figure {
    public:
    Pentagon(std::istream& InputStream);

    virtual ~Pentagon();

    size_t VerticesNumber();
    double Area();
    void Print(std::ostream &OutputStream);

    private:
    Point a;
    Point b;
    Point c;
    Point d;
    Point e;
};
#endif
