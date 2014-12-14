//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment09/BBoard.cpp 
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

#include<fstream>
#include<cstdlib>
#include<iostream>
#include<vector>
#include "BBoard.h"
#include "User.h"
#include "Topic.h"
#include "Reply.h"
#include "Message.h"
#include <sstream>

using namespace std;

// Dashes used as borders between messages
const string DASHES = "-------------------------------------------------------------------------------";

//Default Constructor to create title for the bulletin board.
BBoard::BBoard()
    : title("BBoard of DOOM!!!"), current_user(0)
{}

//Constructor with string parameter to creat a board title determined by user 
//input when a BBoard object is created.
BBoard::BBoard(const string& ttl)
	: title(ttl), current_user(0)
{}

BBoard::~BBoard()
{
	for(unsigned i = 0; i < message_list.size(); i++)
	{
		if(message_list.at(i) != 0)
		{
			delete message_list.at(i);
		}
	}
}
// Accessor function to setup the vector data member "user_list" with a
// list of users and respective passwords from a file
bool BBoard::load_users(const string& userfile)
{
    ifstream inFile;
    string uname, pass;
    
    inFile.open(userfile.c_str());
	if(!inFile.is_open())
	{
		cout << "Error opening file." << endl;
		return false;
	}
    
    inFile >> uname;
    
    while(uname != "end")
    {
        inFile >> pass;
        
        user_list.push_back(User(uname, pass));
        
        inFile >> uname;
    }
    
    inFile.close();
	
	return true;
}
/////////////////////////////////////////////////////FIX ME

bool BBoard::load_messages(const string& datafile)
{
	ifstream inFile;
	ofstream outFile;
	stringstream ss;
	
	inFile.open(datafile.c_str());
	if(!inFile.is_open())
	{
		cout << "Error opening file" << endl;
		return false;
	}
	
	unsigned num_of_messages;
	
	inFile >> num_of_messages;
	
	string skip;
	string author, subject, userName, body, child;
	//char space;
	unsigned id, child_id;
	vector<string> children;
	Message *newTop = 0, *newRep = 0;
	
	while(!inFile.eof())
	{
		inFile >> skip;
	
		if(skip == "<begin_topic>")
		{
			while(skip != "<end>")
			{
				inFile >> skip;
				if(skip == ":id:")
				{
					inFile >> id;
				}
				else if(skip == ":subject:")
				{
					inFile.get();
					getline(inFile, subject);
					//inFile.ignore(256, '\n');
				}
				else if(skip == ":from:")
				{
					inFile >> author;
				}
				else if(skip == ":children:")
				{
					getline(inFile, skip);
					//inFile.ignore(256, '\n');
					children.push_back(skip);
				}
				else if(skip ==":body:")
				{
					body = "";
					inFile.get();
					while(skip != "<end>")
					{
						getline(inFile, skip);
						if(skip != "<end>")
							body += skip;
							
						inFile >> skip;
						
						if(skip != "<end>")
							body += ("\n" + skip);
					}
					
					if(body.size() != 0 && body.at(body.size() -1) == '\n')
					{
						body.erase(body.size() -1);
					}
					child = "0";
					children.push_back(child);
				}
			}

			newTop = new Topic(author, subject, body, id);
			message_list.push_back(newTop);
		}
		else if(skip == "<begin_reply>")
		{
				while(skip != "<end>")
				{
					inFile >> skip;
					if(skip == ":id:")
					{
						inFile >> id;
					}
					else if(skip == ":subject:")
					{
						inFile.get();
						inFile >> skip;
						inFile.get();
						getline(inFile, subject);
						//inFile.ignore(256, '\n');
					}
					else if(skip == ":from:")
					{
						inFile >> author;
					}
					else if(skip == ":children:")
					{
						getline(inFile, skip);
						//inFile.ignore(256, '\n');
						children.push_back(skip);
					}
					else if(skip ==":body:")
					{
						body = "";
						inFile.get();
						while(skip != "<end>")
						{
							getline(inFile, skip);
							if(skip != "<end>")
								body += skip;
							
							inFile >> skip;
							
							if(skip != "<end>")
								body += ("\n" + skip);
						}
						
						if(body.size() != 0 && body.at(body.size() -1) == '\n')
						{
							body.erase(body.size() -1);
						}
						child = "0";
						children.push_back(child);
					}
				}
			
			newRep = new Reply(author, subject, body, id);
			message_list.push_back(newRep);
			
		}
		
	}

	
	for(unsigned i = 0; i < children.size(); i++)
	{
		ss << children.at(i) << endl;
	}
	
	for(unsigned i = 0; i < num_of_messages; i++)
	{
		while(true)
		{
			ss >> child_id;
			if(child_id == 0)
				break;
				
			message_list.at(i)->add_child(message_list.at(child_id - 1));
		}
	}
	
	inFile.close();
	
	return true;
}

bool BBoard::save_messages(const string& datafile)
{
	ofstream outFile;
	
	outFile.open(datafile.c_str());
	
	outFile << message_list.size() << endl;
	
	for(unsigned i = 0; i < message_list.size(); i++)
	{
		outFile << message_list.at(i)->to_formatted_string();
	}
	
	outFile.close();
	
	return true;
}
//////////////////////////////////////////////////////////////////

//Accessor function that creates the login process of the bulletin board. Loops
// if incorrect letter was inputted. Also quits once 'q' or 'Q' is inputted.
void BBoard::login()
{
    string uname, pass;
   	
   	cout << "Welcome to " << title << endl;
   	
    while(current_user == 0)
    {
        cout << "Enter your username (\'Q\' or \'q\' to quit): ";
        cin >> uname;
        
        if(uname == "Q" || uname == "q")
        {
            cout << "Bye!" << endl;
            exit(0);
        }
        cout << "Enter your password: ";
        cin >> pass;
        
        current_user = get_user(uname, pass);
        
        if(current_user == 0)
        {
            cout << "\nInvalid Username or Password!\n" << endl;
        }
    }
    
    cout << "\nWelcome back " << current_user->get_username() << "!" << endl;
    cout << endl;
}

const User * BBoard::get_user(const string &name, const string &pw) const
{
	//Loops runs through the list of existing users.
    for(unsigned i = 0; i < user_list.size(); i++)
    {
        if(user_list.at(i).check(name, pw))
        {
            return &user_list.at(i);
        }
    }
    
    return 0;
}	

// Accessor function where the whole program pretty much takes place. Asks user
//  whether to display messages, add a new message, or quit.
void BBoard::run()
{
    char input;
    
    //Starts the login method.
    //login();

	//Loop for main menu.
    do
    {
        cout << "Menu" << endl;
        cout << "   - Display Messages (\'D\' or \'d\')" << endl;
        cout << "   - Add New Topic (\'N\' or \'n\')" << endl;
		cout << "   - Add Reply (\'R\' or \'r\')" << endl;
        cout << "   - Quit (\'Q\' or \'q\')" << endl;
        cout << "Choose an action: ";
        cin >> input;
        if(input == 'Q' || input == 'q')
        	break;
        
        cin.ignore();	//makes sure to discard newline character from buffer
        cout << endl;
        
        if((input != 'D' && input != 'd') && (input != 'N' && input != 'n') 
            && (input != 'Q' && input != 'q') && (input != 'R' && input != 'r'))
        {
            cout << "\nInvalid action. Please try again.\n" << endl;
            continue; //Continues with next iteration if invalid value put in
        }
        
        
        if(input == 'D' || input == 'd')
        {
            display(); //Runs display method to show all messages
            cout << endl;
        }
        else if(input == 'N' || input == 'n')
        {
            add_topic(); //Runs add_message method to add message
        }
        else if(input == 'R' || input == 'r')
		{
			add_reply();
		}
    } 
    while(input != 'Q' && input != 'q');
    
    cout << "Bye!" << endl;
    return;
}


// Accessor function to display all message objects in the vector
//   data member message_list.
void BBoard::display() const
{
	if(message_list.size() == 0)
	{
		cout << "\nNothing to display.\n";
		return;
	}
	
    for(unsigned i = 0; i < message_list.size(); i++)
	{
		if(!message_list.at(i)->is_reply())
		{
			cout << DASHES << endl;
			message_list.at(i)->print(0);
		}
	}
	cout << DASHES << endl;
}

void BBoard::add_topic()
{
	string temp = "";
	string subject, body, fullBody = "";
	
	cout << "Subject: ";
	getline(cin, subject);
	
	cout << "Body: ";
	while(true)
	{
		getline(cin, body);
		if(body.empty())
		{
			break;
		}
		fullBody += (body + "\n");
	}
	
	Topic *newTop = new Topic(current_user->get_username(),
					subject, fullBody, message_list.size() + 1);
	
	message_list.push_back(newTop);
}

void BBoard::add_reply()
{
	bool correctIndex = false;
	string body, subject, temp = "";
	string fullBody = "";
	int searchIndex;
	
	while(!correctIndex)
	{
		cout << "Enter Message ID (-1 for Menu): ";
		cin >> searchIndex;
		
		if(searchIndex == 0 ||
			searchIndex > static_cast<int>(message_list.size()))
		{
			cout << "Invalid Message ID!!" << endl << endl;
		}
		else
		{	
			correctIndex = true;
		}
	}
	
	if(searchIndex < 0)
	{
		cout << endl;
		return;
	}

	cin.ignore();
	cout << "Enter Body: ";
	while(true)
	{
		getline(cin, body);
		if(body.empty())
		{
			break;
		}
		
		fullBody += (body + "\n");
	}
	
	
	subject = message_list.at(searchIndex - 1)->get_subject();
	
	Reply* userRep = new Reply(current_user->get_username(),
		subject, fullBody, message_list.size() + 1);
		
	message_list.at(searchIndex - 1)->add_child(userRep);
	message_list.push_back(userRep);
}