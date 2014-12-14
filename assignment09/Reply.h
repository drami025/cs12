//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment09/Reply.h 
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

#ifndef REPLY_H
#define REPLY_H

#include "Message.h"
#include "Topic.h"

using namespace std;

class Reply : public Message
{
	public:
		Reply();
		Reply(const string& athr,
			  const string& sbjct,
			  const string& body,
			  unsigned id);
		virtual bool is_reply() const;
		virtual string to_formatted_string() const;
};

#endif