#include "octagon.h"
#include <cmath>

Octagon::Octagon(std::istream &InputStream) 
  {
      InputStream >> a;
      InputStream >> b;
      InputStream >> c;
      InputStream >> d;
      InputStream >> e;
      InputStream >> f;
      InputStream >> g;
      InputStream >> h;
      std:: cout << "Octagon that you wanted to create has been created" << std:: endl;
  }

   void Octagon::Print(std::ostream &OutputStream) {
      OutputStream << "Octagon: ";
      OutputStream << a << " " << b << " " << c << " " << d << " " << e << " " << f  << " " << g << " " << h << std:: endl;
  }

  size_t Octagon::VertexesNumber() {
       size_t number = 8;
       return number;
   }

   double Octagon::Area() {
   double q = abs(a.X() * b.Y() + b.X() * c.Y() + c.X() * d.Y() + d.X() * e.Y() + e.X() * f.Y() + f.X() * g.Y() + g.X() * h.Y() + h.X() * a.Y() - b.X() * a.Y() - c.X() * b.Y() - d.X() * c.Y() - e.X() * d.Y() - f.X() * e.Y() - g.X() * f.Y() - h.X() * g.Y() - a.X() * h.Y());
   double s = q / 2;
   return s;
   }


      Octagon::~Octagon() {
          std:: cout << "My friend, your octagon has been deleted" << std:: endl;
      }