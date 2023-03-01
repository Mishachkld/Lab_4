//
// Created by Mishach on 28.02.2023.
//

#include "Matrix.hpp"

namespace mt {


    template<class T>
    Matrix<T>::Matrix(unsigned int n , unsigned int m) {
        n_size = n;
        m_size = m;
        matrix = new T[n_size][m_size];
        fillByObject();
    }

    template<class T>
    Matrix<T>::Matrix(const Matrix &temp) {
        m_size = temp.m_size;
        n_size = temp.n_size;
        matrix = new T[n_size][m_size];
        std::copy(temp.matrix, temp.matrix + temp.n_size, matrix);
        //        object = temp.object;
        fillByObject();
    }

    template<class  T>
    Matrix<T>::~Matrix() {
        delete[] matrix;
    }

    template<class  T>
    void Matrix<T>::fillByObject() {
        for (int i = 0; i < n_size; i++) {
            for (int j = 0; j < m_size; j++) {
                matrix[i][j] = 0;
            }
        }
    }
}