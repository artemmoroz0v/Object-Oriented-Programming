#ifndef TIMEPOINT_H
#define TIMEPOINT_H
#include <iostream>
class TimePoint {
    public:
        TimePoint();
        TimePoint(int h, int m, int s);
        TimePoint(std::istream &is);
        TimePoint(const TimePoint &other);
        void Difference(const TimePoint &other);
        void Sum(const TimePoint& other);
        void AddSeconds(int s);
        void RemoveSeconds(int s);
        int IsBigger(const TimePoint &other);
        void Compare(const TimePoint &other);
        int ToSeconds();
        int ToMinutes();
        void Print(std::ostream &os);
        ~TimePoint();
    private:
        int hours;
        int minutes;
        int seconds;
};
#endif