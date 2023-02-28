//
// Created by Mishach on 28.02.2023.
//

#pragma once

#include <vector>

namespace mt {
    template<typename T, unsigned int n, unsigned int m>
    class Matrix {
    public:
        Matrix(T object, unsigned N, unsigned M);
        Matrix(const Matrix& temp);
        ~Matrix();

    private:
        T* matrix[n][m];
//        std::vector<std::vector<T>> matrix;
        unsigned int n_size;
        unsigned int m_size;
        T object;

        void fillByObject();
    };
}
