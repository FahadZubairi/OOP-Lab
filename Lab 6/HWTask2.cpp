#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    double price;
public:
    Vehicle(double p) : price(p) {}
    virtual void displayDetails() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
protected:
    int seatingCapacity;
    int numberOfDoors;
    string fuelType;
public:
    Car(double p, int s, int d, string f) : Vehicle(p), seatingCapacity(s), numberOfDoors(d), fuelType(f) {}
};

class Motorcycle : public Vehicle {
protected:
    int numberOfCylinders;
    int numberOfGears;
    int numberOfWheels;
public:
    Motorcycle(double p, int c, int g, int w) : Vehicle(p), numberOfCylinders(c), numberOfGears(g), numberOfWheels(w) {}
};

class Audi : public Car {
private:
    string modelType;
public:
    Audi(double p, int s, int d, string f, string m) : Car(p, s, d, f), modelType(m) {}
    void displayDetails() override {
        cout << "Audi Details:" << endl;
        cout << "Price: " << price << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Doors: " << numberOfDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Model Type: " << modelType << endl;
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;
public:
    Yamaha(double p, int c, int g, int w, string m) : Motorcycle(p, c, g, w), makeType(m) {}
    void displayDetails() override {
        cout << "Yamaha Details:" << endl;
        cout << "Price: " << price << endl;
        cout << "Number of Cylinders: " << numberOfCylinders << endl;
        cout << "Number of Gears: " << numberOfGears << endl;
        cout << "Number of Wheels: " << numberOfWheels << endl;
        cout << "Make Type: " << makeType << endl;
    }
};

int main() {
    Audi myAudi(50000, 5, 4, "Petrol", "A4");
    Yamaha myYamaha(15000, 2, 6, 2, "YZF-R1");

    myAudi.displayDetails();
    cout << endl;
    myYamaha.displayDetails();
    
    return 0;
}
