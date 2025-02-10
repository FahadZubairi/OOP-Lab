//Program to read a 2D array of size 3x3 find the sum for each row, print the sum line by line.
#include<iostream>
using namespace std;
int main(){
    int Array2D[3][3];
    int sum = 0;
    int row, col;
    cout<<"Enter the Elements: ";
    for (row = 0;row<3;row++){
        for (col = 0;col<3;col++){
            cin>>Array2D[row][col];
            sum += Array2D[row][col];
        }
        cout<<"The sum of row "<<row+1<<" is "<<sum<<endl;
        sum = 0;
    }
    cout<<endl;
}
