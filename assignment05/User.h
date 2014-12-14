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

#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>

using namespace std;

// User class interface for User objects

class User{
    private:
        string username;
        string password;
        
    public:
        User();
        User(const string& uname, const string& pass);
        string get_username() const;
        bool check(const string &uname, const string &pass) const;
        void set_password(const string &newpass);
};

#endif
