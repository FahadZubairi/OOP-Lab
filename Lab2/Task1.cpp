// Task 1: Write a program that calculates the sum of all the elements in array using pointers
// (Note: Generate the array via user in the main function use argv)
#include <iostream>
#include <cstdlib> 
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <number1> <number2> ... <numberN>" << endl;
        return 1;
    }
    int size = argc - 1;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = std::atoi(argv[i + 1]);
    }


    int sum = 0;
    int *ptr = arr; 
    for (int i = 0; i < size; i++) {
        sum += *ptr; 
        ptr++;      
    }
    cout << "Sum of array elements: " << sum <<endl;

    delete[] arr;

    return 0;
}
