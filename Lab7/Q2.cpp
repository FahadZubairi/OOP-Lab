#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() override { cout << "Drawing Circle" << endl; }
    double calculateArea() override { return 3.14 * radius * radius; }
    double calculatePerimeter() override { return 2 * 3.14 * radius; }
};

int main() {
    Circle c(5);
    c.draw();
    cout << "Area: " << c.calculateArea() << endl;
}
