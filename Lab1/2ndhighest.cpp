// Write a program that finds the second highest number in a float type array of 20
// elements using pointer.
#include<iostream>
using namespace std;
int main(){
    float NumArray[20];
    cout<<"Enter the Elements: ";
    for (int i =0;i<sizeof(NumArray);i++)
        cin>>NumArray[i];
float *ptr = NumArray;
float highest = 0;
float secondHighest = 0;
// Find highest
for (int i = 0; i < 20; i++) {
    if (*(ptr + i) > highest) {
        secondHighest = highest;
        highest = *(ptr + i);
    } else if (*(ptr + i) > secondHighest && *(ptr + i) < highest) {
        secondHighest = *(ptr + i);
    }
}
cout << "Second highest number is: " << secondHighest << endl;
return 0;}
