#ifndef TIMEPOINT_H
#define TIMEPOINT_H
#include <iostream>
class TimePoint {
    public:
        TimePoint();
        TimePoint(int h, int m, int s);
        TimePoint(const TimePoint &other);
        void AddSeconds(int s);
        void RemoveSeconds(int s);
        int IsBigger(const TimePoint &other);
        int ToSeconds();
        int ToMinutes();
        TimePoint operator + (const TimePoint &object);
        TimePoint operator - (const TimePoint &object);
        bool operator == (const TimePoint &object);
        bool operator > (const TimePoint &other);
        bool operator < (const TimePoint &other);
        friend std::istream& operator >> (std::istream& is, TimePoint &object);
        friend std::ostream& operator <<(std::ostream& os, TimePoint &object);
        ~TimePoint();
    private:
        int hours;
        int minutes;
        int seconds;
};
#endif