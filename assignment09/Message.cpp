//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment09/Message.cpp 
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

#include<iostream>
#include<sstream>
#include "Message.h"

using namespace std;


// Constructor creates a new Message object with all data members initialized
//  to the empty string.
Message::Message()
    : author(""), subject(""), body(""), id(0)
{}

// Constructor creates a new Message object with data members author, subject,
//  body initialized to athr, sbjct, and body respectively
Message::Message(const string &athr, const string &sbjct, const string &body,
				unsigned id)
    : author(athr), subject(sbjct), body(body), id(id)
{}

Message::~Message()
{}

void Message::print(unsigned indentation) const
{
	string space = "";
	
	string fullBody = body;

	for(unsigned i = 0; i < indentation; i++)
	{
		space += "  ";
	}
	if(is_reply())
	{
		cout << endl;
	}
	cout << space << "Message #" << get_id() << ": " << get_subject() << endl;
	cout << space << "from " << author << ": ";
	for(int i = 0; i < static_cast<int>(fullBody.size()) - 1; i++)
	{
		if(fullBody.at(i) == '\n')
		{
			fullBody.insert(i + 1, space);
		}
	}
	cout << fullBody << endl;
	if(child_list.size() != 0)
	{
		for(unsigned i = 0; i < child_list.size(); i++)
		{
			child_list.at(i)->print(indentation + 1);
		}
	}
}

const string& Message::get_subject() const
{
	return subject;
}

unsigned Message::get_id() const
{
	return id;
}

void Message::add_child(Message *child)
{
	child_list.push_back(child);
}

