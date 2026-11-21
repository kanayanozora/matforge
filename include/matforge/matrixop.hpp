#pragma once
#include <vector>
#include <matforge/matrix.hpp>

//Methods
class MatrixOp {
public:
    static Matrix mtxAddition(const Matrix& a, const Matrix& b);
    static Matrix mtxSubtraction(const Matrix& a, const Matrix& b);
};