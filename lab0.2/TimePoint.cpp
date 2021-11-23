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

TimePoint::TimePoint(const TimePoint& other) {
    hours = other.hours;
    minutes = other.minutes;
    seconds = other.seconds;
    std:: cout << "The copy of your time-object has been created" << std:: endl;
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

TimePoint TimePoint::operator + (const TimePoint &object) {
    int x = hours * 3600 + minutes * 60 + seconds;
    int y = object.hours * 3600 + object.minutes * 60 + object.seconds;
    int z = x + y;
    int dhours = z / 3600;
    int dminutes = (z % 3600) / 60;
    int dseconds = (z % 3600) - (dminutes * 60);
    this->hours = dhours;
    this->minutes = dminutes;
    this->seconds = dseconds;
    return *this;
}

TimePoint TimePoint::operator - (const TimePoint &object) {
    int x = hours * 3600 + minutes * 60 + seconds;
    int y = object.hours * 3600 + object.minutes * 60 + object.seconds;
    int dhours, dminutes, dseconds;
    if ((hours > object.hours) || (hours == object.hours && minutes > object.minutes) || (hours == object.hours && minutes == object.minutes && seconds > object.seconds)) {
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
    this->hours = dhours;
    this->minutes = dminutes;
    this->seconds = dseconds;
    return *this;
}

bool TimePoint::operator == (const TimePoint &object) {
    if (hours == object.hours && minutes == object.minutes && seconds == object.seconds) {
        return true;
    }
    return false;
}

bool TimePoint::operator > (const TimePoint &other) {
    if ((hours > other.hours) || (hours == other.hours && minutes > other.minutes) || (hours == other.hours && minutes == other.minutes && seconds > other.seconds)) {
        return true;
    }
    else {
        return false;
    }
}

bool TimePoint::operator < (const TimePoint &other) {
    if ((hours < other.hours) || (hours == other.hours && minutes < other.minutes) || (hours == other.hours && minutes == other.minutes && seconds < other.seconds)) {
        return true;
    }
    else {
        return false;
    }
}

std::istream& operator >> (std::istream& is, TimePoint &object) {
    std:: cout << "Please enter your time-object data: " << std:: endl;
    is >> object.hours >> object.minutes >> object.seconds;
    if ((object.hours < 0 || object.hours > 23) || (object.minutes < 0 || object.minutes > 59) || (object.seconds < 0 || object.seconds > 59)) {
        std:: cout << "Invalind input. Enter again!" << std:: endl;
        is >> object.hours >> object.minutes >> object.seconds;
    }
    return is;
}

std::ostream& operator << (std::ostream& os, TimePoint &object) {
    os << object.hours << ":" << object.minutes << ":" << object.seconds << std:: endl;
    return os;
}

TimePoint::~TimePoint() {
    std:: cout << "FROM DESTRUCTOR: Your time-object has been deleted" << std:: endl;
}