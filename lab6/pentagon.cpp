#include "pentagon.h"
#include <cmath>

    Pentagon::Pentagon() {
        a.X() == 0.0; a.Y() == 0.0;
        b.X() == 0.0; b.Y() == 0.0;
        c.X() == 0.0; c.Y() == 0.0;
        d.X() == 0.0; d.Y() == 0.0;
        e.X() == 0.0; e.Y() == 0.0;
    }

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

   size_t Pentagon::VertexesNumber() {
       size_t number = 5;
       return number;
   }

   double Pentagon::Area() {
   double q = abs(a.X() * b.Y() + b.X() * c.Y() + c.X() * d.Y() + d.X() * e.Y() + e.X() * a.Y() - b.X() * a.Y() - c.X() * b.Y() - d.X() * c.Y() - e.X() * d.Y() - a.X() * e.Y());
   double s = q / 2;
   this->area = s;
   return s;
   }

   double Pentagon:: GetArea() {
       return area;
   }

    Pentagon::~Pentagon() {
          std:: cout << "My friend, your pentagon has been deleted" << std:: endl;
      }

    bool operator == (Pentagon& p1, Pentagon& p2){
        if(p1.a == p2.a && p1.b == p2.b && p1.c == p2.c && p1.d == p2.d && p1.e == p2.e) {
            return true;
        }
        return false;
    }
    
    std::ostream& operator << (std::ostream& os, Pentagon& p){
    os << "Pentagon: ";
    os << p.a << p.b << p.c << p.d << p.e;
    os << std::endl;
    return os;
}