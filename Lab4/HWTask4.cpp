#include <iostream>
#include <string>

class Book {
private:
    std::string author;
    std::string title;
    double price;
    std::string publisher;
    int stock;
public:
    Book(std::string a, std::string t, double p, std::string pub, int s)
        : author(a), title(t), price(p), publisher(pub), stock(s) {}
    bool isAvailable(std::string t, std::string a) {
        return (title == t && author == a);
    }
    void displayBookDetails() {
        std::cout << "Title: " << title << "\nAuthor: " << author << "\nPrice: " << price << "\nPublisher: " << publisher << "\nStock: " << stock << std::endl;
    }
    void sellBook(int copies) {
        if (copies <= stock) {
            std::cout << "Total Cost: " << copies * price << std::endl;
            stock -= copies;
        } else {
            std::cout << "Required copies not in stock" << std::endl;
        }
    }
};

int main() {
    Book b("J.K. Rowling", "Harry Potter", 39.99, "Bloomsbury", 50);
    std::string title, author;
    int copies;
    std::cout << "Enter title: ";
    std::getline(std::cin, title);
    std::cout << "Enter author: ";
    std::getline(std::cin, author);
    if (b.isAvailable(title, author)) {
        b.displayBookDetails();
        std::cout << "Enter number of copies: ";
        std::cin >> copies;
        b.sellBook(copies);
    } else {
        std::cout << "Book not available" << std::endl;
    }
    return 0;
}
