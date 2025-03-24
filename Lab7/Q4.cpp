#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name, id;
public:
    Person(string n, string i) : name(n), id(i) {}
    virtual void displayInfo() { cout << "Name: " << name << " ID: " << id << endl; }
};

class Student : public Person {
    double GPA;
public:
    Student(string n, string i, double g) : Person(n, i), GPA(g) {}
    void displayInfo() override { cout << "Student: " << name << " GPA: " << GPA << endl; }
};

int main() {
    Student s("Alice", "S123", 3.9);
    s.displayInfo();
}
