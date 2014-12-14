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
#include<cmath>
#include<ctime>

using namespace std;

const int ARR_SIZE = 500;

//Prototypes of the functions used in this program.
double randFloat(double, double);
void setSeq(double arr[], double, double);
double findMean(double arr[], double mean);
double findVar(double arr[], double variance, double mean);

int main()
{
    //Declares arrays and their respective mean and variance variables.
    double arr1[ARR_SIZE], mean1 = 0.0, variance1 = 0.0;
    double arr2[ARR_SIZE], mean2 = 0.0, variance2 = 0.0;
    
    //Initializes both arrays to a sequences of doubles.
    setSeq(arr1, -3.0, 3.0);
    setSeq(arr2, -7.0, -1.0);
    
    //Initializes of the means and variances of both arrays.
    mean1 = findMean(arr1, mean1);
    mean2 = findMean(arr2, mean2);
    variance1 = findVar(arr1, variance1, mean1);
    variance2 = findVar(arr2, variance2, mean2);
    
    cout << 0.0 << " " << mean1 << " " << 3.0 << " " << variance1 << endl;
    cout << -4.0 << " " << mean2 << " " << 3.0 << " " << variance2 << endl;
    
    return 0;
}

//Function returns a random double
double randFloat(double a, double b)
{
    return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

//Function initializes an array to a sequence of random doubles using randFloat
// function.
void setSeq(double arr[], double min, double max)
{
    for(int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = randFloat(min, max);   
    }
}

//Function returns the mean of all the doubles in an array of doubles.
double findMean(double arr[], double mean)
{
    for(int i = 0; i < ARR_SIZE; i++)
    {
        mean += arr[i];
    }
    
    mean /= ARR_SIZE;
    return mean;
}

//Function returns the variance of all the doubles in an array of doubles.
double findVar(double arr[], double variance, double mean)
{
    for(int i = 0; i < ARR_SIZE; i++)
    {
        variance += pow((arr[i] - mean), 2);
    }
    
    variance /= (ARR_SIZE - 1);
    
    return variance;
}