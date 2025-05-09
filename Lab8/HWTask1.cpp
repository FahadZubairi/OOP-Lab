#include <iostream>

using namespace std;

class Number {
private:
    int value;

public:
    Number(int v) : value(v) {}

    Number operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() {
        cout << value << endl;
    }
};
int main() {
    Number n(8);
    --n;
    cout << "Prefix --: "; 
    n.display();

    n--;
    cout << "Postfix --: "; 
    n.display();

    return 0;
}
