#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int i, string n) : id(i), name(n) {}
    virtual void displayRole() = 0;
    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill() = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int i, string n) : Employee(i, n) {}
    void takeOrder() override { cout << name << " is taking an order." << endl; }
    void displayRole() override { cout << name << " is a Waiter." << endl; }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int i, string n) : Employee(i, n) {}
    void prepareOrder() override { cout << name << " is preparing an order." << endl; }
    void displayRole() override { cout << name << " is a Chef." << endl; }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int i, string n) : Employee(i, n) {}
    void generateBill() override { cout << name << " is generating a bill." << endl; }
    void displayRole() override { cout << name << " is a Cashier." << endl; }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int i, string n) : Employee(i, n) {}
    void takeOrder() override { cout << name << " is taking an order as a Manager." << endl; }
    void generateBill() override { cout << name << " is generating a bill as a Manager." << endl; }
    void displayRole() override { cout << name << " is a Manager." << endl; }
};

class Menu {
protected:
    string name;
public:
    Menu(string n) : name(n) {}
    virtual double calculateTotal() = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
public:
    FoodMenu(string n) : Menu(n) {}
    double calculateTotal() override { return 50.0; }
};

class BeverageMenu : public Menu {
public:
    BeverageMenu(string n) : Menu(n) {}
    double calculateTotal() override { return 30.0 * 1.1; }
};

int main() {
    vector<Employee*> employees;
    employees.push_back(new Waiter(1, "John"));
    employees.push_back(new Chef(2, "Alice"));
    employees.push_back(new Cashier(3, "Bob"));
    employees.push_back(new Manager(4, "Sarah"));

    for (Employee* emp : employees) {
        emp->displayRole();
    }
    
    for (Employee* emp : employees) {
        delete emp;
    }
    
    return 0;
}
