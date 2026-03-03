#include <iostream>
using namespace std;

/*
Topic: Encapsulation
- Data members private rakhte hain
- Controlled access getter/setter se hota hai
*/

class BankAccount {
private:
    double balance;

public:
    explicit BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(1000);
    account.deposit(500);

    if (account.withdraw(300)) {
        cout << "Withdraw successful\n";
    } else {
        cout << "Withdraw failed\n";
    }

    cout << "Current Balance: " << account.getBalance() << '\n';
    return 0;
}
