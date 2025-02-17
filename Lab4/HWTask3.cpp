#include <iostream>
#include <string>

class Invoice {
private:
    std::string partNumber;
    std::string partDescription;
    int quantity;
    double pricePerItem;
public:
    Invoice(std::string pNumber, std::string pDescription, int qty, double price)
        : partNumber(pNumber), partDescription(pDescription), quantity(qty), pricePerItem(price) {}
    std::string getPartNumber() { return partNumber; }
    std::string getPartDescription() { return partDescription; }
    int getQuantity() { return quantity; }
    double getPricePerItem() { return pricePerItem; }
};

int main() {
    Invoice inv("1234", "Hammer", 10, 15.99);
    std::cout << "Part Number: " << inv.getPartNumber() << std::endl;
    std::cout << "Description: " << inv.getPartDescription() << std::endl;
    std::cout << "Quantity: " << inv.getQuantity() << std::endl;
    std::cout << "Price per Item: " << inv.getPricePerItem() << std::endl;
    return 0;
}
