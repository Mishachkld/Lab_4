//
// Created by Mishach on 28.02.2023.
//
#pragma once

#include <iostream>
#include <cmath>

namespace mt {

    template<class T, class T1, class T2>
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


        /* T minor2(int k) {
             T result = 0;

             for (int i = 0; i < n_size - 1; i++)
                 for (int j = 0; j < m_size - 1; j++)
                         result +=
             return result;
         }*/

        T determinant() {
            T result = 0;
            T **minor = new T *[n_size - 1];
            for (int i = 0; i < n_size; i++)
                minor[i] = new T[m_size - 1];

            if ((n_size == m_size) and (n_size <= 3)) {
                if (n_size == 1)
                    result = matrix[0][0];
                else if (n_size == 2)
                    result = static_cast<T>((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));  /// ошибка выскаивает
                else
                    result = (matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[1][0] * matrix[0][2] * matrix[2][1] + matrix[0][1] * matrix[2][0] * matrix[1][2] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][0] * matrix[1][2] * matrix[2][1] - matrix[2][2] * matrix[0][1] * matrix[1][0]);
                   /* for (int j = 0; j < m_size; j++) {
                        result += pow(-1, 1 + j) * (matrix[0][j] * fillMinor(minor, j)); //(pow(-1, 1 + j)) *
                    }*/

            }

            return result;
        }

        T& at(unsigned int i , unsigned int j){
            if (i < n_size and j < m_size)
                return matrix[i][j];
            std::abort();
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
            Matrix<T, T1, T2> newMatrix(n_size, temp.m_size);
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
        T fillMinor(T **minor, int n) {   /// заполнить матрицу объектами
            T result = 0;
            int a = 1;
            int b = 1;
            for (int i = 0; i < n_size; i++)
                for (int j = 0; j < m_size; j++)
                    if ((j != n) and (i != 0)) {
                        (j < n and i > 0) ? minor[i-1][j] = matrix[i][j] : ((j > n and i > 0) ? minor[i - 1][j - 1] = matrix[i][j]: a = 1 );

//                        std::cout << " : " << minor[i][j]<< " " << i  << " " << j << std::endl;
                    }



            result = (minor[0][0] * minor[1][1]) - (minor[1][2] * minor[2][1]);
            return result;
        }

        void deleteMatrix() {
            for (int i = 0; i < n_size; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
    };


}
