#include <iostream>
#include "Matrix/Matrix.hpp"


int main() {

    mt::Matrix<int, int, int> matrix(2, 2);
//    mt::Matrix<int, int, int> matrix2(3, 3);
    std::cin >> matrix;
//    matrix2 = matrix;
//    matrix *= matrix2;
    matrix.at(1,1) = 46;
    std::cout << matrix.at(1,1);


}








