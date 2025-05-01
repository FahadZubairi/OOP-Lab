#include <iostream>
#include <stdexcept>
using namespace std;

class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds";
    }
};

template<typename T>
class SafeArray {
    T* arr;
    int size;
public:
    SafeArray(int s) : size(s) {
        arr = new T[s];
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw ArrayIndexOutOfBounds();
        }
        return arr[index];
    }

    ~SafeArray() {
        delete[] arr;
    }
};

int main() {
    SafeArray<int> sa(5);
    try {
        sa[2] = 10;
        cout << sa[2] << endl;
        cout << sa[5] << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}
