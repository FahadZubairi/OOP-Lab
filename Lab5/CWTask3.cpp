#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Book {
public:
    string title;
    string isbn;
    Book(string t, string i) : title(t), isbn(i) {}
};

class Catalog {
private:
    unordered_map<string, Book*> books;
public:
    void addBook(Book* book) {
        books[book->isbn] = book;
    }
    void removeBook(string isbn) {
        books.erase(isbn);
    }
    Book* findBook(string isbn) {
        return books.count(isbn) ? books[isbn] : nullptr;
    }
};

class Library {
private:
    Catalog catalog;
    vector<shared_ptr<Book>> books;
public:
    void addBook(shared_ptr<Book> book) {
        books.push_back(book);
        catalog.addBook(book.get());
    }
    void removeBook(string isbn) {
        books.erase(remove_if(books.begin(), books.end(), [&](shared_ptr<Book> b) { return b->isbn == isbn; }), books.end());
        catalog.removeBook(isbn);
    }
    Book* findBookInCatalog(string isbn) {
        return catalog.findBook(isbn);
    }
};

int main() {
    Library library;
    auto book1 = make_shared<Book>("C++ Programming", "12345");
    auto book2 = make_shared<Book>("Data Structures", "67890");
    
    library.addBook(book1);
    library.addBook(book2);
    
    Book* found = library.findBookInCatalog("12345");
    if (found) cout << "Found Book: " << found->title << endl;
    else cout << "Book not found" << endl;
    
    return 0;
}
