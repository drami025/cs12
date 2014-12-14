//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment09/Topic.h 
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

#ifndef TOPIC_H
#define TOPIC_H

#include<iostream>
#include "Message.h"
#include "Reply.h"

using namespace std;

class Topic : public Message
{
	public:
		Topic();
		Topic(const string &athr, const string &sbjct, const string &body,
			unsigned id);
		virtual bool is_reply() const;
		virtual string to_formatted_string() const;
};

#endif