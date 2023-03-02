#include <iostream>
#include "Matrix/Matrix.hpp"


int main() {

    mt::Matrix<int> matrix(2, 2);
    mt::Matrix<int> matrix2(2, 2);
    std::cin >> matrix;
    matrix2 = matrix;
    matrix *= matrix2;
    std::cout << matrix;


}








