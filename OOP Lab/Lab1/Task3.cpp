// Write a program in C++ to calculate and print the Electricity bill of a given customer. The customer id,
// name and unit consumed by the user should be taken from the keyboard and display the total amount to
// pay to the customer.
#include<iostream>
using namespace std;
int main(){
    int customer_id;
    string name;
    int units_consumed;
    float bill;
    float surcharge = 0;
    float Net_amount;
    float charge = 0;
    cout<<"Enter Customer ID: ";
    cin>>customer_id;
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter Units consumed: ";
    cin>>units_consumed;
    if (units_consumed<200){
        charge = 16.2;
        bill = units_consumed * charge;
        Net_amount = bill;
    }
    else if (units_consumed>=200 && units_consumed<300){
        charge = 20.1;
        bill = units_consumed * charge;
        Net_amount = bill;
    }
    else if (units_consumed>=300 && units_consumed<500){
        charge = 27.1;
        bill = units_consumed * charge;
        Net_amount = bill;
    }
    else if (units_consumed>500){
        charge = 35.9;
        bill = units_consumed * charge;
        if (bill>18000){
            surcharge = bill * 0.15;
        }
        Net_amount = bill + surcharge;
    }
    cout<< "Customer ID: "<<customer_id<<endl;
    cout<<"Customer Name: "<<name<<endl;
    cout<<"Units Consumed: "<<units_consumed<<endl;
    cout<<"Amount Charges @ Rs."<<charge<< " per unit: "<<bill<<endl;
    cout<<"Surcharge Amount: "<<surcharge<<endl;
    cout<<"Net Amount Paid by the customer: "<<Net_amount<<endl;
    return 0;
}