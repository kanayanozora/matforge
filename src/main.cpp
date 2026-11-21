#include <iostream>
#include <matforge/matrix.hpp>
#include <matforge/matrixop.hpp>

using namespace std;

static std::vector<double> matrixInit(int rows, int cols) {
    std::vector<double> data(rows * cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> data[i * cols + j];
        }
    }

    return data;
}
int main() {
    //Minimal interactive terminal input
    int rowsA, colsA;

    std::cout << "Enter number of rows: ";
    std::cin >> rowsA;
    std::cout << "Enter number of columns: ";
    std::cin >> colsA;
    if (rowsA <= 0 || colsA <= 0) {
        throw std::invalid_argument("Rows and cols should be positive");
    }
    const std::vector<double> mtxA = matrixInit(rowsA, colsA);
    Matrix A(rowsA, colsA, mtxA);

    int rowsB, colsB;
    std::cout << "Enter number of rows: ";
    std::cin >> rowsB;
    std::cout << "Enter number of columns: ";
    std::cin >> colsB;
    if (rowsB <= 0 || colsB <= 0) {
        throw std::invalid_argument("Rows and cols should be positive");
    }
    const std::vector<double> mtxB = matrixInit(rowsB, colsB);
    Matrix B(rowsB, colsB, mtxB);

    //Mtx addition and subtraction
    const Matrix cAdd = MatrixOp::mtxAddition(A, B);
    const Matrix cSub = MatrixOp::mtxSubtraction(A, B);

    std::cout << "Matrix addition" << std::endl;
    cAdd.printMtx();
    std::cout << "Matrix subtraction" << std::endl;
    cSub.printMtx();
}