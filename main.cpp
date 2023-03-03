#include <iostream>
#include "Matrix/Matrix.hpp"


int main() {

    mt::Matrix<int, int, int> matrix(2, 2);
    mt::Matrix<int, int, int> matrix2(2, 2);
    std::cin >> matrix;
    matrix2 = matrix;
    matrix *= matrix;
    mt::Matrix<int, int, int> matrix3 = matrix + matrix2;
    std::cout << matrix;
    std::cout << matrix3;
    std::cout << matrix3.determinant();
    matrix.at(1,1) = 46;
    std::cout << matrix.at(1,1);


}








