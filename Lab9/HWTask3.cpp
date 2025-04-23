#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    double salary;
public:
    virtual void getdata() {
        cin >> name >> salary;
    }
    virtual void displaydata() {
        cout << name << " " << salary << endl;
    }
    virtual double bonus() {
        return salary * 0.1;
    }
};

class Admin : virtual public Person {
public:
    void getdata() {
        cin >> name >> salary;
    }
    void displaydata() {
        cout << "Admin: " << name << ", Salary: " << salary << endl;
    }
    double bonus() {
        return salary * 0.15;
    }
};

class Account : virtual public Person {
public:
    void getdata() {
        cin >> name >> salary;
    }
    void displaydata() {
        cout << "Account: " << name << ", Salary: " << salary << endl;
    }
    double bonus() {
        return salary * 0.2;
    }
};

class Master : public Admin, public Account {
public:
    void getdata() {
        cin >> name >> salary;
    }
    void displaydata() {
        cout << "Master: " << name << ", Salary: " << salary << endl;
    }
    double bonus() {
        return salary * 0.25;
    }
};

int main() {
    Person* p;
    Master m;
    p = &m;
    p->getdata();
    p->displaydata();
    cout << "Bonus: " << p->bonus() << endl;
    return 0;
}
