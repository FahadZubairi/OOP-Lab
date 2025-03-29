#include <iostream>

using namespace std;

class Shape {
private:
    int area;

public:
    Shape(int a) : area(a) {}

    Shape operator+(const Shape &other) {
        return Shape(area + other.area);
    }

    void display() {
        cout << "Total Area: " << area << endl;
    }
};
int main() {
    Shape shape1(20);
    Shape shape2(30);

    Shape total = shape1 + shape2;
    total.display();

    return 0;
}
