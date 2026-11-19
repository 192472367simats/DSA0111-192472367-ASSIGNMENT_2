
#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    int accountNumber;
    double balance;
    string transactions[10];
    int count;

    void addTransaction(const string& details) {
        if (count < 10) {
            transactions[count] = details;
            count++;
        } else {
            for (int i = 1; i < 10; i++) {
                transactions[i - 1] = transactions[i];
            }

            transactions[9] = details;
        }
    }

public:
    SavingsAccount(int accNo, double initialBalance)
        : accountNumber(accNo),
          balance(initialBalance),
          count(0) {}

    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement() const;
};

void SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        addTransaction("Deposit: Rs. " + to_string(amount));
    }
}

void SavingsAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        addTransaction("Withdrawal: Rs. " + to_string(amount));
    }
}

void SavingsAccount::miniStatement() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: Rs. " << balance << endl;
    cout << "\nLast 10 Transactions:\n";

    for (int i = 0; i < count; i++) {
        cout << transactions[i] << endl;
    }
}

int main() {
    SavingsAccount account(12345, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(200);
    account.withdraw(300);
    account.deposit(700);
    account.withdraw(100);
    account.deposit(400);
    account.withdraw(250);
    account.deposit(800);
    account.withdraw(150);
    account.deposit(600);

    account.miniStatement();

    return 0;
}
