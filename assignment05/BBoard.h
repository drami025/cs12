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

#ifndef BBOARD_H
#define BBOARD_H

#include<iostream>
#include<fstream>
#include<vector>
#include "User.h"
#include "Message.h"

using namespace std;
//This is the interface for the BBoard class

//Class BBoard for the bulletin board
class BBoard{
    private:
        string title;
        vector<User> user_list;
        User current_user;
        vector<Message> message_list;
        //void add_user(istream &infile, const string &name, const string &pass);
        bool user_exists(const string &name, const string &pass) const;
        //User get_user(const string &name) const;
        void display() const;
        void add_message();
        
        
    public:
        BBoard();
        BBoard(const string &ttl);
        void setup(const string &input_file);
        void login();
        void run();
};


#endif 
        