
#include <iostream>
using namespace std;

struct Parcel {
    double weight;
};

double charge(int grams, bool express = false, bool insured = false) {
    double amount = grams * 0.05;

    if (express)
        amount += 30;

    if (insured)
        amount += 20;

    cout << "Integer grams overload: ";
    return amount;
}

double charge(double kilograms, bool express = false,
              bool insured = false) {
    double amount = kilograms * 50;

    if (express)
        amount += 30;

    if (insured)
        amount += 20;

    cout << "Double kg overload: ";
    return amount;
}

double charge(Parcel p, bool express = false,
              bool insured = false) {
    double amount = p.weight * 50;

    if (express)
        amount += 30;

    if (insured)
        amount += 20;

    cout << "Parcel overload: ";
    return amount;
}

int main() {
    Parcel p = {3.5};

    cout << charge(2) << endl;
    cout << charge(2.0) << endl;
    cout << charge(2.0f) << endl;
    cout << charge(500, true) << endl;
    cout << charge(2.5, true, true) << endl;
    cout << charge(p, false, true) << endl;

    return 0;
}
