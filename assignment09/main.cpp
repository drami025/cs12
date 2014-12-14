//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment09/main.cpp
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
#include "Message.h"
#include "Topic.h"
#include "User.h"
#include "Reply.h"
#include "BBoard.h"

using namespace std;

int main(int argc, char* argv[])
{
	
	if(argc != 3)
	{
		cout << "ERROR: Invalid program call." << endl
			<< "Usage: <program_name> userfile datafile" << endl;
			
		return 1;
	}
	
	string userfile(argv[1]);
	string datafile(argv[2]);
	
	BBoard bb("CS12 Bulletin Board");
	
	if(!bb.load_users(userfile))
	{
		cout << "ERROR: Cannot load users from " << userfile << endl;
		return 1;
	}
	
	if(!bb.load_messages(datafile))
	{
		cout << "ERROR: Cannot load messages from " << datafile << endl;
		return 1;
	}
	
	
	bb.login();
	bb.run();
	
	if(!bb.save_messages(datafile))
	{
		cout << "ERROR: Cannot save messages to " << datafile << endl;
		return 1;
	}
	
	return 0;	
}
