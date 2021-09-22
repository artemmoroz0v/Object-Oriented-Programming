#include "hexagon.h"
#include <cmath>

Hexagon::Hexagon(std::istream &InputStream) 
  {
      InputStream >> a;
      InputStream >> b;
      InputStream >> c;
      InputStream >> d;
      InputStream >> e;
      InputStream >> f;
      std:: cout << "Hexagon that you wanted to create has been created" << std:: endl;
  }

   void Hexagon::Print(std::ostream &OutputStream) {
      OutputStream << "Hexagon: ";
      OutputStream << a << " " << b << " " << c << " " << d << " " << e << " " << f << std:: endl;
  }

  size_t Hexagon::VertexesNumber() {
       size_t number = 6;
       return number;
   }

   double Hexagon::Area() {
   double q = abs(a.X() * b.Y() + b.X() * c.Y() + c.X() * d.Y() + d.X() * e.Y() + e.X() * f.Y() + f.X() * a.Y()  - b.X() * a.Y() - c.X() * b.Y() - d.X() * c.Y() - e.X() * d.Y() - f.X() * e.Y() - a.X() * f.Y());
   double s = q / 2;
   return s;
   }


      Hexagon::~Hexagon() {
          std:: cout << "My friend, your hexagon has been deleted" << std:: endl;
      }