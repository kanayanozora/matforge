#pragma once
#include <matforge/matrix.hpp>

//Methods
class MatrixOp {
public:
    static Matrix mtxAddition(const Matrix& a, const Matrix& b);
    static Matrix mtxSubtraction(const Matrix& a, const Matrix& b);
    static Matrix scalarMultiplication(const Matrix& a, const double& scalar);
    static Matrix mtxTranspose (const Matrix& a);
    static Matrix mtxMultiplication(const Matrix& a, const Matrix& b);
};