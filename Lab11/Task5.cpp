#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow";
    }
};

template<typename T>
class Stack {
    vector<T> data;
public:
    void push(T value) {
        data.push_back(value);
    }

    void pop() {
        if (data.empty()) {
            throw StackUnderflowException();
        }
        data.pop_back();
    }

    T top() {
        if (data.empty()) {
            throw StackUnderflowException();
        }
        return data.back();
    }

    bool empty() {
        return data.empty();
    }
};

int main() {
    Stack<int> s;
    try {
        s.push(10);
        s.push(20);
        cout << s.top() << endl;
        s.pop();
        s.pop();
        s.pop();
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}
