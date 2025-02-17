#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;
    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;
public:
    CoffeeShop(string n, vector<MenuItem> m) : name(n), menu(m) {}
    string addOrder(string itemName) {
        for (auto &item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added";
            }
        }
        return "This item is currently unavailable";
    }
    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }
    vector<string> listOrders() {
        return orders;
    }
    double dueAmount() {
        double total = 0;
        for (auto &order : orders) {
            for (auto &item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }
    string cheapestItem() {
        if (menu.empty()) return "";
        MenuItem cheapest = menu[0];
        for (auto &item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
    }
    vector<string> drinksOnly() {
        vector<string> drinks;
        for (auto &item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }
    vector<string> foodOnly() {
        vector<string> food;
        for (auto &item : menu) {
            if (item.type == "food") {
                food.push_back(item.name);
            }
        }
        return food;
    }
};

int main() {
    vector<MenuItem> menu = { {"Coffee", "drink", 2.5}, {"Sandwich", "food", 5.0}, {"Tea", "drink", 2.0} };
    CoffeeShop shop("Cafe Bliss", menu);
    cout << shop.addOrder("Coffee") << endl;
    cout << shop.fulfillOrder() << endl;
    cout << "Total Due: " << shop.dueAmount() << endl;
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;
    return 0;
}