#include <iostream>
#include "Matrix/Matrix.hpp"


int main() {

    mt::Matrix<int, 3, 3> matrix;
    mt::Matrix<int,3,3> matrix2;
    std::cin >> matrix;
    matrix2 = matrix;
    matrix *= matrix2;
    mt::Matrix<int, 3,3> matrix3 = matrix + matrix2;
    std::cout << matrix;
    std::cout << matrix3;
    std::cout << matrix3.determinant() << " ";
    matrix.at(1, 1) = 46;
    std::cout << matrix.at(1, 1);


}








