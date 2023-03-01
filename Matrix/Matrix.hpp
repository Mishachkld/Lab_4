//
// Created by Mishach on 28.02.2023.
//

#pragma once

#include <vector>
#include <iostream>

namespace mt {

    template<class T>
    class Matrix {
    public:
        Matrix(unsigned int n , unsigned int m);

        Matrix(const Matrix &temp);

        ~Matrix();

//        friend std::ostream& operator >> (std::ostream& outStream, const Matrix& temp);
    private:
        T **matrix;
//        std::vector<std::vector<T>> matrix;
        unsigned int n_size;
        unsigned int m_size;
//        T object;


        void fillByObject();
    };
}
