//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment01/main.cpp 
/// @brief Assignment 01 for CS 12v Winter 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date January 14, 2014
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 021
/// @par
///     TA: Nkenge Wheatland
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  =============== END ASSESSMENT HEADER ==================

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

//Prototypes for functions used in this program.
double randFloat(double a, double b);
double rand_mv(double mean, double var);

int main()
{
    //Declares the mean and variance used for this program, as well as the 
    // random floating point number.
    double mean, variance;
    double random;
    
    //User inputs mean and variance.
    cout << "Enter Mean: ";
    cin >> mean;
    cout << endl;
    
    cout << "Enter Variance: ";
    cin >> variance;
    cout << endl;
    
    random = rand_mv(mean, variance);
    
    return 0;
}

//Function returns a random double
double randFloat(double a, double b)
{
    return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

//Function returns a random floating point number, but more importantly it
// finds the value of A and B.
double rand_mv(double mean, double var)
{
    double A, B;
    
    B = sqrt(12 * var);
    
    A = (2 * mean - B) / 2;
    B += A;
    
    cout << A << " " << B << endl;
    
    return randFloat(A, B);
}