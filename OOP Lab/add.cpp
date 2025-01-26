#include<iostream>
using namespace std;
int add(int a, int b){
    return (a+b);
}
int main(){
    int sum;
    sum = add(78,100);
    cout<< "78+100 = "<<sum<<endl;
    return 0;
}