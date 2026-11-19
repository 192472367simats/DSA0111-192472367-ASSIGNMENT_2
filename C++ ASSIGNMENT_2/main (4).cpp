
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace chrono;

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

// Friend function 1
int minutesBetween(const Time& a, const Time& b) {
    int timeA = a.h * 60 + a.m;
    int timeB = b.h * 60 + b.m;

    return abs(timeA - timeB);
}

// Friend function 2
bool earlier(const Time& a, const Time& b) {
    if (a.h != b.h)
        return a.h < b.h;

    return a.m < b.m;
}

// Inline function
inline int inlineSquare(int x) {
    return x * x;
}

// Normal function
int normalSquare(int x) {
    return x * x;
}

int main() {
    cout << "TRAIN JOURNEY PLANNER\n";

    Time departure(9, 45);
    Time arrival(13, 10);

    cout << "Minutes between times: "
         << minutesBetween(departure, arrival) << endl;

    cout << "Arrival earlier than departure: "
         << boolalpha
         << earlier(arrival, departure) << endl;

    cout << "\nCORRECTNESS TESTS\n";

    Time morning(11, 30);
    Time afternoon(12, 30);

    cout << "Across noon: "
         << minutesBetween(morning, afternoon) << endl;

    cout << "Morning earlier: "
         << earlier(morning, afternoon) << endl;

    Time same1(10, 15);
    Time same2(10, 15);

    cout << "Same time difference: "
         << minutesBetween(same1, same2) << endl;

    cout << "Same time earlier: "
         << earlier(same1, same2) << endl;

    cout << "\nINLINE AND NORMAL FUNCTIONS\n";

    cout << "Inline square: "
         << inlineSquare(5) << endl;

    cout << "Normal square: "
         << normalSquare(5) << endl;

    cout << "\nTIMING TEST: 10000000 CALLS\n";

    const int N = 10000000;
    volatile long long result = 0;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        result = result + inlineSquare(i);
    }

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        result = result + normalSquare(i);
    }

    auto end2 = high_resolution_clock::now();

    cout << "Inline time: "
         << duration_cast<milliseconds>(end1 - start1).count()
         << " ms" << endl;

    cout << "Normal function time: "
         << duration_cast<milliseconds>(end2 - start2).count()
         << " ms" << endl;

    cout << "Result: " << result << endl;

    return 0;
}
