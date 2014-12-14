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


#include <iostream>
#include "User.h"
#include "Message.h"
#include "BBoard.h"

using namespace std;

// Main function takes in command line arguments, the second being a file
//   with a list of existing usernames and their respective passwords
int main(int argc, char* argv[])
{
	
	if(argc != 2)
	{
		cout << "Usage: Main.cpp [input file name]" << endl;
		return 1;
	}
	
	string file = argv[1];
	
	//creates a BBoard object myBoard
	BBoard myBoard;
	
	//Setups the BBoard object to have all usernames and passwords as 
	//   acceptable users.
	myBoard.setup(file);
	
	//Runs the bulletin board
	myBoard.run();
	
    return 0;
}

