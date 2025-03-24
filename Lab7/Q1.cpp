#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber, accountHolderName;
    double balance;
public:
    Account(string accNum, string accHolder, double bal) : accountNumber(accNum), accountHolderName(accHolder), balance(bal) {}
    virtual void deposit(double amount) { balance += amount; }
    virtual void withdraw(double amount) { if (balance >= amount) balance -= amount; }
    virtual double calculateInterest() { return 0.0; }
    virtual void printStatement() { cout << "Account: " << accountNumber << " Balance: " << balance << endl; }
};

class SavingsAccount : public Account {
    double interestRate, minimumBalance;
public:
    SavingsAccount(string accNum, string accHolder, double bal, double rate, double minBal) 
        : Account(accNum, accHolder, bal), interestRate(rate), minimumBalance(minBal) {}
    double calculateInterest() override { return balance * interestRate; }
    void withdraw(double amount) override { if (balance - amount >= minimumBalance) balance -= amount; }
};

class FixedDepositAccount : public Account {
    double fixedInterestRate;
    int maturityDate;
public:
    FixedDepositAccount(string accNum, string accHolder, double bal, double rate, int maturity) 
        : Account(accNum, accHolder, bal), fixedInterestRate(rate), maturityDate(maturity) {}
    double calculateInterest() override { return balance * fixedInterestRate; }
};

int main() {
    SavingsAccount sa("12345", "John Doe", 5000, 0.03, 1000);
    sa.deposit(1000);
    sa.withdraw(2000);
    sa.printStatement();
}
