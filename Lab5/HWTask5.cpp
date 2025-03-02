#include <iostream>

using namespace std;

class Car {
private:
    int engine_horsepower;
    int seating_capacity;
    int no_of_speakers;

public:

    Car(int hp, int seats, int speakers) : engine_horsepower(hp), seating_capacity(seats), no_of_speakers(speakers) {}

    void display() const {
        cout << "Car Details:\n";
        cout << "Engine Horsepower: " << engine_horsepower << endl;
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Speakers: " << no_of_speakers << endl;
    }
};

int main() {
    Car myCar(300, 5, 6);
    myCar.display();

    return 0;
}
