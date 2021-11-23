#include "TimePoint.h"

TimePoint::TimePoint() {
    hours = 0;
    minutes = 0;
    seconds = 0;
    std:: cout << "The default time-ojbect has been created" << std:: endl;
}

TimePoint::TimePoint(int h, int m, int s) {
    if (h >= 0 && m >= 0 && s >= 0) {
        hours = h;
        minutes = m;
        seconds = s;
    }
    else {
        std:: cout << "Please enter positive numbers!" << std:: endl;
    }
    std:: cout << "The time-object according to your parameters has been created" << std:: endl;
}

TimePoint::TimePoint(std::istream &is) {
    std:: cout << "Please enter your time-object data: " << std:: endl;
    is >> hours >> minutes >> seconds;
    if ((hours < 0 || hours > 23) || (minutes < 0 || minutes > 59) || (seconds < 0 || seconds > 59)) {
        std:: cout << "Invalind input. Enter again!" << std:: endl;
        is >> hours >> minutes >> seconds;
    }
    std:: cout << "The time-object has been created via istream" << std:: endl;
}

TimePoint::TimePoint(const TimePoint& other) {
    hours = other.hours;
    minutes = other.minutes;
    seconds = other.seconds;
    std:: cout << "The copy of your time-object has been created" << std:: endl;
}

void TimePoint::Difference(const TimePoint &other) {
    int x = hours * 3600 + minutes * 60 + seconds;
    int y = other.hours * 3600 + other.minutes * 60 + other.seconds;
    int dhours, dminutes, dseconds;
    if ((hours > other.hours) || (hours == other.hours && minutes > other.minutes) || (hours == other.hours && minutes == other.minutes && seconds > other.seconds)) {
        int z = x - y;
        dhours = z / 3600;
        dminutes = (z % 3600) / 60;
        dseconds = (z % 3600) - (dminutes * 60);
    }
    else {
        int z = y - x;
        dhours = z / 3600;
        dminutes = (z % 3600) / 60;
        dseconds = (z % 3600) - (dminutes * 60);
    }
    std:: cout << "The difference between your time-objects is: " << dhours << ":" << dminutes << ":" << dseconds << std:: endl; 
}

void TimePoint::Sum(const TimePoint& other) {
    int x = hours * 3600 + minutes * 60 + seconds;
    int y = other.hours * 3600 + other.minutes * 60 + other.seconds;
    int z = x + y;
    int dhours = z / 3600;
    int dminutes = (z % 3600) / 60;
    int dseconds = (z % 3600) - (dminutes * 60);
    std:: cout << "The sum of your time-objects is: " << dhours << ":" << dminutes << ":" << dseconds << std:: endl;
}

void TimePoint::AddSeconds(int s) {
    if (s < 0) {
        std:: cout << "Please enter positive number!" << std:: endl;
    }
    else {
        int x = hours * 3600 + minutes * 60 + seconds + s;
        hours = x / 3600;
        minutes = ((x % 3600) / 60);
        seconds = (x % 3600) - (((x % 3600) / 60) * 60);
        std:: cout << "After adding seconds your time is: "  << hours << ":" << minutes << ":" << seconds << std:: endl;
    }
}

void TimePoint::RemoveSeconds(int s) {
    if (s < 0) {
        std:: cout << "Please enter positive number!" << std:: endl;
    }
    else {
        int x = hours * 3600 + minutes * 60 + seconds - s;
        hours = x / 3600;
        minutes = ((x % 3600) / 60);
        seconds = (x % 3600) - (((x % 3600) / 60) * 60);
        std:: cout << "After removing seconds your time is: "  << hours << ":" << minutes << ":" << seconds << std:: endl;
    }
}

int TimePoint::IsBigger(const TimePoint &other ) {
    int x = hours * 3600 + minutes * 60 + seconds;
    int y = other.hours * 3600 + other.minutes * 60 + other.seconds;
    if ((hours > other.hours) || (hours == other.hours && minutes > other.minutes) || (hours == other.hours && minutes == other.minutes && seconds > other.seconds)) {
        return x / y;
    }
    return y / x;
}

void TimePoint::Compare(const TimePoint &other) {
    if ((hours > other.hours) || (hours == other.hours && minutes > other.minutes) || (hours == other.hours && minutes == other.minutes && seconds > other.seconds)) {
        std:: cout << "The first time is more that second time!" << std:: endl;
    }
    else if (hours == other.hours && minutes == other.minutes && seconds == other.seconds) {
        std:: cout << "Times are equal!" << std:: endl;
    }
    else {
        std:: cout << "The second time is more that first time!" << std:: endl;
    }    
}

int TimePoint::ToSeconds() {
    return hours * 3600 + minutes * 60 + seconds;
}

int TimePoint::ToMinutes() {
    int z = hours * 3600 + minutes * 60 + seconds;
    int m = z / 60;
    if (z % 60 == 0) {
        return m;
    }
    else {
        if (z % 60 >= 30) {
            return m + 1;
        }
    }
    return m;
}

void TimePoint::Print(std::ostream& os) {
    os << "Your current time is: " << hours << ":" << minutes << ":" << seconds << std:: endl;
}

TimePoint::~TimePoint() {
    std:: cout << "FROM DESTRUCTOR: Your time-object has been deleted" << std:: endl;
}