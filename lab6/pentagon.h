#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"
#include <iostream>


class Pentagon : public Figure {
    public:
    Pentagon(std::istream &InputStream);
    Pentagon();
    double GetArea();
    size_t VertexesNumber();
    double Area();
    void Print(std::ostream &OutputStream);
    friend bool operator == (Pentagon& p1, Pentagon& p2);
    friend std::ostream& operator << (std::ostream& os, Pentagon& p);
    virtual ~Pentagon();
    double area;

    private:
    Point a;
    Point b;
    Point c;
    Point d;
    Point e;
};
#endif
