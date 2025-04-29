#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Employee {
public:
    int id;
    string name;
    string designation;
    int years;

    Employee(int i, string n, string d, int y) : id(i), name(n), designation(d), years(y) {}

    string toString() {
        return to_string(id) + "," + name + "," + designation + "," + to_string(years);
    }

    static Employee fromString(string line) {
        stringstream ss(line);
        string part;
        vector<string> parts;
        while (getline(ss, part, ',')) {
            parts.push_back(part);
        }
        return Employee(stoi(parts[0]), parts[1], parts[2], stoi(parts[3]));
    }
};

void writeEmployees(vector<Employee> emps, string filename) {
    ofstream file(filename);
    for (auto& emp : emps) {
        file << emp.toString() << endl;
    }
    file.close();
}

vector<Employee> readEmployees(string filename) {
    ifstream file(filename);
    vector<Employee> emps;
    string line;
    while (getline(file, line)) {
        emps.push_back(Employee::fromString(line));
    }
    file.close();
    return emps;
}

int main() {
    vector<Employee> employees = {
        Employee(1, "Ali", "manager", 3),
        Employee(2, "Sara", "developer", 1),
        Employee(3, "Ahmed", "manager", 2),
        Employee(4, "Ayesha", "tester", 5)
    };

    writeEmployees(employees, "employees.txt");

    vector<Employee> all = readEmployees("employees.txt");

    vector<Employee> queryResult;
    for (auto& emp : all) {
        if (emp.designation == "manager" && emp.years >= 2) {
            queryResult.push_back(emp);
        }
    }

    writeEmployees(queryResult, "query_result.txt");

    vector<Employee> incremented;
    int newId = 1;
    for (auto& emp : queryResult) {
        emp.id = newId++;
        incremented.push_back(emp);
    }

    writeEmployees(incremented, "final_result.txt");

    return 0;
}
