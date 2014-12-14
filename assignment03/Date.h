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

#include<string>
#include<iostream>

using namespace std;

// Declaration of Date class
class Date
{
    private:
        unsigned day;
        unsigned month;
        string monthName;
        unsigned year;
        
        // Tests for leap year
        bool isLeap(unsigned) const;
        
        // Returns number of days allowed in a given month
        unsigned daysPerMonth(unsigned m, unsigned y) const;
        
        // Returns the name of a given month
        string name(unsigned m) const;
        
        // Returns the number of a given named month
        unsigned number(const string& mn) const;
        
    public:
        Date();     //Default constructor: creates the date January 1st, 2000
        
        // Parameterized constructor: month number, day, year - e.g. (3,1,2010)
        //  would construct the date March 1st, 2010
        Date(unsigned m, unsigned d, unsigned y); 
        
        // Parameterized constructor: month name, day, year - e.g. (December, 
        //   15, 2012) would construct the date December 15th, 2012
        Date(const string& mn, unsigned d, unsigned y);
        
        // const accessor function to output a Date exactly in the format
        //    "3/1/2012"
        void printNumeric() const;
        
        // const accessor function to output a Date exactly in the forma
        //      "March 1, 2012"
        void printAlpha() const;
        
        Date addDays(int) const;
};

