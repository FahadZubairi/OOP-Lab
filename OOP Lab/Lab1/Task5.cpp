#include <iostream>
#include <iomanip> 
#include <string>  
using namespace std;

int main() {
   
    string movieName;
    double adultTicketPrice, childTicketPrice, percentageDonated;
    int adultTicketsSold, childTicketsSold;

    cout << "Enter the movie name: ";
    getline(cin, movieName);
    cout << "Enter the price of an adult ticket: ";
    cin >> adultTicketPrice;
    cout << "Enter the price of a child ticket: ";
    cin >> childTicketPrice;
    cout << "Enter the number of adult tickets sold: ";
    cin >> adultTicketsSold;
    cout << "Enter the number of child tickets sold: ";
    cin >> childTicketsSold;
    cout << "Enter the percentage of gross amount to be donated: ";
    cin >> percentageDonated;
    double grossAmount = (adultTicketPrice * adultTicketsSold) + (childTicketPrice * childTicketsSold);
    double amountDonated = (grossAmount * percentageDonated) / 100.0;
    double netSale = grossAmount - amountDonated;

    cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout << left << setw(40) << "Movie Name:" << " " << movieName << endl;
    cout << left << setw(40) << "Number of Tickets Sold:" << " " << (adultTicketsSold + childTicketsSold) << endl;
    cout << left << setw(40) << "Gross Amount:" << " $ " << fixed << setprecision(2) << right << grossAmount << endl;
    cout << left << setw(40) << "Percentage of Gross Amount Donated:" << " " << fixed << setprecision(2) << percentageDonated << "%" << endl;
    cout << left << setw(40) << "Amount Donated:" << " $ " << fixed << setprecision(2) << right << amountDonated << endl;
    cout << left << setw(40) << "Net Sale:" << " $ " << fixed << setprecision(2) << right << netSale << endl;

    return 0;
}
