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
#include<vector>

using namespace std;

#include "Date.h" 

//Default constructor: creates the date January 1st, 2000
Date::Date()
    : day(1), month(1), year(2000), monthName("January")
{}

// Parameterized constructor: month number, day, year - e.g. (3,1,2010)
//  would construct the date March 1st, 2010
Date::Date(unsigned m, unsigned d, unsigned y)
{
    // bool variable keeps track whether date was corrected
    bool wasCorrected = false;
    month = m;
    day = d;
    year = y;
    
    // Conditions for day to be corrected
    if(day >= 32)
    {
        day = daysPerMonth(m, y);
        wasCorrected = true;
    }
    else if(d >= 31 && (m == 4 || m == 6 || m == 9 || m == 11))
    {
        day = daysPerMonth(m, y);
        wasCorrected = true;
    }
    else if((d > 28 && m == 2 && !isLeap(y)) || (d > 29 && m ==2 && isLeap(y)))
    {
        day = daysPerMonth(m, y);
        wasCorrected = true;
    }
    
    // Conditions for month to be corrected
    if(month > 12)
    {
        month = 12;
        wasCorrected = true;
    }
    else if(month < 1)
    {
        month = 1;
        wasCorrected = true;
    }
    
    // If Date was corrected, then output correction
    if(wasCorrected)
    {
        cout << "Invalid data values: Date corrected to ";
        cout << month <<"/" << day << "/" << year << ".\n";
    }
    
    // Assigns monthName data member
    monthName = name(month);
}

// Parameterized constructor: month name, day, year - e.g. (December, 
//   15, 2012) would construct the date December 15th, 2012
Date::Date(const string& mn, unsigned d, unsigned y)
{
    // Keeps track of whether the date was corrected
    bool wasCorrected = true;
    
    // Conditions to make sure mn is a valid month string
    if(mn == "January" || mn == "january")
    {
        wasCorrected = false;
        monthName = mn;
    }
    else if(mn == "February" || mn == "february")
    {
        wasCorrected = false;
        monthName = mn;
    }
    else if(mn == "March" || mn == "march")
    {
        wasCorrected = false;
        monthName = mn;
    }
    else if(mn == "April" || mn == "april")
    {
        wasCorrected = false;
        monthName = mn;
    }
    else if(mn == "May" || mn == "may")
    {
        wasCorrected = false;
        monthName = mn;
    }
    else if(mn == "June" || mn == "june")
    {
        wasCorrected = false;
        monthName = mn;
    }
    else if(mn == "July" || mn == "july")
    {
        wasCorrected = false;
        monthName = mn;
    }
    else if(mn == "August" || mn == "august")
    {
        wasCorrected = false;
        monthName = mn;
    }
    else if(mn == "September" || mn == "september")
    {
        wasCorrected = false;
        monthName = mn;
    }
    else if(mn == "October" || mn == "october")
    {
        wasCorrected = false;
        monthName = mn;
    }
    else if(mn == "November" || mn == "november")
    {
        wasCorrected = false;
        monthName = mn;
    }
    else if(mn == "December" || mn == "december")
    {
        wasCorrected = false;
        monthName = mn;
    }
    
    // If date was corrected, we output a default Date    
    if(wasCorrected)
    {
        cout << "Invalid month name: the Date was set to 1/1/2000" << endl;
        monthName = "January";
        day = 1;
        year = 2000;
        wasCorrected = false;
    }
    
    day = d;
    year = y;
    
    // Conditions for day to be corrected
    if(day >= 32)
    {
        day = daysPerMonth(number(monthName), y);
        wasCorrected = true;
    }
    else if(d >= 31 && (number(monthName) == 4 || number(monthName) == 6 
                    || number(monthName) == 9 || number(monthName) == 11))
    {
        day = daysPerMonth(number(monthName), y);
        wasCorrected = true;
    }
    else if((d > 28 && number(monthName) == 2 && !isLeap(y)) 
            || (d > 29 && number(monthName) == 2 && isLeap(y)))
    {
        day == daysPerMonth(number(monthName), y);
        wasCorrected = true;
    }
    
    // Conditions for year to be corrected

    
    // if day or year was corrected, we output a correction
    if(wasCorrected)
    {
        cout << "Invalid data values: Date corrected to ";
        cout << number(monthName) <<"/" << day << "/" << year << ".\n";
    }
    
    // Assigns number to month data member
    month = number(monthName);
}

// const accessor function to output a Date exactly in the format
//    "3/1/2012"
void Date::printNumeric() const
{
    cout << month << "/" << day << "/" << year;
}

// const accessor function to output a Date exactly in the forma
//      "March 1, 2012"
void Date::printAlpha() const
{

    cout << monthName << " " << day << ", " << year;
}

// Tests for leap year
bool Date::isLeap(unsigned y) const
{
    return (year % 4 == 0 && (year % 400 == 0 || !(year % 100 == 0)));
}

// Returns number of days allowed in a given month
unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
    if(month == 2 && !isLeap(y))
        return 28;
    else if(month == 2 && isLeap(y))
        return 29;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else 
        return 31;
}

// Returns the name of a given month
string Date::name(unsigned m) const
{
    switch(m % 13)
    {
        case 0:
        case 1:
            return "January";
        case 2: 
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
    }   
}

// Returns the number of a given named month
unsigned Date::number(const string& mn) const
{
    if(mn == "January")
        return 1;
    else if(mn == "February")
        return 2;
    else if(mn == "March")
        return 3;
    else if(mn == "April")
        return 4;
    else if(mn == "May")
        return 5;
    else if(mn == "June")
        return 6;
    else if(mn == "July")
        return 7;
    else if(mn == "August")
        return 8;
    else if(mn == "September")
        return 9;
    else if(mn == "October")
        return 10;
    else if(mn == "November")
        return 11;
    else if(mn == "December")
        return 12;
}

Date Date::addDays(int daysPlus) const
{
    Date newDate;
    
    newDate.day = day;
    newDate.month = month;
    newDate.monthName = monthName;
    newDate.year = year;
    while((newDate.month == 2 && !isLeap(newDate.year) && daysPlus > 28) ||
            (newDate.month == 2 && isLeap(newDate.year) 
            && (newDate.day + daysPlus > 29)) || ((newDate.month == 4 
            || newDate.month == 6 || newDate.month == 9
            || newDate.month == 11) && (newDate.day + daysPlus > 30)) ||
            (newDate.month == 12 && (newDate.day + daysPlus > 31)))
    {
        if(newDate.month == 2 && !isLeap(newDate.year) 
            && (newDate.day + daysPlus > 28))
        {
            newDate.month++;
            daysPlus -= 28;
        }
        else if(newDate.month == 2 && isLeap(newDate.year) 
                && (newDate.day + daysPlus > 29))
        {
            newDate.month++;
            daysPlus -= 29;
        }
        else if((newDate.month == 4 || newDate.month == 6 || newDate.month == 9
                || newDate.month == 11) && (newDate.day + daysPlus > 30))
        {
            newDate.month++;
            daysPlus -= 30;
        }
        else if(newDate.month == 12 && (newDate.day + daysPlus > 31))
        {
            newDate.month = 1;
            newDate.year++;
            daysPlus -= 31;
        }
        else if(newDate.day + daysPlus > 31)
        {
            newDate.month++;
            daysPlus -= 31;
        }
    }
    return newDate;
}