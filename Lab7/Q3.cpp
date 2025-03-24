#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
public:
    Currency(double amt) : amount(amt) {}
    virtual double convertToBase() { return amount; }
    virtual void displayCurrency() { cout << "Amount: " << amount << endl; }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt) {}
    double convertToBase() override { return amount * 1.0; }
    void displayCurrency() override { cout << "$" << amount << endl; }
};

int main() {
    Dollar d(100);
    d.displayCurrency();
}
