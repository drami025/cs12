//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment03/main.cpp 
/// @brief Assignment 04 for CS 12v Winter 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date February 12, 2014
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

#include "User.h"


using namespace std;


// Default constructor to create an empty string for username and password
User::User()
    : username(""), password("")
{}

// Constructors assigns data members username and password to parameters
User::User(const string& uname, const string& pass)
    : username(uname), password(pass)
{}

// Accessor function returns the username data member of the User object
string User::get_username() const
{
    return username;
}

// Accessor function checks to see whether the parameter uname matches with
//  the username data member, and pass matches with password data member
bool User::check(const string& uname, const string& pass) const
{
    if(uname == "" || pass == "")
        return false;
    
    if(uname == username && pass == password)
        return true;
        
    return false;
}

// Accessor function assigns newpass parameter to password datamember, 
//    essentially creating a new password.
void User::set_password(const string &newpass)
{
    password = newpass;
}

