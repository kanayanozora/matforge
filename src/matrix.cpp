#include <iostream>
#include <matforge/matrix.hpp>
using namespace std;

//Constructor
Matrix::Matrix(const int row, const int col, const std::vector<double>& mtx):
    row(row), col(col), mtx(mtx) {}
Matrix::Matrix(const int row, const int col): row(row), col(col), mtx(row * col) {};
Matrix::Matrix(): row(0), col(0) {};
Matrix::~Matrix() = default;

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

void Matrix::printMtx() const {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << mtx[i * col + j] << " ";
        }
        std::cout << std::endl;
    }
}