#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "Matrix dimension mismatch";
    }
};

template<typename T>
class Matrix {
    vector<vector<T>> data;
    int rows, cols;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(r, vector<T>(c));
    }

    T& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw out_of_range("Index out of range");
        }
        return data[r][c];
    }

    Matrix<T> operator+(const Matrix<T>& other) {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException();
        }
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) {
        if (cols != other.rows) {
            throw DimensionMismatchException();
        }
        Matrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }
};
