#include "TimePoint.h"

int main () {
    TimePoint a(std:: cin);
    TimePoint b(12, 38, 40);
    TimePoint c(20, 20, 41);
    TimePoint d(c);
    c.Difference(d);
    b.Sum(c);
    d.AddSeconds(3600);
    c.Print(std:: cout);
    d.Print(std:: cout);
    b.RemoveSeconds(3240);
    b.Print(std:: cout);
    a.Compare(c);
    TimePoint e(06, 00, 00);
    TimePoint f(18, 00, 00);
    std:: cout << "The diffrence between times in their division is: " << e.IsBigger(f) << std:: endl;
    std:: cout << "Your time in minutes is: " << a.ToMinutes() << std:: endl;
    std:: cout << "Your time is seconds is: " << a.ToSeconds() << std:: endl;
    return 0;
}