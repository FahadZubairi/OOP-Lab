#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    double price;
public:
    virtual void setPrice(double p) = 0;
    string getModel() { return model; }
    double getPrice() { return price; }
};

class Color : public Car {
    string color;
public:
    Color(string m, string c) { model = m; color = c; }
    void setPrice(double p) {
        price = p + 500;
    }
};

class Company : public Car {
    string companyName;
public:
    Company(string m, string c) { model = m; companyName = c; }
    void setPrice(double p) {
        price = p + 1000;
    }
};

int main() {
    Color car1("ModelX", "Red");
    Company car2("ModelS", "Tesla");

    car1.setPrice(20000);
    car2.setPrice(30000);

    cout << "Car1 Model: " << car1.getModel() << ", Price: $" << car1.getPrice() << endl;
    cout << "Car2 Model: " << car2.getModel() << ", Price: $" << car2.getPrice() << endl;

    return 0;
}
