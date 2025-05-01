#include <iostream>
using namespace std;

template<typename T>
class Base {
protected:
    T a, b;
public:
    Base(T x, T y) : a(x), b(y) {}
    void display() {
        cout << "Base: " << a << ", " << b << endl;
    }
};

template<typename T>
class Derived : public Base<T> {
    T c, d;
public:
    Derived(T x, T y) : Base<T>(x, y), c(x), d(y) {}
    void multiply() {
        cout << "Multiplication: " << this->a * this->b * c * d << endl;
    }
};

int main() {
    Derived<int> obj(2, 3);
    obj.display();
    obj.multiply();
}
