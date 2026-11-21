#include <iostream>
#include <matforge/matrix.hpp>
#include <matforge/matrixop.hpp>

using namespace std;

//Helper functions
static std::vector<double> matrixInit(const int rows, const int cols) {
    std::vector<double> data(rows * cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> data[i * cols + j];
        }
    }

    return data;
}

static void matrixAddition() {
    int rowsA, colsA, rowsB, colsB;
    std::cout << "Matrix A";
    std::cout << "Enter number of rows: ";
    std::cin >> rowsA;
    std::cout << "Enter number of columns: ";
    std::cin >> colsA;
    if (rowsA <= 0 || colsA <= 0) {
        throw std::invalid_argument("Rows and cols should be positive");
    }
    const std::vector<double> mtxA = matrixInit(rowsA, colsA);
    const Matrix A(rowsA, colsA, mtxA);

    std::cout << "Matrix B";
    std::cout << "Enter number of rows: ";
    std::cin >> rowsB;
    std::cout << "Enter number of columns: ";
    std::cin >> colsB;
    if (rowsB <= 0 || colsB <= 0) {
        throw std::invalid_argument("Rows and cols should be positive");
    }
    const std::vector<double> mtxB = matrixInit(rowsB, colsB);
    const Matrix B(rowsB, colsB, mtxB);
    const Matrix cAdd = MatrixOp::mtxAddition(A, B);
    std::cout << "Matrix addition" << std::endl;
    cAdd.printMtx();
}

static void matrixSubtraction() {
    int rowsA, colsA, rowsB, colsB;
    std::cout << "Matrix A";
    std::cout << "Enter number of rows: ";
    std::cin >> rowsA;
    std::cout << "Enter number of columns: ";
    std::cin >> colsA;
    if (rowsA <= 0 || colsA <= 0) {
        throw std::invalid_argument("Rows and cols should be positive");
    }
    const std::vector<double> mtxA = matrixInit(rowsA, colsA);
    const Matrix A(rowsA, colsA, mtxA);

    std::cout << "Matrix B";
    std::cout << "Enter number of rows: ";
    std::cin >> rowsB;
    std::cout << "Enter number of columns: ";
    std::cin >> colsB;
    if (rowsB <= 0 || colsB <= 0) {
        throw std::invalid_argument("Rows and cols should be positive");
    }
    const std::vector<double> mtxB = matrixInit(rowsB, colsB);
    const Matrix B(rowsB, colsB, mtxB);

    const Matrix cSub = MatrixOp::mtxSubtraction(A, B);

    std::cout << "Matrix subtraction" << std::endl;
    cSub.printMtx();
}

static void scalarMultiplication() {
    int rowsA, colsA;
    std::cout << "Enter number of rows: ";
    std::cin >> rowsA;
    std::cout << "Enter number of columns: ";
    std::cin >> colsA;
    if (rowsA <= 0 || colsA <= 0) {
        throw std::invalid_argument("Rows and cols should be positive");
    }
    const std::vector<double> mtxA = matrixInit(rowsA, colsA);
    const Matrix A(rowsA, colsA, mtxA);

    double scalar;
    std::cout <<"Enter scalar value for scalar multiplication: ";
    std::cin >> scalar;
    const Matrix scMul = MatrixOp::scalarMultiplication(A, scalar);
    std::cout << "Scalar matrix multiplication" << std::endl;
    scMul.printMtx();

}

static void matrixTranspose() {
    int rowsA, colsA;
    std::cout << "Enter number of rows: ";
    std::cin >> rowsA;
    std::cout << "Enter number of columns: ";
    std::cin >> colsA;
    if (rowsA <= 0 || colsA <= 0) {
        throw std::invalid_argument("Rows and cols should be positive");
    }
    const std::vector<double> mtxA = matrixInit(rowsA, colsA);
    const Matrix A(rowsA, colsA, mtxA);

    const Matrix mtxTranspose = MatrixOp::mtxTranspose(A);
    std::cout << "Matrix transpose" << std::endl;
    mtxTranspose.printMtx();

}

static void chooseOperation(const int option) {
    switch (option) {
        case 1:
            matrixAddition();
            break;
        case 2:
            matrixSubtraction();
            break;
        case 3:
            scalarMultiplication();
            break;
        case 4:
            matrixTranspose();
            break;
        default:
            throw std::invalid_argument("Invalid option");
    }
}

int main() {
    int option;

    while (true) {
        std::cout << "Enter the following number for their corresponding operations: \n";
        std::cout << "Op 1: Matrix addition \n";
        std::cout << "Op 2: Matrix subtraction \n";
        std::cout << "Op 3: Scalar multiplication \n";
        std::cout << "Op 4: Matrix transpose \n";
        std::cout << "0: Exit\n";

        std::cout <<"Your choice:";
        std::cin >> option;

        if (option == 0) {
            std::cout << "Exiting matforge.\n";
            break;
        }

        try {
            chooseOperation(option);
        }
        catch (const std::invalid_argument& e) {
            std::cout <<e.what() << "\n";
        }

    }
    return 0;

}