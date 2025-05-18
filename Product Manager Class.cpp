#include<iostream>
#include<string>
#include<fstream>
#include <type_traits>
using namespace std;

// Base Template Class

template <class T>
class Product{
protected:
    int ID;
    double Price;
    T stock;
public:
    Product(int i, double p, T s) : ID(i), Price(p), stock(s) {}
    virtual void display() const = 0;
    virtual T getStock() const = 0;
    virtual double CalculateDiscount() const = 0;
    int getID() const { return ID; }
    virtual void Savetofile(ofstream& out) const {
        out << ID << endl;
        out << Price << endl;
        out << stock << endl;
    }
    virtual ~Product() {}
};

// Electronics

template <typename T>
class Electronics : public Product<T> {
    int warrantyinmonths;
public:
    Electronics(int w, int i, double p, T s) : Product<T>(i, p, s), warrantyinmonths(w) {}
    void display() const override {
        cout << "Electronics Product | Warranty: " << warrantyinmonths
             << " | ID: " << this->ID << " | Price: " << this->Price
             << " | Stock: " << this->stock << endl;
    }
    T getStock() const override {
        return this->stock;
    }
    double CalculateDiscount() const override {
        return this->Price * 0.1;
    }
    void Savetofile(ofstream& out) const override {
        out << "Electronics" << endl;
        Product<T>::Savetofile(out);
        out << warrantyinmonths << endl;
    }
};

// Books

template <class T>
class Book : public Product<T> {
    string author;
    int no_of_pages;
public:
    Book(string a, int n, int i, double p, T s) : Product<T>(i, p, s), author(a), no_of_pages(n) {}
    void display() const override {
        cout << "Book | Author: " << author << " | Pages: " << no_of_pages
             << " | ID: " << this->ID << " | Price: " << this->Price
             << " | Stock: " << this->stock << endl;
    }
    T getStock() const override {
        return this->stock;
    }
    double CalculateDiscount() const override {
        return this->Price * 0.2;
    }
    void Savetofile(ofstream& out) const override {
        out << "Book" << endl;
        Product<T>::Savetofile(out);
        out << author << endl;
        out << no_of_pages << endl;
    }
};

// Grocery

template <class T>
class Grocery : public Product<T> {
    string expiry;
    double weight;
public:
    Grocery(string e, double w, int i, double p, T s) : Product<T>(i, p, s), expiry(e), weight(w) {}
    void display() const override {
        cout << "Grocery | Expiry: " << expiry << " | Weight: " << weight
             << " | ID: " << this->ID << " | Price: " << this->Price
             << " | Stock: " << this->stock << endl;
    }
    T getStock() const override {
        return this->stock;
    }
    double CalculateDiscount() const override {
        return this->Price * 0.15;
    }
    void Savetofile(ofstream& out) const override {
        out << "Grocery" << endl;
        Product<T>::Savetofile(out);
        out << expiry << endl;
        out << weight << endl;
    }
};

// User

template<class T>
class User{
    T user_role;
public:
    User(T u) : user_role(u) {}
    T getRole() const {
        return user_role;
    }
};

template<typename T>
bool Haspermission(const User<T>& user1, const string& action){
    if(user1.getRole() == "admin") return true;
    else if(user1.getRole() == "manager" && action != "delete") return true;
    return false;
}

// Product Manager

template<typename T>
class ProductManager {
    Product<T>** products;
    int capacity;
    int count;

    void resize() {
        capacity *= 2;
        Product<T>** newArray = new Product<T>*[capacity];
        for (int i = 0; i < count; i++) {
            newArray[i] = products[i];
        }
        delete[] products;
        products = newArray;
    }

public:
    ProductManager(int initialsize = 10) : capacity(initialsize), count(0) {
        products = new Product<T>*[capacity];
    }

    void AddProduct(Product<T>* prod) {
        if (count == capacity) resize();
        products[count++] = prod;
    }

    void DisplayAll() const {
        for (int i = 0; i < count; i++) {
            products[i]->display();
        }
    }

    double AverageStock() const {
    if constexpr (std::is_arithmetic<T>::value) {
        if (count == 0) return 0;
        T total = T();
        for (int i = 0; i < count; i++) {
            if (products[i]) {
                total += products[i]->getStock();
            }
        }
        return static_cast<double>(total) / count;
    } else {
        throw std::runtime_error("AverageStock can only be calculated for numeric stock types.");
    }
}

    void deleteproduct(int id, const User<T>& user) {
        if (!Haspermission(user, "delete")) {
            cout << "User does not have permission to delete" << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            if (products[i]->getID() == id) {
                delete products[i];
                for (int j = i; j < count - 1; ++j) {
                    products[j] = products[j + 1];
                }
                --count;
                cout << "Product deleted" << endl;
                return;
            }
        }
    }

    void Savetofile(const string& filename) const {
        ofstream file(filename, ios::app);
        if (!file) throw runtime_error("Failed to open file");
        for (int i = 0; i < count; i++) {
            products[i]->Savetofile(file);
        }
        file.close();
    }

    ~ProductManager() {
        for (int i = 0; i < count; i++) {
            delete products[i];
        }
        delete[] products;
    }
};

// Main function

int main() {
    try {
        ProductManager<string> manager;
        manager.AddProduct(new Electronics<string>(24, 1001, 999.99, "20"));
        manager.AddProduct(new Grocery<string>("2025-12-01", 5.5, 1002, 25.75, "50"));
        manager.AddProduct(new Book<string>("John Doe", 350, 1003, 499.50, "15"));

        cout << "\n--- Displaying All Products ---\n";
        manager.DisplayAll();

        cout << "\n--- Average Stock: " << manager.AverageStock() << " ---\n";

        manager.Savetofile("products.txt");
        cout << "\nProducts saved to file.\n";

        User<string> user1("viewer");
        manager.deleteproduct(1003,user1);

        User<string> admin("admin");
        manager.deleteproduct(1001, admin);

        cout << "\n--- After Deletion ---\n";
        manager.DisplayAll();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
