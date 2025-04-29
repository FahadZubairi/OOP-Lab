#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class User {
public:
    string id;
    string firstName;
    string lastName;
    string address;
    string email;

    string toString() {
        return id + "," + firstName + "," + lastName + "," + address + "," + email;
    }

    static User fromString(string line) {
        stringstream ss(line);
        vector<string> parts;
        string part;
        while (getline(ss, part, ',')) {
            parts.push_back(part);
        }
        User u;
        u.id = parts[0];
        u.firstName = parts[1];
        u.lastName = parts[2];
        u.address = parts[3];
        u.email = parts[4];
        return u;
    }
};

class Product {
public:
    string id;
    string name;
    string description;
    int price;

    string toString() {
        return id + "," + name + "," + description + "," + to_string(price);
    }

    static Product fromString(string line) {
        stringstream ss(line);
        vector<string> parts;
        string part;
        while (getline(ss, part, ',')) {
            parts.push_back(part);
        }
        Product p;
        p.id = parts[0];
        p.name = parts[1];
        p.description = parts[2];
        p.price = stoi(parts[3]);
        return p;
    }
};

class Order {
public:
    string id;
    string userId;
    string productId;
    int totalPaid;

    string toString() {
        return id + "," + userId + "," + productId + "," + to_string(totalPaid);
    }

    static Order fromString(string line) {
        stringstream ss(line);
        vector<string> parts;
        string part;
        while (getline(ss, part, ',')) {
            parts.push_back(part);
        }
        Order o;
        o.id = parts[0];
        o.userId = parts[1];
        o.productId = parts[2];
        o.totalPaid = stoi(parts[3]);
        return o;
    }
};

template <typename T>
vector<T> readFile(string filename, T (*parser)(string)) {
    ifstream file(filename);
    vector<T> data;
    string line;
    while (getline(file, line)) {
        data.push_back(parser(line));
    }
    file.close();
    return data;
}

int main() {
    vector<User> users = {
        {"1", "Linus", "Torvalds", "Helsinki", "linus@example.com"},
        {"2", "Ada", "Lovelace", "London", "ada@example.com"}
    };

    vector<Product> products = {
        {"p1", "Laptop", "High-end machine", 2000},
        {"p2", "Keyboard", "Mechanical", 100},
        {"p3", "Mouse", "Wireless", 50}
    };

    vector<Order> orders = {
        {"o1", "1", "p1", 2000},
        {"o2", "2", "p2", 100},
        {"o3", "1", "p3", 50}
    };

    ofstream ufile("users.txt");
    for (auto& u : users) ufile << u.toString() << endl;
    ufile.close();

    ofstream pfile("products.txt");
    for (auto& p : products) pfile << p.toString() << endl;
    pfile.close();

    ofstream ofile("orders.txt");
    for (auto& o : orders) ofile << o.toString() << endl;
    ofile.close();

    vector<User> udata = readFile("users.txt", User::fromString);
    vector<Product> pdata = readFile("products.txt", Product::fromString);
    vector<Order> odata = readFile("orders.txt", Order::fromString);

    string linusId;
    for (auto& u : udata) {
        if (u.firstName == "Linus") {
            linusId = u.id;
            break;
        }
    }

    vector<string> productIds;
    for (auto& o : odata) {
        if (o.userId == linusId) {
            productIds.push_back(o.productId);
        }
    }

    for (auto& p : pdata) {
        for (auto& pid : productIds) {
            if (p.id == pid) {
                cout << p.name << endl;
            }
        }
    }

    return 0;
}
