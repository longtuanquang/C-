#ifndef _MATRIX_CPP
#define _MATRIX_CPP

#include <iostream>
#include "matrix.h"
// Implementation the constructor
template <typename T>
Matrix<T>::Matrix(const unsigned _rows, const unsigned _cols, const T& _initial){
    rows = _rows;
    cols = _cols;
    // resize(#number of outer vector = number of cols)
    mat.resize(_rows);
    for(int i = 0; i < _cols; i++){
        mat[i].resize(_cols,_initial);
    }
}
// Copy constructor
Matrix<T>::Matrix(const Matrix<T> m){
    rows = m.get_rows();
    cols = m.get_cols();
    mat = m.mat;
}
// Destructor
Matrix<T>::~Matrix(){}
// Assignment for matrix
Matrix<T>& Matrix::operator=(const Matrix<T>& rhs){
    // Check the of the current matrix is the same as the rhs's address
    if(this == &rhs){
        return this;
    }
    // resize the matrix
    unsigned new_rows = rhs.get_rows();
    unsigned new_cols = rhs.get_cols();
    mat.resize(new_rows);
    for(int i = 0; i < new_rows; i++){
        mat[i].resize(new_cols,initial);
    }
    // Assign values of rhs to this
    for(int i= 0; i < new_rows; i++){
        for(int j = 0; j < new_cols; j++){
            mat[i][j] = rhs[i][j];
        }
    }
    rows = new_rows;
    cols = new_cols;
    return *this;
}

template<typename T>
Matrix<T> Matrix::operator+(const Matrix<T>& rhs){
    // Create a new matrix
    unsigned const new_rows = rows;
    unsigned const new_cols = cols;
    Matrix new_mat = new Matrix(new_rows, new_cols, 0.0);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            new_mat[i][j] = (*this).mat[i][j] + rhs[i][j]; // (*this).mat[i][j] == this->mat[i][j]
        }
    }
    return new_mat;
}
template<typename T>
Matrix<T>& Matrix::operator+=(const Matrix<T>& rhs){
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();
    for(int i = 0; i < rows; i++){
        for(int j =0; i <cols; i++){
            this->mat[i][j] += rhs(i,j);
        }
    }
    return *this;
}
template<typename T>
Matrix<T> Matrix::operator*(const Matrix<T>& rhs){
    unsigned new_rows = this.get_rows();
    unsigned new_cols = rhs.get_cols();
    Matrix new_mat = new Matrix(new_rows, new_cols, 0.0);
    for(int i = 0; i < new_rows; i++){
        for(int j = 0; j < new_cols; j++){
            for(int k = 0; k < new_rows; k++){
                new_mat[i][j] += this->map[i][k] * rhs[k][j];
            }
        }
    }
    return new_mat;
}
Matrix<T>& Matrix::operator*=(const Matrix<T>& rhs){
    Matrix result = (*this)*(rhs);
    return (*this);
}

template<typename T>
Matrix<T> Matrix::transpose(){
    unsigned new_rows = this.get_cols();
    unsigned new_cols = this.get_rows();
    Matrix new_mat = new Matrix(new_rows, new_cols, 0.0);
    for(int i = 0; i < new_rows; i++){
        for(int j = 0; j < new_cols; j++){
            new_mat[i][j] = this->mat[j][i];
        }
    }
    return new_mat;
}


Matrix<T>::get_rows(){
    return rows;
}
Matrix<T>::get_cols(){
    return cols;
}
//
#endif
