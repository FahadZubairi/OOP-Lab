#include <iostream>
#include <string>
using namespace std;

class PatientRecord {
    string name, id, dob;
    string medicalHistory;
    string billingDetails;

public:
    PatientRecord(string n, string i, string d) : name(n), id(i), dob(d) {}

    string getPublicData() {
        return "Name: " + name + ", ID: " + id;
    }

    string getMedicalData(string role) {
        if (role == "doctor") return medicalHistory;
        return "Access Denied";
    }

    void updateMedicalHistory(string data, string role) {
        if (role == "doctor") medicalHistory = data;
    }

    void addBillingDetails(string data, string role) {
        if (role == "billing") billingDetails = data;
    }

    string getBillingDetails(string role) {
        if (role == "billing") return billingDetails;
        return "Access Denied";
    }
};

int main() {
    PatientRecord p("John Doe", "P1001", "1990-05-01");

    p.updateMedicalHistory("Diabetes", "doctor");
    p.addBillingDetails("$2000 paid", "billing");

    cout << p.getPublicData() << endl;
    cout << p.getMedicalData("doctor") << endl;
    cout << p.getMedicalData("receptionist") << endl;
    cout << p.getBillingDetails("billing") << endl;

    return 0;
}
