// We are prototyping a robot that refills glasses during dinner. Every glass holds 200 milliliters. During dinner,
// people either drink water or juice, and as soon as there is less than 100 ml left in the glass, the robot refills it back
// to 200 ml.
// Create a class Glass with one public int field LiquidLevel and methods public Drink(int milliliters) that takes the
// amount of liquid that a person drank and public Refill() that refills the glass to be 200 ml full. Both methods
// should not return any value. Initially set LiquidLevel to 200. In the Main method create an object of class Glass
// and read commands from the screen until the user terminates the program (see next). Don&#39;t forget to refill the glass
// when needed!
#include<iostream>
#include<iomanip>
using namespace std;
class Glass{
    public:
    int Liquidlevel = 200;
    void Drink(int millilitres){
        if (millilitres>Liquidlevel){
            cout<<"You can only drink "<<Liquidlevel<<" ml of water"<<endl;
        }
        else{
        Liquidlevel = Liquidlevel - millilitres;
        cout<<"You drank "<<millilitres<<" ml of water, "<<Liquidlevel<< " ml remaining"<<endl;
    }}
    void Refill(){
        Liquidlevel = 200;
        cout<<"Glass Refilled, current liquid level "<<Liquidlevel<<" ml."<<endl;
    }
};
int main(){
    Glass glass;
    int choice;
    int ml;
    while (true){
    cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout<<left<<setw(10)<<"1. Drink "<<endl;
    cout<<left<<setw(10)<<"2. Refill"<<endl;
    cout<<left<<setw(10)<<"3. Exit"<<endl;

    cout<<"Enter the command you want to perform: ";
    cin>>choice;
    
    switch (choice)
    {
    case (1):
        cout<<"Enter the amount you want to drink: ";
        cin>>ml;
        glass.Drink(ml);
        break;
    case (2):
        if (glass.Liquidlevel<200){
            glass.Refill();
        }
        break;
    case (3):
        cout<<"Exiting Program...";
        return 0;
    default:
        cout<<"Enter a valid choice from 1,2 or 3;"<<endl;
        break;
    }
    }
}
