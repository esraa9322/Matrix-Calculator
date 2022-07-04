//
// Created by Esraa Yazid on 12/05/2021.
//

#ifndef PROBLEM3_MATRIX_H
#define PROBLEM3_MATRIX_H
#include <iostream>
using namespace std;
template <typename T>
class Matrix {
private:
    int rows, columns;
    T** matrix;

public:
    Matrix(); // default constructor
    Matrix(int rows, int columns); // parametrized constructor
    Matrix(const Matrix<T>& mat);  // copy constructor

    //Setters
    void setRows(int rows);
    void setColumns(int columns);


    //Getters
    int getRows() const;
    int getColumns() const;





    Matrix<T> operator+ (Matrix<T> mat); //overloading + operator to add two matrices
    Matrix<T> operator- (Matrix<T> mat); //overloading - operator to subtract two matrices
    Matrix<T> operator* (Matrix<T> mat); //overloading * operator to multiply two matrices
    Matrix<T> transpose();  //method to rotate the matrix

    virtual ~Matrix();        // destructor
   // overloading istream operator to get input from user
    friend inline istream& operator>>(istream& is, Matrix<T>& matrix1) {

        matrix1.matrix=new T* [matrix1.rows];
        for (int i = 0; i < matrix1.rows; i++)
            matrix1.matrix[i] = new T[matrix1.columns];

        for (int i = 0; i < matrix1.rows; i++) {
            for (int j = 0; j < matrix1.columns; j++) {
               is >> matrix1.matrix[i][j];

            }
        }
        return is;
    }
    //overloading output stream operator to print output
    friend inline ostream& operator<<(ostream& os, const Matrix<T>& matrix1) {
        for (int i = 0; i < matrix1.rows; i++) {
            for (int j = 0; j < matrix1.columns; j++) {
                os << matrix1.matrix[i][j];
                os << " ";
            }
            os << '\n';
        }
        return os;
    }
};


template <typename T>
Matrix<T>::Matrix() : Matrix<T>(0, 0) { } //setting default values of rows and columns to 0 and 0

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& mat) {
    rows = mat.rows;
    columns = mat.columns;
    matrix = new T * [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new T [columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = mat.matrix[i][j];
        }
    }

}
template<typename T>
Matrix<T>::Matrix(int row, int column) {
    rows = row;
    columns = column;
    matrix = new T * [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new T[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 0;
        }

    }
}

template<typename T>
int Matrix<T>::getRows() const {
    return rows;
}

template<typename T>
int Matrix<T>::getColumns() const {
    return columns;
}

template<typename T>
void Matrix<T>::setRows(int rows) {
    Matrix::rows = rows;
}

template<typename T>
void Matrix<T>::setColumns(int columns) {
    Matrix::columns = columns;
}


template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T>mat) {

    Matrix SummationMatrix(rows, columns);
    SummationMatrix.matrix=new T* [SummationMatrix.rows];
    for (int i = 0; i < SummationMatrix.rows; i++)
        SummationMatrix.matrix[i] = new T[SummationMatrix.columns];

    for (int i = 0; i < SummationMatrix.rows; i++) {
        for (int j = 0; j < SummationMatrix.columns; j++) {
            SummationMatrix.matrix[i][j] = 0;
        }

    }
     for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                SummationMatrix.matrix[i][j] = matrix[i][j] + mat.matrix[i][j];
            }
        }


    return SummationMatrix;
}

template <typename  T>
Matrix<T> Matrix<T>::operator-(Matrix<T> mat) {
    Matrix SubtractionMatrix(rows, columns);
    SubtractionMatrix.matrix=new T*[SubtractionMatrix.rows];
    for (int i=0 ;i <SubtractionMatrix.rows;i++){
        SubtractionMatrix.matrix[i]=new T[SubtractionMatrix.columns];
    }

    for (int i = 0; i < SubtractionMatrix.rows; i++) {
        for (int j = 0; j < SubtractionMatrix.columns; j++) {
            SubtractionMatrix.matrix[i][j] = 0;
        }
    }


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                //SubtractionMatrix.matrix[i][j] = matrix[i][j] - mat.matrix[i][j];
                SubtractionMatrix.matrix[i][j] = mat.matrix[i][j]-matrix[i][j];
            }
        }



    return SubtractionMatrix;
}

template <typename T >
Matrix<T> Matrix<T>::operator*(Matrix<T> mat) {
    Matrix MultiplicationMatrix(rows, mat.columns);
    MultiplicationMatrix.matrix=new T*[MultiplicationMatrix.columns];
    for(int i =0 ;i<MultiplicationMatrix.columns;i++){
        MultiplicationMatrix.matrix[i]=new T[MultiplicationMatrix.columns];
    }

    for (int i = 0; i < MultiplicationMatrix.rows; i++) {
        for (int j = 0; j < MultiplicationMatrix.columns; j++) {
            MultiplicationMatrix.matrix[i][j] = 0;
        }
    }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                for (int q = 0; q < columns; q++) {

                    MultiplicationMatrix.matrix[i][j] += matrix[i][q] * mat.matrix[q][j];
                }
            }
        }


    return MultiplicationMatrix;
}

template <typename T>
Matrix<T> Matrix<T>::transpose() {
    Matrix TransposeMatrix(columns, rows);
    TransposeMatrix.matrix=new T*[TransposeMatrix.rows];
    for(int i=0 ;i<TransposeMatrix.rows;i++){
        TransposeMatrix.matrix[i]=new T[TransposeMatrix.columns];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            TransposeMatrix.matrix[i][j] = matrix[j][i];
        }
    }

    return TransposeMatrix;
}


template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}




#endif //PROBLEM3_MATRIX_H
