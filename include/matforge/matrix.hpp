#pragma once
#include <vector>

class Matrix {
    int row;
    int col;
    std::vector<double> mtx;

public:
    Matrix(int row, int col);
    Matrix(int row, int col, const std::vector<double>& mtx);
    Matrix();
    ~Matrix();

    int getRow() const;
    int getCol() const;
    std::vector<double> getMtx() const;

    void setRow(int row);
    void setCol(int col);

    void printMtx() const;
};
