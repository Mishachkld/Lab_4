//
// Created by Mishach on 28.02.2023.
//
#pragma once

#include <iostream>

namespace mt {

    template<class T>
    class Matrix {
    public:
        Matrix(unsigned int n, unsigned int m) {
            n_size = n;
            m_size = m;
            matrix = new T *[n_size];
            for (int i = 0; i < n_size; i++) {
                matrix[i] = new T[m_size];
            }
//            fillByObject();
        }

        Matrix(const Matrix &temp) {
            m_size = temp.m_size;
            n_size = temp.n_size;
            matrix = new T *[n_size];
            for (int i = 0; i < n_size; i++)
                matrix[i] = new T[m_size];
            for (int i = 0; i < n_size; i++)
                for (int j = 0; j < m_size; j++)
                    matrix[i][j] = temp.matrix[i][j];
        }

        ~Matrix() {
            deleteMatrix();
        }


        T determinant(){
            T result = 0;
            if((n_size == m_size) and (n_size <= 3)){
                if (n_size == 1)
                    result = matrix[0][0];
                else if(n_size == 2)
                    result = matrix[0][0] * matrix[1][1] - matrix[1][2] * matrix[2][1];
                else{
                    for (int i = 0; i < n_size; i++) {
                        for (int j = i; j < m_size; j++) {
                            result = matrix[i][j];
                        }
                    }
                }
            }

            return result;
        }

        Matrix &operator=(const Matrix &temp) {
            Matrix newMatrix = temp;
            n_size = newMatrix.n_size;
            m_size = newMatrix.m_size;
            deleteMatrix();
            matrix = new T *[n_size];
            for (int i = 0; i < newMatrix.n_size; i++) {  /// будет ли здесь утечка памяти(или еще чего-нибудь)?
                matrix[i] = newMatrix.matrix[i];
            }
            return *this;
        }

        Matrix operator+(const Matrix &temp) {
            Matrix newMatrix = temp;
            for (int i = 0; i < n_size; i++) {
                for (int j = 0; j < m_size; j++) {
                    newMatrix.matrix[i][j] += matrix[i][j];
                }
            }
            return newMatrix;
        }

        Matrix &operator++(int k) {
            for (int i = 0; i < n_size; i++)
                for (int j = 0; j < m_size; j++)
                    matrix[i][j]++;
            return *this;
        }

        Matrix &operator+=(const Matrix &temp) {
            Matrix newMatrix = temp;
            for (int i = 0; i < n_size; i++)
                for (int j = 0; j < m_size; j++)
                    matrix[i][j] += temp.matrix[i][j];
            return *this;
        }

        /// подумать
        Matrix operator*(const Matrix &temp) {
            Matrix<T> newMatrix(n_size, temp.m_size);
            for (int i = 0; i < n_size; i++)
                for (int j = 0; j < newMatrix.m_size; j++)
                    for (int k = 0; k < newMatrix.m_size; k++)
                        newMatrix.matrix[i][j] += matrix[i][k] * temp.matrix[k][j];  ///по формуле....
            return newMatrix;
        }

        Matrix &operator*=(const Matrix &temp) {
            *this = *this * temp;
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &outStream, const Matrix &temp) {
            for (int i = 0; i < temp.n_size; i++) {
                for (int j = 0; j < temp.m_size; j++)
                    outStream << temp.matrix[i][j] << " ";
                outStream << std::endl;
            }
            return outStream;
        }

        friend std::istream &operator>>(std::istream &outStream, const Matrix &temp) {
            for (int i = 0; i < temp.n_size; i++)
                for (int j = 0; j < temp.m_size; j++)
                    outStream >> temp.matrix[i][j];
            return outStream;
        }

    private:
        T **matrix;
        unsigned int n_size;
        unsigned int m_size;

        ///Functions
        void fillByObject() {   /// заполнить матрицу объектами
            for (int i = 0; i < n_size; i++)
                for (int j = 0; j < m_size; j++)
                    matrix[i][j] = 0;
        }

        void deleteMatrix() {
            for (int i = 0; i < n_size; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

    };


}
