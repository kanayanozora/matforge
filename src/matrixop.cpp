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

Matrix MatrixOp::scalarMultiplication(const Matrix& a, const double& scalar) {
    const std::vector<double> mtxA = a.getMtx();
    std::vector<double> mtxC;

    for (double i : mtxA) {
        mtxC.push_back(scalar * i);
    }
    Matrix c(a.getRow(), a.getCol(), mtxC);

    return c;
}

Matrix MatrixOp::mtxTranspose(const Matrix& a) {
    const int rowA = a.getRow();
    const int colA = a.getCol();
    const std::vector<double> mtxA = a.getMtx();
    std::vector<double> mtxC;

    for (int i = 0; i < colA; i++) {
        for (int j = 0; j < rowA; j++) {
            mtxC.push_back(mtxA[j * colA + i]);
        }
    }
    Matrix c(colA, rowA, mtxC);

    return c;
}
/*Computes for A x B = C
Dimensions for C (rowA x colB)

*/
Matrix MatrixOp::mtxMultiplication(const Matrix& a, const Matrix& b) {
    const int rowA = a.getRow();
    const int colA = a.getCol();
    const int rowB = b.getRow();
    const int colB = b.getCol();

    const std::vector<double> mtxB = b.getMtx();
    const std::vector<double> mtxA = a.getMtx();
    std::vector<double> mtxC(rowA*colB, 0);

    //Dimension check
    if (colA != rowB) {
        throw std::invalid_argument("Incorrect dimensions for matrix multiplication.");
    }

    //Calculation
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            for (int k = 0; k < colA; k++) {
                mtxC[i * colB + j] += mtxA[i * colA + k] * mtxB[k * colB + j];
            }
        }
    }

    Matrix c(rowA, colB, mtxC);
    return c;
}
