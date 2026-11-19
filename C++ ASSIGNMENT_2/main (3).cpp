
#include <iostream>
#include <string>
using namespace std;

// Predict-output Token class
class Token {
    static int next;
    int id;

public:
    Token() {
        id = ++next;
    }

    int get() const {
        return id;
    }

    static int issued() {
        return next - 100;
    }
};

int Token::next = 100;

// BusTicket class
class BusTicket {
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    string name;

public:
    explicit BusTicket(const string& n)
        : seat(0), name(n) {
        if (issued < CAPACITY) {
            issued++;
            seat = issued;
        }
    }

    static int count() {
        return issued;
    }

    void print() const {
        cout << name << ": "
             << (seat ? "Seat " + to_string(seat)
                      : string("Waiting"))
             << endl;
    }
};

int BusTicket::issued = 0;

// Function called twice
void createTickets() {
    BusTicket trip[2] = {
        BusTicket("Student A"),
        BusTicket("Student B")
    };

    for (const BusTicket& t : trip) {
        t.print();
    }

    cout << "Total issued: "
         << BusTicket::count() << endl;
}

int main() {
    cout << "PREDICT THE OUTPUT\n";

    Token counter[3];
    Token extra;

    cout << counter[0].get() << ' '
         << counter[2].get() << ' '
         << extra.get() << ' '
         << Token::issued() << endl;

    cout << "\nBUS TICKET SYSTEM\n";

    BusTicket trip[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (const BusTicket& t : trip) {
        t.print();
    }

    cout << "Issued: " << BusTicket::count() << endl;

    cout << "\nFUNCTION CALLED TWICE\n";

    createTickets();
    createTickets();

    return 0;
}
