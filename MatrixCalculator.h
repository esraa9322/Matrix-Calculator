//
// Created by Esraa Yazid on 12/05/2021.
//
#include"Matrix.h"
#ifndef PROBLEM3_MATRIXCALCULATOR_H
#define PROBLEM3_MATRIXCALCULATOR_H




    class MatrixCalculator {
    public:
        MatrixCalculator(); //default constructor

        virtual ~MatrixCalculator();  // destructor
        template <typename T>
        void performMatrixCalculations(Matrix<T> &matrix); // method to perform the required calculations on the matrices

    };

    template<typename T>
    void MatrixCalculator::performMatrixCalculations(Matrix<T> &matrix2) {
        int r,col,r1,col1;
        Matrix<T> matrix1(r,col), matrix3(r1,col1);
        cout << "Welcome to FCAI Matrix calculator" << endl;
        cout << "---------------------------------------" << endl;
        int choice,secondChoice;
        cout
                << "1.perform Matrix Addition \n2.perform Matrix Subtraction \n3.perform Matrix Multiplication \n4.Matrix Transpose" //showing the main menu
                << endl;
        cin >> choice;
        bool checkChoice = true;
        while (true) {
            if (choice == 1) {//user chose to add 2 matrices
                cout << "Enter number of rows and columns for the first matrix" << endl;
                //int r, col, r1, col1;
                cin >> r >> col;
                cout << "enter number of rows and columns for the second matrix" << endl;
                cin >> r1 >> col1;
                //after getting the num of rows and columns for both matrices we check them
                // if they are equal opertaion will be done
                if (r == r1 && col == col1) {
                    cout << "Enter elements of the first matrix" << endl;
                    matrix2.setRows(r);
                    matrix2.setColumns(col);
                    cin >> matrix2;

                    cout << "Enter elements of second matrix" << endl;
                    matrix3.setRows(r1);
                    matrix3.setColumns(col1);
                    cin >> matrix3;
                    cout << matrix3 + matrix2;
                } else {// if num of rows and columns for both matrices is not equal the operation won't be performed
                    cout << "Operation can't be done due to invalid number of rows and columns" << endl;
                    cout << "1.Try again\n2.Exit" << endl;
                    cin >> secondChoice;
                    if (secondChoice == 1) {
                        continue;
                    } else {
                        break;
                    }
                }
                break;
            } else if (choice == 2) {// the user chose to subtract 2 matrices
                cout << "Enter number of rows and columns for the first matrix" << endl;
                //int r, col, r1, col1;
                cin >> r >> col;
                cout << "Enter number of rows and columns for the second matrix" << endl;
                cin >> r1 >> col1;
                // number of rows and columns for both of them is checked
                if (r == r1 && col == col1) {//if they are equal the operation will be performed
                    cout << "Enter elements of the first matrix" << endl;
                    matrix2.setRows(r);
                    matrix2.setColumns(col);
                    cin >> matrix2;
                    cout << "Enter elements of second matrix" << endl;
                    matrix3.setRows(r);
                    matrix3.setColumns(col);
                    cin >> matrix3;

                    cout << matrix3 - matrix2;
                } else {// if they are not , operation wo't be done
                    cout << "Operation can't be done due to invalid number of rows and columns" << endl;
                    cout << "1.Try again\n2.Exit" << endl;
                    cin >> secondChoice;
                    if (secondChoice == 1) {
                        continue;
                    } else {
                        break;
                    }
                }
                break;



            }
            else if (choice == 3) {//user chose to multiply 2 matrices
                cout << "Enter number of rows and columns for the first matrix " << endl;
                //int r , col,r1,col1;
                cin>> r >> col;
                cout <<"Enter number of rows and columns for the second matrix" <<endl;
                cin>>r1>>col1;
                // check if number of columns of the first matrix is equal to number of rows of the second matrix
                 if (col !=r1){// if they are not opertion won't be done and the user will be given 2 options

                         cout << "Operation can't be done due to invalid number of rows and columns" << endl;
                         cout << "1.Try again\n2.Exit" << endl;
                         cin >> secondChoice;
                         if (secondChoice == 1) {
                             continue;
                         } else {
                             break;
                         }
                     }



                 else { // if they are equal operation will be performed


                     cout << "Enter elements of the first matrix" << endl;
                     matrix2.setRows(r);
                     matrix2.setColumns(col);
                     cin >> matrix2;
                     cout << "Enter elements of second matrix" << endl;
                     matrix3.setRows(r1);
                     matrix3.setColumns(col1);
                     cin >> matrix3;

                     cout << matrix2 * matrix3;
                 }

                break;
            }
            else if (choice == 4) {//user chose to transpose the matrix
                cout <<"Enter number of rows and columns" << endl;
                cin >> r >>col;
                 matrix1.setRows(r);
                matrix1.setColumns(col);
                cout << "Enter the data of the matrix you wanna transpose" << endl;
                cin >> matrix1;


                cout << matrix1.transpose();
                break;
            }
            else {//user chose invalid number from the main menu

                cout << "Invalid input" << endl;

                break;



            }

        }
    }




#endif //PROBLEM3_MATRIXCALCULATOR_H
