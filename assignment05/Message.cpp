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

#include "Message.h"

using namespace std;


// Constructor creates a new Message object with all data members initialized
//  to the empty string.
Message::Message()
    : author(""), subject(""), body("")
{}

// Constructor creates a new Message object with data members author, subject,
//  body initialized to athr, sbjct, and body respectively
Message::Message(const string &athr, const string &sbjct, const string &body)
    : author(athr), subject(sbjct), body(body)
{}

// Accessor function outputs all Message object's datamembers in a bulletin
//  board format
void Message::display() const
{
    cout << subject << endl;
    cout << "from " << author << ": " << body << endl;
}