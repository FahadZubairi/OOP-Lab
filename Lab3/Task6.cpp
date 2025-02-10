// Create a class called Matrix containing a constructor that initializes the number of rows and number of columns
// of a new Matrix object. The Matrix class has the following information.
// 1. Number of rows of matrix
// 2. Number of columns of matrix
// 3. Elements of matrix in the form of 2D array
// The Matrix class has methods for each of the following
// 1. Get the number of rows
// 2. Get the number of columns
// 3. Set the elements of the matrix at the given position (i,j)
// 4. Adding two matrices. If the matrices are not addable, “Matrices cannot be added” will be displayed
// 5. Multiplying the two matrices
#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** matrix; 

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    int getRows() { return rows; }

    int getCols() { return cols; }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            matrix[i][j] = value;
        } else {
            cout << "Invalid position!\n";
        }
    }

    void inputMatrix() {
        cout << "Enter elements for a " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
    }

    void displayMatrix() {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrices cannot be added!\n";
            return Matrix(0, 0); 
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix multiply(Matrix& other) {
        if (cols != other.rows) {
            cout << "Matrices cannot be multiplied!\n";
            return Matrix(0, 0);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    Matrix mat1(r1, c1);
    mat1.inputMatrix();

    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;
    Matrix mat2(r2, c2);
    mat2.inputMatrix();
    cout << "\nFirst Matrix:\n";
    mat1.displayMatrix();
    cout << "\nSecond Matrix:\n";
    mat2.displayMatrix();

    if (r1 == r2 && c1 == c2) {
        Matrix sum = mat1.add(mat2);
        cout << "\nSum of Matrices:\n";
        sum.displayMatrix();
    } else {
        cout << "\nMatrices cannot be added (Different sizes).\n";
    }

    if (c1 == r2) {
        Matrix product = mat1.multiply(mat2);
        cout << "\nProduct of Matrices:\n";
        product.displayMatrix();
    } else {
        cout << "\nMatrices cannot be multiplied (Columns of first ≠ Rows of second).\n";
    }

    return 0;
}
