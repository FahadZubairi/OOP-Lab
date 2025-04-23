#include <iostream>
#include <string>
using namespace std;

class Wallet {
    double balance;
    double dailyDepositLimit;
    double dailyWithdrawLimit;
    double depositedToday;
    double withdrawnToday;

public:
    Wallet(double depositLimit = 5000, double withdrawLimit = 3000) {
        balance = 0;
        dailyDepositLimit = depositLimit;
        dailyWithdrawLimit = withdrawLimit;
        depositedToday = 0;
        withdrawnToday = 0;
    }

    bool deposit(double amount) {
        if (amount > 0 && (depositedToday + amount) <= dailyDepositLimit) {
            balance += amount;
            depositedToday += amount;
            return true;
        }
        return false;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance && (withdrawnToday + amount) <= dailyWithdrawLimit) {
            balance -= amount;
            withdrawnToday += amount;
            return true;
        }
        return false;
    }

    double getBalance() {
        return balance;
    }
};

class User {
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string n) : userID(id), name(n) {}

    bool deposit(double amount) {
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        return wallet.withdraw(amount);
    }

    void showBalance() {
        cout << name << " has balance: $" << wallet.getBalance() << endl;
    }
};

int main() {
    User u1("U101", "Alice");
    User u2("U102", "Bob");

    u1.deposit(2000);
    u1.withdraw(500);
    u1.showBalance();

    u2.deposit(6000);
    u2.withdraw(1000);
    u2.showBalance();

    return 0;
}
