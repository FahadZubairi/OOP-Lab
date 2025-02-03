// Task 2: You are required to pass a single dimension array to a function (type of the array can be your
// choice) and perform add operations to each element. Return the array to the main function after
// completion. One small catch is that the arguments and the return type should be void*. (Create an array
// via the main arguments)
#include <iostream>
#include <cstdlib>

using namespace std;

void* processArray(void* arr, int size) {
    int* array = static_cast<int*>(arr);
    for (int i = 0; i < size; i++) {
        array[i] += 5;
    }
    return array;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <number1> <number2> ... <numberN>" << endl;
        return 1;
    }

    int size = argc - 1;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    void* result = processArray(static_cast<void*>(arr), size);
    int* modifiedArray = static_cast<int*>(result);

    for (int i = 0; i < size; i++) {
        cout << modifiedArray[i] << " ";
    }

    delete[] arr;
    return 0;
}