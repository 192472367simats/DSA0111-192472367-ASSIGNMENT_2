
#include <iostream>
#include <vector>
using namespace std;

int& highestMark(int marks[], int size) {
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[maxIndex]) {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

// Return highest mark as a const reference
const int& highestMarkConst(const int marks[], int size) {
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[maxIndex]) {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

// Return highest mark as an index
int highestIndex(const int marks[], int size) {
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[maxIndex]) {
            maxIndex = i;
        }
    }

    return maxIndex;
}

// Return highest mark as a pointer
int* highestPointer(int marks[], int size) {
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[maxIndex]) {
            maxIndex = i;
        }
    }

    return &marks[maxIndex];
}

// Deliberately unsafe: do not call this function
int& dangerousFunction() {
    int value = 50;
    return value;
}

int main() {
    int marks[] = {75, 88, 92, 81, 90};
    int size = 5;

    cout << "RETURN BY REFERENCE\n";
    cout << "Highest mark: " << highestMark(marks, size) << endl;

    highestMark(marks, size) += 2;

    cout << "After moderation: " << highestMark(marks, size) << endl;

    cout << "\nRETURN BY CONST REFERENCE\n";
    cout << "Highest mark: " << highestMarkConst(marks, size) << endl;

    cout << "\nRETURN BY INDEX\n";
    int index = highestIndex(marks, size);
    cout << "Highest index: " << index << endl;
    cout << "Highest mark: " << marks[index] << endl;

    cout << "\nRETURN BY POINTER\n";
    int* ptr = highestPointer(marks, size);
    cout << "Highest mark: " << *ptr << endl;

    cout << "\nVECTOR TEST\n";
    vector<int> registerMarks = {75, 88, 92, 81, 90};

    int savedIndex = highestIndex(registerMarks.data(),
                                  registerMarks.size());

    cout << "Highest mark before growth: "
         << registerMarks[savedIndex] << endl;

    registerMarks.push_back(95);

    // Recalculate the index after vector growth
    savedIndex = highestIndex(registerMarks.data(),
                              registerMarks.size());

    cout << "Highest mark after growth: "
         << registerMarks[savedIndex] << endl;

    cout << "\nUnsafe local-reference function is not called.\n";

    return 0;
}
