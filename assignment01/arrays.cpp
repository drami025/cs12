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

//constants that determine the two sequence sizes.
const int SEQ_ONE = 100;
const int SEQ_TWO = 10000;

//prototypes for functions used in this program.
double randFloat(double, double);
void setSeq(double arr[], int);
double findMean(double arr[], double, int);
double findVar(double arr[], double, double, int);

int main()
{
    //declares the two sequences of size 100 and 10000.
    double arr1[SEQ_ONE], arr2[SEQ_TWO];
    double mean1 = 0.0, variance1 = 0.0;
    double mean2 = 0.0, variance2 = 0.0;
    
    //initializes the sequences' indices to random doubles.
    setSeq(arr1, SEQ_ONE);
    setSeq(arr2, SEQ_TWO);
    
    //finds the means of both sequences.
    mean1 = findMean(arr1, mean1, SEQ_ONE);
    mean2 = findMean(arr2, mean2, SEQ_TWO);
    
    //finds the variances of both sequences.
    variance1 = findVar(arr1, variance1, mean2, SEQ_ONE);
    variance2 = findVar(arr2, variance2, mean2, SEQ_TWO);
    
    cout << 7 << " " << mean1 << " " << 3 << " " << variance1 << endl;
    cout << 7 << " " << mean2 << " " << 3 << " " << variance2 << endl;
    
    return 0;
}

double randFloat(double a, double b)
{
    return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

//function that initializes an array to a sequence of random doubles.
void setSeq(double arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = randFloat(4.0, 10.0);
    }
}

//function that finds the mean of an array of doubles.
double findMean(double arr[], double mean, int size)
{
    for(int i = 0; i < size; i++)
    {
        mean += arr[i];
    }
    
    mean /= size;
    return mean;
}

//function that finds the variance of an array of doubles.
double findVar(double arr[], double variance, double mean, int size)
{
    for(int i = 0; i < size; i++)
    {
        variance += pow((arr[i] - mean), 2);
    }
    
    variance /= (size - 1);
    
    return variance;
}
