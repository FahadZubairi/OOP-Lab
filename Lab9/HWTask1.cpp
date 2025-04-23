#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() {
        return width * height;
    }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double getArea() {
        return 0.5 * base * height;
    }
};

int main() {
    Shape* r = new Rectangle(4, 5);
    Shape* t = new Triangle(4, 5);
    cout << "Rectangle Area: " << r->getArea() << endl;
    cout << "Triangle Area: " << t->getArea() << endl;
    delete r;
    delete t;
    return 0;
}
