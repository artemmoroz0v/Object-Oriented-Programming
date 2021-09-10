#include "pentagon.h"
#include <cmath>

    Pentagon::Pentagon(std::istream &InputStream) 
  {
      InputStream >> a;
      InputStream >> b;
      InputStream >> c;
      InputStream >> d;
      InputStream >> e;
      std:: cout << "Pentagon that you wanted to create has been created" << std:: endl;
  }

  void Pentagon::Print(std::ostream &OutputStream) {
      OutputStream << "Pentagon: ";
      OutputStream << a << " " << b << " " << c << " " << d << " " << e << std:: endl;
      
  }

   size_t Pentagon::VerticesNumber() {
       size_t number = 5;
       return number;
   }

   double Pentagon::Area() {
   double q = abs(a.X() * b.Y() + b.X() * c.Y() + c.X() * d.Y() + d.X() * e.Y() + e.X() * a.Y() - b.X() * a.Y() - c.X() * b.Y() - d.X() * c.Y() - e.X() * d.Y() - a.X() * e.Y());
   double s = q / 2;
   return s;
   }


      Pentagon::~Pentagon() {
          std:: cout << "My friend, your pentagon has been deleted" << std:: endl;
      }