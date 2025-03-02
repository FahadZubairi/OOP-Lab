#include <iostream>
#include <vector>
#include <map>

using namespace std;

class CoffeeShop {
private:
    string name;
    vector<string> orders;
    map<string, double> menu;

public:
    CoffeeShop(string shopName, map<string, double> menuItems) : name(shopName), menu(menuItems) {}

    string addOrder(string item) {
        if (menu.find(item) != menu.end()) {
            orders.push_back(item);
            return "Order added: " + item;
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0.0;
        for (const string& item : orders) {
            total += menu[item];
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "Menu is empty!";
        string cheapest = menu.begin()->first;
        double minPrice = menu.begin()->second;
        for (const auto& pair : menu) {
            if (pair.second < minPrice) {
                minPrice = pair.second;
                cheapest = pair.first;
            }
        }
        return cheapest;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& pair : menu) {
            if (pair.first.find("Drink") != string::npos) {
                drinks.push_back(pair.first);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (const auto& pair : menu) {
            if (pair.first.find("Drink") == string::npos) {
                foods.push_back(pair.first);
            }
        }
        return foods;
    }
};

int main() {
    
    map<string, double> menu = {
        {"Coffee", 2.5}, {"Tea", 1.8}, {"Sandwich", 4.0},
        {"Muffin", 3.2}, {"Orange Juice Drink", 3.0}
    };

    CoffeeShop myShop("StarBeans", menu);

    cout << myShop.addOrder("Coffee") << endl;
    cout << myShop.addOrder("Muffin") << endl;
    cout << myShop.addOrder("Pasta") << endl; 

    cout << myShop.fulfillOrder() << endl;

    vector<string> orders = myShop.listOrders();
    cout << "Current Orders: ";
    for (const string& order : orders) cout << order << " ";
    cout << endl;

    cout << "Total Due: $" << myShop.dueAmount() << endl;

    cout << "Cheapest Item: " << myShop.cheapestItem() << endl;

    vector<string> drinks = myShop.drinksOnly();
    cout << "Drinks Only: ";
    for (const string& drink : drinks) cout << drink << " ";
    cout << endl;

    vector<string> foods = myShop.foodOnly();
    cout << "Food Only: ";
    for (const string& food : foods) cout << food << " ";
    cout << endl;

    return 0;
}
