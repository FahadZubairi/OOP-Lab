#include <iostream>

using namespace std;

void resizeArray(int*& arr, int& size, int newSize) {
    int* temp = new int[newSize];
    for (int i = 0; i < size; i++) temp[i] = arr[i];
    delete[] arr;
    arr = temp;
    size = newSize;
}

int main() {
    int size = 5, count = 0;
    int* arr = new int[size];
    int num;
    while (cin >> num) {
        if (count >= size * 2) resizeArray(arr, size, size * 2);
        arr[count++] = num;
    }
    resizeArray(arr, size, count);
    for (int i = 0; i < count; i++) cout << arr[i] << " ";
    delete[] arr;
    return 0;
}