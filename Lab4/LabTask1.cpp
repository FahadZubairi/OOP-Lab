#include <iostream>
using namespace std;
class matrix
{
    int x;
    int y;
    double **elements;

public:
    matrix(double row = 0, double col = 0) : x(row), y(col) {}
    matrix(int row, int col)
    {
        elements = new double *[row];
        for (int i = 0; i < row; i++)
        {
            elements[i] = new double[col]();
        }
    }
    matrix(const matrix &mat):x(mat.x), y(mat.y)
    {
        elements = new double *(*mat.elements);
    }
    matrix(matrix&& mat)noexcept{
        elements = new double *(*mat.elements);
        mat.elements = nullptr;
    }
    ~matrix(){
        for (int i =0;i<x;i++){
            delete[] elements[i];
        }
        delete[] elements;
    }
    int getRows(){
        return x;
    }
    int getCols(){
        return y;
    }
    double& at(int r, int c){
        if ((r<0||r>=x)&&(c<0||c>=y)){
            cout<< "Range out of bounds"<<endl;

        }
        return elements[r][c];
    }
    void fill(double value){
        for (int i =0;i<x;i++){
            for (int j = 0;j<y;j++){
                elements[i][j] = value;
            }
        }
    }
    matrix transpose(){
        matrix transposed(x,y);
        for (int i =0;i<x;i++){
            for (int j =0;j<y;j++){
                elements[i][j] = elements[j][i];
            }
        }
        return transposed;
         for (int i =0;i<x;i++){
            for (int j =0;j<y;j++){
                cout<<elements[i][j];
    }}
}};

int main(){
    matrix obj(2,4);
    obj.fill(2);
    obj.transpose();
}
