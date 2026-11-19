
#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b) {
    int timeA = a.h * 60 + a.m;
    int timeB = b.h * 60 + b.m;

    return abs(timeA - timeB);
}

inline bool earlier(const Time& a, const Time& b) {
    if (a.h < b.h)
        return true;

    if (a.h == b.h && a.m < b.m)
        return true;

    return false;
}

int main() {
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha
         << earlier(arrival, departure) << '\n';

    Time morning(11, 30);
    Time afternoon(12, 30);

    cout << "Minutes between noon times: "
         << minutesBetween(morning, afternoon) << endl;

    cout << "Morning earlier: "
         << earlier(morning, afternoon) << endl;

    cout << "Same time difference: "
         << minutesBetween(morning, morning) << endl;

    cout << "Same time comparison: "
         << earlier(morning, morning) << endl;

    return 0;
}
