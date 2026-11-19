
#include <iostream>
using namespace std;

class SavingsAccount {
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int count;
    int nextIndex;

public:
    SavingsAccount(int accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
        count = 0;
        nextIndex = 0;
    }

    void addTransaction(double amount) {
        transactions[nextIndex] = amount;

        nextIndex = (nextIndex + 1) % 10;

        if (count < 10)
            count++;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            addTransaction(amount);
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            addTransaction(-amount);
        } else {
            cout << "Invalid withdrawal\n";
        }
    }

    void miniStatement() const {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Latest " << count << " Transactions:\n";

        int start = (count == 10) ? nextIndex : 0;

        for (int i = 0; i < count; i++) {
            int index = (start + i) % 10;

            if (transactions[index] > 0)
                cout << "Deposit: " << transactions[index] << endl;
            else
                cout << "Withdrawal: " << -transactions[index] << endl;
        }
    }
};

int main() {
    SavingsAccount account(1001, 10000);

    account.deposit(500);
    account.withdraw(200);
    account.deposit(1000);
    account.withdraw(300);
    account.deposit(700);
    account.withdraw(400);
    account.deposit(800);
    account.withdraw(100);
    account.deposit(600);
    account.withdraw(250);
    account.deposit(1500);
    account.withdraw(500);
    account.deposit(900);

    account.miniStatement();

    return 0;
}
