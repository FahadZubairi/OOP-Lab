#include <iostream>
using namespace std;

class Wallet
{
    double balance;

public:
    Wallet(double b)
    {
        if (b >= 0)
            balance = b;
        else
            cerr << "Balance cannot be negative\n";
    }
    
};
int main() {}
