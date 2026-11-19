
#include <iostream>
#include <vector>
using namespace std;

int& highestMark(int marks[], int size) {
    int index = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[index])
            index = i;
    }

    return marks[index];
}

// Dangerous: returning a reference to a local variable
int& dangerousFunction() {
    int value = 100;
    return value;
}

int highestMarkCopy(const int marks[], int size) {
    int highest = marks[0];

    for (int i = 1; i < size; i++) {
        if (marks[i] > highest)
            highest = marks[i];
    }

    return highest;
}

const int& highestMarkConstRef(const int marks[], int size) {
    int index = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[index])
            index = i;
    }

    return marks[index];
}

int main() {
    int marks[] = {75, 88, 92, 68, 85};
    int size = 5;

    cout << "Original Marks: ";
    for (int i = 0; i < size; i++)
        cout << marks[i] << " ";

    cout << "\nHighest Mark: " << highestMarkCopy(marks, size);

    highestMark(marks, size) += 2;

    cout << "\nAfter Moderation (+2): ";
    for (int i = 0; i < size; i++)
        cout << marks[i] << " ";

    cout << "\nHighest Mark by Copy: "
         << highestMarkCopy(marks, size);

    cout << "\nHighest Mark by Const Reference: "
         << highestMarkConstRef(marks, size);

    // Vector references may become invalid after reallocation.
    vector<int> studentMarks = {70, 80, 90};
    cout << "\nFirst Vector Mark: " << studentMarks[0];

    studentMarks.push_back(95);
    cout << "\nVector Size: " << studentMarks.size();

    cout << '\n';
    return 0;
}
