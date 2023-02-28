//
// Created by Mishach on 28.02.2023.
//

#include "Matrix.hpp"

namespace mt {


    template<typename T, unsigned int N, unsigned int M>
    Matrix<T, N, M>::Matrix(T object, unsigned int n, unsigned int m) {
        n_size = n;
        m_size = m;
        this->object = object;
        fillByObject();
    }

    template<typename T, unsigned int n, unsigned int m>
    Matrix<T, n, m>::~Matrix() {
        delete[] matrix
    }

    template<typename T, unsigned int n, unsigned int m>
    void Matrix<T, n, m>::fillByObject() {
        for (int i = 0; i < n_size; i++) {
            for (int j = 0; j < m_size; j++) {
                matrix[i][j] = object;
            }
        }
    }

    template<typename T, unsigned int n, unsigned int m>
    Matrix<T, n, m>::Matrix(const Matrix &temp) {
        m_size = temp.m_size;
        n_size = temp.n_size;
        object = temp.object;
        fillByObject();
    }
}