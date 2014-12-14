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

#include<fstream>
#include<cstdlib>
#include<iostream>
#include<vector>
#include "BBoard.h"
#include "User.h"

using namespace std;

// Dashes used as borders between messages
const string DASHES = "-----------------------------------------------";

//Default Constructor to create title for the bulletin board.
BBoard::BBoard()
    : title("BBoard of DOOM!!!")
{}

//Constructor with string parameter to creat a board title determined by user 
//input when a BBoard object is created.
BBoard::BBoard(const string& ttl)
{
    title = ttl;
}

// Accessor function to setup the vector data member "user_list" with a
// list of users and respective passwords from a file
void BBoard::setup(const string& input_file)
{
    ifstream inFile;
    string uname, pass;
    
    inFile.open(input_file.c_str());
    
    inFile >> uname;
    
    while(uname != "end")
    {
        inFile >> pass;
        
        user_list.push_back(User(uname, pass));
        
        inFile >> uname;
    }
    
    inFile.close();
}

//Accessor function that creates the login process of the bulletin board. Loops
// if incorrect letter was inputted. Also quits once 'q' or 'Q' is inputted.
void BBoard::login()
{
    string uname, pass;
    bool found = false;	
    while(!found)
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
        
        found = user_exists(uname, pass);
        
        if(!found)
        {
            cout << "Invalid Username or Password!\n" << endl;
        }
    }
    
    // Assigns current_user to the User pass in through login iff the password
    //  and username match somewhere in the list of valid usernames and pass's.
    current_user = User(uname, pass);
    
    cout << "\nWelcome back " << current_user.get_username() << "!" << endl;
}

// Accessor function where the whole program pretty much takes place. Asks user
//  whether to display messages, add a new message, or quit.
void BBoard::run()
{
    char input;
    
    cout << "Welcome to " << title << endl;
    
    //Starts the login method.
    login();

	//Loop for main menu.
    do
    {
        cout << "\nMenu" << endl;
        cout << "   - Display Messages (\'D\' or \'d\')" << endl;
        cout << "   - Add New Message (\'N\' or \'n\')" << endl;
        cout << "   - Quit (\'Q\' or \'q\')" << endl;
        cout << "Choose an action: ";
        cin >> input;
        cin.ignore();	//makes sure to discard newline character from buffer
        cout << endl;
        
        if((input != 'D' && input != 'd') && (input != 'N' && input != 'n') 
            && (input != 'Q' && input != 'q'))
        {
            cout << "\nInvalid action. Please try again.\n" << endl;
            continue; //Continues with next iteration if invalid value put in
        }
        
        
        if(input == 'D' || input == 'd')
        {
            display(); //Runs display method to show all messages
        }
        else if(input == 'N' || input == 'n')
        {
            add_message(); //Runs add_message method to add message
        }
        
    } 
    while(input != 'Q' && input != 'q');
    
    cout << "Bye!" << endl;
    exit(0);
}

// Accessor function to determine whether a username and respective password
//    exists in the file.
bool BBoard::user_exists(const string &name, const string &pass) const
{
	//Loops runs through the list of existing users.
    for(unsigned i = 0; i < user_list.size(); i++)
    {
        if(user_list.at(i).check(name, pass))
        {
            return true;
            break;
        }
    }
    
    return false;
}

// Accessor function to display all message objects in the vector
//   data member message_list.
void BBoard::display() const
{
    if(message_list.size() == 0)
    {
        cout << "\nNothing to Display.\n" << endl;
        return;
    }
    cout << DASHES << endl;
    for(unsigned i = 0; i < message_list.size(); i++)
    {
        cout << "Message #" << i + 1 << ": ";
        message_list.at(i).display();
        cout << DASHES << endl;
    }
}

// Accessor function to add a new Message object to the vector data member
//   message_list
void BBoard::add_message()
{
    string subject, message;
    string temp;
    
    cout << "\nEnter Subject: ";
    getline(cin, subject); // Gets the full subject line inputted by user
    cout << "Enter Body: ";
    getline(cin, message); // Gets the full message inputted by user
    
    //Pushes back a new Message object in the message_list vector.
    message_list.push_back(Message(current_user.get_username(),
                            subject, message));
    
    cout << "Message Recorded!" << endl;
    
}