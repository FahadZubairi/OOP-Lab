#include <iostream>
#include <vector>

using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative;

public:
    BigInteger(string num) {
        isNegative = num[0] == '-';
        for (int i = num.size() - 1; i >= (isNegative ? 1 : 0); i--) {
            digits.push_back(num[i] - '0');
        }
    }

    BigInteger operator+(const BigInteger &other) const {
        vector<int> result;
        int carry = 0;
        size_t maxSize = max(digits.size(), other.digits.size());

        for (size_t i = 0; i < maxSize || carry; i++) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];

            result.push_back(sum % 10);
            carry = sum / 10;
        }

        return BigInteger(result);
    }

    friend ostream &operator<<(ostream &os, const BigInteger &b) {
        if (b.isNegative) os << "-";
        for (int i = b.digits.size() - 1; i >= 0; i--) os << b.digits[i];
        return os;
    }
};
int main() {
    BigInteger num1("999999999999");
    BigInteger num2("1");

    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    cout << "Sum: " << (num1 + num2) << endl;

    return 0;
}
