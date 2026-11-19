
#include <iostream>
using namespace std;

struct Parcel {
    double weight;
};

// Double weight in kilograms
double charge(double weight,
              bool express = false,
              bool insured = false) {
    double amount = weight * 50;

    if (express)
        amount += 100;

    if (insured)
        amount += 50;

    return amount;
}

// Integer weight in grams
double charge(int grams,
              bool express = false,
              bool insured = false) {
    double weight = grams / 1000.0;
    return charge(weight, express, insured);
}

// Parcel object
double charge(const Parcel& p,
              bool express = false,
              bool insured = false) {
    return charge(p.weight, express, insured);
}

int main() {
    Parcel p = {2.5};

    cout << "Courier Charge Calculator\n";

    cout << "charge(2): "
         << charge(2) << endl;

    cout << "charge(2.0f): "
         << charge(2.0f) << endl;

    cout << "charge(2000): "
         << charge(2000) << endl;

    cout << "charge(2.0, true): "
         << charge(2.0, true) << endl;

    cout << "charge(2.0, false, true): "
         << charge(2.0, false, true) << endl;

    cout << "charge(Parcel): "
         << charge(p) << endl;

    return 0;
}
