#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Flight {
    string flightNumber, departure, arrival;
    int capacity;
    int bookedSeats;

public:
    Flight(string f, string d, string a, int c) : flightNumber(f), departure(d), arrival(a), capacity(c), bookedSeats(0) {}

    bool bookSeat() {
        if (bookedSeats < capacity) {
            bookedSeats++;
            return true;
        }
        return false;
    }

    bool cancelSeat() {
        if (bookedSeats > 0) {
            bookedSeats--;
            return true;
        }
        return false;
    }

    bool upgradeSeat() {
        return bookedSeats > 0;
    }

    void showStatus() {
        cout << flightNumber << " - Booked: " << bookedSeats << "/" << capacity << endl;
    }
};

class Passenger {
    string id, name;

public:
    Passenger(string i, string n) : id(i), name(n) {}

    void requestBooking(Flight& flight) {
        if (flight.bookSeat()) cout << name << " booked a seat.\n";
        else cout << name << " failed to book a seat.\n";
    }
};

int main() {
    Flight f1("PK101", "Lahore", "Karachi", 2);
    Passenger p1("P01", "Ali");
    Passenger p2("P02", "Sara");
    Passenger p3("P03", "Ahmed");

    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p3.requestBooking(f1);

    f1.showStatus();

    return 0;
}
