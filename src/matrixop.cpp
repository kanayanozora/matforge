#include "matforge/matrixop.hpp"
#include "matforge/matrix.hpp"
#include <vector>
#include <iostream>

Matrix MatrixOp::mtxAddition(const Matrix& a, const Matrix& b) {

    //indices
    int rowA = a.getRow();
    int colA = a.getCol();
    int rowB = b.getRow();
    int colB = b.getCol();

    //data matrices
    std::vector<double> mtxB = b.getMtx();

    //TODO: matrix add implementation

    //Filler
    return {};
}
