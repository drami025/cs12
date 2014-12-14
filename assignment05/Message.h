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

#ifndef MESSAGE_H
#define MESSAGE_H

#include<iostream>
#include<string>

using namespace std;

// Interface for Message class

class Message{
    private:
        string author;
        string subject;
        string body;
        
    public:
        Message();
        Message(const string &athr, const string &sbjct, const string &body);
        void display() const;
};


#endif