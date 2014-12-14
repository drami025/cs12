//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment09/Message.h 
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

#ifndef MESSAGE_H
#define MESSAGE_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Interface for Message class

class Message{
    protected:
        string author;
        string subject;
        string body;
		unsigned id;
		vector<Message *> child_list;
        
    public:
        Message();
        Message(const string &athr, const string &sbjct, const string &body,
        		unsigned id);
		virtual ~Message();
		virtual bool is_reply() const = 0;
		virtual string to_formatted_string() const = 0;
		void print(unsigned indentation) const;
		const string & get_subject() const;
		unsigned get_id() const;
		void add_child(Message *child);
};


#endif