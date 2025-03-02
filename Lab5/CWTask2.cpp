#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car {
    string name;
    int id;
public:
    Car(string n, int i) : name(n), id(i) {}
    string getName() { return name; }
    int getId() { return id; }
};

class Garage {
    vector<Car*> cars;
public:
    void parkCar(Car* car) { cars.push_back(car); }
    void listCars() {
        for (Car* car : cars)
            cout << "Car ID: " << car->getId() << ", Name: " << car->getName() << endl;
    }
};

int main() {
    Car car1("Toyota", 1);
    Car car2("Honda", 2);
    Car car3("Ford", 3);
    
    Garage garage;
    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);
    
    garage.listCars();
    
    return 0;
}
