//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment09/BBoard.h 
/// @brief Assignment 09 for CS 12v Winter 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date March 16, 2014
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
        const User *current_user;
        vector<Message *> message_list;
        void display() const;
		void add_topic();
		void add_reply();
		const User * get_user(const string &name, const string &pw) const;
        
        
    public:
        BBoard();
        BBoard(const string &ttl);
		~BBoard();
        bool load_users(const string &userfile);
		bool load_messages(const string& datafile);
		bool save_messages(const string& datafile);
        void login();
        void run();
};


#endif 
        