// Your task is to create a Circle constructor that creates a circle with a radius provided by an argument. The
// circles constructed must have two getters getArea() (PIr^2) and getPerimeter() (2PI*r) which give both
// respective areas and perimeter (circumference).
#include <iostream>
#include <cmath>

class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() { return M_PI * radius * radius; }
    double getPerimeter() { return 2 * M_PI * radius; }
};

int main() {
    Circle c(5.0);
    std::cout << "Area: " << c.getArea() << std::endl;
    std::cout << "Perimeter: " << c.getPerimeter() << std::endl;
    return 0;
}
