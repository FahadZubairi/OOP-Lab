#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
public:
    Media(string t) : title(t) {}
    virtual void displayInfo() { cout << "Title: " << title << endl; }
};

class Book : public Media {
    string author;
public:
    Book(string t, string a) : Media(t), author(a) {}
    void displayInfo() override { cout << "Book: " << title << " Author: " << author << endl; }
};

int main() {
    Book b("C++ Programming", "Bjarne Stroustrup");
    b.displayInfo();
}
