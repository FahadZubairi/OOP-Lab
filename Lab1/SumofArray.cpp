// Write a program that calculates the sum of all the elements in array using pointers
#include<iostream>
using namespace std;
int main(){
    int n;
    int Array[n];
    int sum = 0;
    cout<<"Enter the number of Elements in the Array: "<<endl;
    cin>>n;
    cout<<"Enter the Elements: ";
    int *ptr = Array;
    for (int i =0;i<n;i++){
        cin>>Array[i];
        sum += *(ptr + i);
    }
    cout<<"The sum of all Elements: "<<sum<<endl;
}
