//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab08/main.cpp
/// @brief Lab 08 for CS 12v Winter 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date February 26, 2014
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
#include "IntList.h"

using namespace std;

int main()
{
	IntList myList;
	
	myList.push_front(3);
	myList.push_front(4);
	myList.push_front(5);
	
	myList.display();
	cout << endl << endl;
	
	IntList myList2;
	myList2.push_front(9);
	myList2.push_front(8);
	myList2.push_front(7);
	
	myList2.display();
	cout << endl << endl;
	
	myList2.pop_front();
	myList2.pop_front();

	myList2.display();
	cout << endl << endl;
	
	myList2.pop_front();
	
	cout << "Should be nothing here: " << endl;
	myList2.display();
	cout << endl; 
	
	
	IntList myList3;
	myList3.push_back(3);
	myList3.push_back(5);
	myList3.push_back(9);
	myList3.push_back(9);
	myList3.push_back(9);
	myList3.push_back(3);
	myList3.push_back(4);
	myList3.push_back(3);
	myList3.push_back(3);
	
	myList3.remove_duplicates();
	
	myList3.display();
	cout << endl << endl;
	
	myList3.select_sort();
	myList3.display();
	cout << endl << endl;
	
	myList3.insert_sorted(6);
	myList3.display();
	cout << endl << endl;
	
	myList3.insert_sorted(10);
	myList3.display();
	cout << endl << endl;
	
	myList3.insert_sorted(1);
	myList3.display();
	cout << endl << endl;
	
	myList3.insert_sorted(7);
	myList3.insert_sorted(6);
	myList3.display();
	cout << endl << endl;
	return 0;
}
