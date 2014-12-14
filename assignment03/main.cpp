//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment03/main.cpp 
/// @brief Assignment 03 for CS 12v Winter 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date January 29, 2014
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
#include<string>
#include<vector>

using namespace std;

// Includes the Date class
#include "Date.h"

// Prototypes for the tests to be displayed
void test1();
void test2();
void test3();
void test4();
void test5();
void myTest1();

int main()
{
    // Execute tests 1 - 5
    test1();
    test2();
    test3();
    test4();
    test5();
    myTest1();
    
    return 0;
}

// test1 tests Default constructor, no parameters
void test1()
{
    cout <<"1. Default" << endl;
    Date x = Date();
    cout << "numeric:\t";
    x.printNumeric(); 
    cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "-------------------------" << endl;
}

// test2 tests for constructor with 3 int parameters
void test2()
{
    cout << "2. Numeric Date: 7.3.1991" << endl;
    Date x = Date(7, 3, 1991);
    cout << "numeric:\t";
    x.printNumeric();
    cout << endl;
    cout <<"alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "--------------------------" << endl;
}

// test3 tests for constructor with string, int, int parameters
void test3()
{
    cout << "3. Alpha Date: July 3, 1991" << endl;
    Date x = Date("July", 3, 1991);
    cout << "numeric:\t";
    x.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "---------------------------" << endl;
}

// test4 tests for an invalid month date
void test4()
{
    cout << "4. Invalid Numeric Date: 0.3.1991 -> 1.3.1991" << endl;
    Date x = Date(0, 3, 1991);
    cout << "numeric:\t";
    x.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "---------------------------" << endl;
}

// test5 tests for invalid monthName date
void test5()
{
    cout << "5. Invalid Alpha Date: 1.adf.1991 -> 1.1.2000" << endl;
    Date x = Date("adf", 1, 1991);
    cout << "numeric:\t";
    x.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "---------------------------" << endl;
}

void myTest1()
{
    cout << "Test for date: 1/31/1848\n\n";
    
    Date x = Date(1, 31, 1848);
    x.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout <<"--------------------------------" << endl;
    
    cout << "Test for date: 12/29/2479\n\n";
    
    Date y = Date(12, 29, 2479);
    y.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    y.printAlpha();
    cout << endl;
    cout << "-----------------------------------" << endl;
    
    
    Date z = Date(1, 31, 2000);
    z.addDays(7);
    cout << endl;
    z.printNumeric();
}