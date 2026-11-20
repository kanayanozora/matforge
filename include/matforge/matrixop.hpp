#pragma once
#include <vector>
#include <matforge/matrix.hpp>

//Methods
class MatrixOp {
public:
    Matrix mtxAddition(const Matrix& a, const Matrix& b);
    Matrix mtxSubtraction(const Matrix& a, const Matrix& b);
};