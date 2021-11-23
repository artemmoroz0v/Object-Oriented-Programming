#include "TimePoint.h"

//literals
unsigned long long operator "" _tohours(unsigned long long sec) {
    unsigned long long hours_lit = sec / 3600;
    return hours_lit;
}

unsigned long long operator "" _tominutes(unsigned long long sec) {
    unsigned long long minutes_lit = sec / 60;
    return minutes_lit;
}

int main () {
    TimePoint a(15,0,5);
    TimePoint b(15,0,5);
    std:: cout << (b == a) << std:: endl;
    std:: cout << (a > b) << std:: endl;
    std:: cout << (b < a) << std:: endl;
    TimePoint c = a + b;
    std:: cout << c;
    TimePoint d;
    std:: cin >> d;
    TimePoint e = d - b;
    std:: cout << e;
    TimePoint x(23,59,59);
    TimePoint y = x - a;
    TimePoint j, h, u;
    std:: cin >> j >> h >> u;
    std:: cout << j << h << u;
    std:: cout << "The example of using to-hours literal is: " << 3600_tohours << std:: endl;
    std:: cout << "The example of using to-minutes literal is: " << 50505_tominutes << std:: endl;
    return 0;
}