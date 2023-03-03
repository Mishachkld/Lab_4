#include <iostream>
#include "Matrix/Matrix.hpp"


int main() {

    mt::Matrix<int, int, int> matrix(3, 3);
//    mt::Matrix<int, int, int> matrix2(3, 3);
    std::cin >> matrix;
//    matrix2 = matrix;
//    matrix *= matrix2;
    std::cout << matrix.determinant();


}








