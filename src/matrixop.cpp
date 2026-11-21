#include "matforge/matrixop.hpp"
#include "matforge/matrix.hpp"
#include <vector>
#include <stdexcept>

Matrix MatrixOp::mtxAddition(const Matrix& a, const Matrix& b) {
    //indices
    const int rowA = a.getRow();
    const int colA = a.getCol();
    const int rowB = b.getRow();
    const int colB = b.getCol();

    if (rowA != rowB || colA != colB) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }

    const std::vector<double> mtxB = b.getMtx();
    const std::vector<double> mtxA = a.getMtx();
    std::vector<double> mtxC(rowA * colA);

    for (int i = 0 ; i < rowA ; i++) {
        for (int j = 0 ; j < colA ; j++) {
            const int index = i * colA + j;
            mtxC[index] = mtxA[index] + mtxB[index];
        }
    }
    Matrix c(rowA, colA, mtxC);

    return c;
}

Matrix MatrixOp::mtxSubtraction(const Matrix& a, const Matrix& b) {
    //indices
    const int rowA = a.getRow();
    const int colA = a.getCol();
    const int rowB = b.getRow();
    const int colB = b.getCol();

    if (rowA != rowB || colA != colB) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }

    const std::vector<double> mtxB = b.getMtx();
    const std::vector<double> mtxA = a.getMtx();
    std::vector<double> mtxC(rowA * colA);

    for (int i = 0 ; i < rowA ; i++) {
        for (int j = 0 ; j < colA ; j++) {
            const int index = i * colA + j;
            mtxC[index] = mtxA[index] - mtxB[index];
        }
    }
    Matrix c(rowA, colA, mtxC);

    return c;
}