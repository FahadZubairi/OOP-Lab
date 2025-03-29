#include <iostream>
#include <algorithm>

using namespace std;

class Fraction {
private:
    int numerator, denominator;

    void reduce() {
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {
        reduce();
    }

    Fraction operator+(const Fraction &other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator-(const Fraction &other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator*(const Fraction &other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction &other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Fraction &other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction &other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction &other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction &other) const {
        return other < *this;
    }

    bool operator<=(const Fraction &other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction &other) const {
        return !(*this < other);
    }

    friend ostream &operator<<(ostream &os, const Fraction &f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream &operator>>(istream &is, Fraction &f) {
        is >> f.numerator >> f.denominator;
        f.reduce();
        return is;
    }
};
int main() {
    Fraction f1(2, 4), f2(3, 6);

    cout << "Sum: " << (f1 + f2) << endl;
    cout << "Difference: " << (f1 - f2) << endl;
    cout << "Product: " << (f1 * f2) << endl;
    cout << "Quotient: " << (f1 / f2) << endl;

    cout << "Enter a fraction (numerator denominator): ";
    Fraction f3(0, 1);
    cin >> f3;
    cout << "You entered: " << f3 << endl;

    return 0;
}
