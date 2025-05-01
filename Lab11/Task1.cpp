#include <iostream>
#include <any>
#include <typeinfo>
#include <stdexcept>
using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "Bad type access";
    }
};

class TypeSafeContainer {
    any value;
public:
    template<typename T>
    void store(T v) {
        value = v;
    }

    template<typename T>
    T get() {
        if (!value.has_value() || value.type() != typeid(T)) {
            throw BadTypeException();
        }
        return any_cast<T>(value);
    }
};
