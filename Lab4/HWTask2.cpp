#include <iostream>
using namespace std;
class Account {
private:
    double balance;
public:
    Account(double initialBalance) : balance(initialBalance) {}
    void credit(double amount) { balance += amount; }
    void debit(double amount) { if (amount <= balance) balance -= amount; }
    double getBalance() { return balance; }
};

int main() {
    Account acc(1000.0);
    acc.credit(500.0);
    acc.debit(200.0);
    std::cout << "Balance: " << acc.getBalance() << std::endl;
    return 0;
}
