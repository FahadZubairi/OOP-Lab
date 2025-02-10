#include<iostream>
using namespace std;
int main(){
    int NumArray[5];
    int sum = 0;
    cout<<"Enter 5 numbers: ";
    for (int i =0;i<5;i++){
        cin>>NumArray[i];
        sum += NumArray[i];

    }
    cout<<endl;
    cout<<"The sum of the numbers is: "<<sum<<endl;
    cout<<"The numbers in reverse order are: ";
    for (int i = 4;i>=0;i--)
        cout<<NumArray[i]<<" ";
    cout<<endl;
}
