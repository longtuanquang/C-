#ifndef _MATRIX_H
#define _MATRIX_H
#include <vector>

template <typename T> class Matrix{
    /* Declaration of attributes */
    private:
        std::vector <std::vector<T> > mat;
        unsigned rows;
        unsigned cols;
    public:
        Matrix(unsigned _rows, unsigned _cols, const T& _initial);
        Matrix(const Matrix<T>& rhs); // copy construction 
        virtual ~Matrix();
        /* Operator overloading */
        Matrix<T>& operator=(const Matrix<T>& rhs);
        Matrix<T> operator+(const Matrix<T>& rhs);
        Matrix<T> operator+=(const Matrix<T>& rhs);
        Matrix<T> operator-(const Matrix<T>& rhs);
        Matrix<T>& operator-=(const Matrix<T>& rhs);
        Matrix<T> operator*(const Matrix<T>& rhs);
        Matrix<T>& operator*=(const Matrix<T>& rhs);
        Matrix<T> transpose();

        /* Matrix/scalar operation */
        Matrix<T> operator+(const T& rhs);
        Matrix<T> operator-(const T& rhs);
        Matrix<T> operator*(const T& rhs);
        Matrix<T> operator/(const T& rhs);

        /* Matrix/vector operatiorn */
        std::vector<T> operator*(const std::vector<T>& rhs);
        std::vector<T> diag_vec();

          // Access the individual elements                                                                                                                                                                                               
        T& operator()(const unsigned& row, const unsigned& col);
        const T& operator()(const unsigned& row, const unsigned& col) const;

        // Access the row and column sizes                                                                                                                                                                                              
        unsigned get_rows() const;
        unsigned get_cols() const;

};
#include "matrix.cpp"
#endif