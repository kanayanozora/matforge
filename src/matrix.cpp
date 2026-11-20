#include <iostream>
#include <matforge/matrix.hpp>
using namespace std;

//Constructor
Matrix::Matrix(int row, int col): row(row), col(col), mtx(row * col) {};

// Getters
int Matrix::getRow() const {
    return row;
}

int Matrix::getCol() const {
    return col;
}

std::vector<double> Matrix::getMtx() const {
    return mtx;
}

//Setters
void Matrix::setRow(int row) {
    this->row = row;
}

void Matrix::setCol(int col) {
    this ->col = col;
}