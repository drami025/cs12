//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment09/Topic.cpp 
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

#include <iostream>
#include "Message.h"
#include "Topic.h"
#include "Reply.h"
#include <sstream>

using namespace std;

Topic::Topic()
	: Message()
{}

Topic::Topic(const string &athr, const string &sbjct, const string &body,
			unsigned id)
	: Message(athr, sbjct, body, id)
{}

bool Topic::is_reply() const
{
	return false;
}

string Topic::to_formatted_string() const
{
	stringstream ss;
	
	string all;
	
	ss << "<begin_topic>" << endl;
	ss << ":id: " << id << endl;
	ss << ":subject: " << subject << endl;
	ss << ":from: " << author << endl;
	if(child_list.size() != 0)
	{
		ss << ":children: ";
		for(unsigned i = 0; i < child_list.size(); i++)
		{
			ss << child_list.at(i)->get_id();
			if(i != child_list.size() - 1)
				ss << " ";
		}
		ss << endl;
	}
		
	ss << ":body: " << body << endl;
	ss << "<end>" << endl;
	
	all = ss.str();
	
	return all;
}