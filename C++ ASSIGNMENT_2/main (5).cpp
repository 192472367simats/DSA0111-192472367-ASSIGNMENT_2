
#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

// Original design: shifting array
class ShiftingHistory {
    string transactions[10];
    int count = 0;

public:
    void add(const string& value) {
        if (count < 10) {
            transactions[count++] = value;
        } else {
            for (int i = 1; i < 10; i++) {
                transactions[i - 1] = transactions[i];
            }

            transactions[9] = value;
        }
    }

    void display() const {
        cout << "\nORIGINAL SHIFTING ARRAY\n";

        for (int i = 0; i < count; i++) {
            cout << transactions[i] << endl;
        }
    }
};

// Redesigned solution: circular buffer
class CircularHistory {
    string transactions[10];
    int count = 0;
    int next = 0;

public:
    void add(const string& value) {
        transactions[next] = value;

        next = (next + 1) % 10;

        if (count < 10) {
            count++;
        }
    }

    void display() const {
        cout << "\nREDESIGNED CIRCULAR BUFFER\n";

        int start = (count == 10) ? next : 0;

        for (int i = 0; i < count; i++) {
            cout << transactions[(start + i) % 10] << endl;
        }
    }
};

int main() {
    ShiftingHistory original;
    CircularHistory redesigned;

    cout << "ADDING 15 TRANSACTIONS\n";

    for (int i = 1; i <= 15; i++) {
        string transaction =
            "Transaction " + to_string(i);

        original.add(transaction);
        redesigned.add(transaction);
    }

    // Display both designs
    original.display();
    redesigned.display();

    // Performance comparison
    const int N = 100000;

    ShiftingHistory test1;
    CircularHistory test2;

    cout << "\nPERFORMANCE COMPARISON\n";

    auto start1 = high_resolution_clock::now();

    for (int i = 1; i <= N; i++) {
        test1.add("Transaction " + to_string(i));
    }

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 1; i <= N; i++) {
        test2.add("Transaction " + to_string(i));
    }

    auto end2 = high_resolution_clock::now();

    auto time1 =
        duration_cast<microseconds>(end1 - start1).count();

    auto time2 =
        duration_cast<microseconds>(end2 - start2).count();

    cout << "Shifting Array Time: "
         << time1 << " microseconds" << endl;

    cout << "Circular Buffer Time: "
         << time2 << " microseconds" << endl;

    return 0;
}
