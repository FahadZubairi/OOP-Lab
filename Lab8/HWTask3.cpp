#include <iostream>

using namespace std;

class Person {
protected:
    int empID;

public:
    void getData() {
        cin >> empID;
    }

    void displayData() {
        cout << "Employee ID: " << empID << endl;
    }
};

class Admin : public Person {
protected:
    string name;
    float income;

public:
    void getData() {
        Person::getData();
        cin >> name >> income;
    }

    void displayData() {
        Person::displayData();
        cout << "Name: " << name << "\nIncome: " << income << "\nBonus: " << income * 0.05 << endl;
    }
};
int main() {
    Admin emp;
    cout << "Enter Employee ID, Name, and Monthly Income: ";
    emp.getData();
    emp.displayData();

    return 0;
}
