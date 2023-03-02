#include <iostream>
#include "Matrix/Matrix.hpp"


int main() {

    mt::Matrix<int> matrix(2, 2);
    mt::Matrix<int> matrix2(2, 2);
    std::cin >> matrix;
    matrix2 *= matrix;
//    mt::Matrix<int> matrix3 = matrix2 * matrix;
//    matrix.getItem(1, 2) = 99999;
    std::cout << matrix2;


}








