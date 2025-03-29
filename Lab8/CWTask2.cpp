#include <iostream>
#include <vector>

using namespace std;

class Polynomial;

class PolynomialUtils {
public:
    static int evaluate(const Polynomial &p, int x);
    static Polynomial derivative(const Polynomial &p);
};

class Polynomial {
private:
    vector<int> coefficients;

public:
    Polynomial() {}

    Polynomial(vector<int> coeffs) : coefficients(coeffs) {}

    Polynomial operator+(const Polynomial &other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); i++) result[i] += coefficients[i];
        for (size_t i = 0; i < other.coefficients.size(); i++) result[i] += other.coefficients[i];
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial &other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); i++) result[i] += coefficients[i];
        for (size_t i = 0; i < other.coefficients.size(); i++) result[i] -= other.coefficients[i];
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial &other) const {
        vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);
        for (size_t i = 0; i < coefficients.size(); i++)
            for (size_t j = 0; j < other.coefficients.size(); j++)
                result[i + j] += coefficients[i] * other.coefficients[j];
        return Polynomial(result);
    }

    friend ostream &operator<<(ostream &os, const Polynomial &p) {
        for (int i = p.coefficients.size() - 1; i >= 0; i--) {
            if (p.coefficients[i] != 0) {
                os << (p.coefficients[i] > 0 && i != p.coefficients.size() - 1 ? " + " : "") << p.coefficients[i] << "x^" << i;
            }
        }
        return os;
    }

    friend class PolynomialUtils;
};

int PolynomialUtils::evaluate(const Polynomial &p, int x) {
    int result = 0;
    int power = 1;
    for (int coeff : p.coefficients) {
        result += coeff * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial &p) {
    vector<int> deriv(p.coefficients.size() - 1, 0);
    for (size_t i = 1; i < p.coefficients.size(); i++) {
        deriv[i - 1] = p.coefficients[i] * i;
    }
    return Polynomial(deriv);
}
int main() {
    Polynomial p1({2, 3, 1});  
    Polynomial p2({1, -1, 0, 2});  

    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;
    cout << "Sum: " << (p1 + p2) << endl;
    cout << "Difference: " << (p1 - p2) << endl;
    cout << "Product: " << (p1 * p2) << endl;

    cout << "Evaluation at x=2: " << PolynomialUtils::evaluate(p1, 2) << endl;
    cout << "Derivative of P1: " << PolynomialUtils::derivative(p1) << endl;

    return 0;
}
