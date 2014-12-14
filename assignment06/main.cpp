//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment05/main.cpp
/// @brief Assignment 05 for CS 12v Winter 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date February 18, 2014
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
#include"IntVector.h"

using namespace std;

// Test harness for IntVector class
int main()
{
	IntVector myVect1; // Tests first constructor
	IntVector myVect2(5); // Tests second constructor
	IntVector myVect3(6, 4); // Tests third constructor
	
	cout << "Vector 1 size: " << myVect1.size() << endl;
	cout << "Vector 2 size: " << myVect2.size() << endl;
	cout << "Vector 3 size: " << myVect3.size() << endl;
	cout << endl;
	
	cout << "Vector 1 is empty (should be 1): " << myVect1.empty() << endl;
	
	cout << "Vector 3, index 3 (should be 4): " << myVect3.at(3) << endl;
	
	myVect1.push_back(2);
	myVect2.pop_back();
	
	cout << "Vector 1 push back, should have 1 element with value 2: " 
		<< myVect1.size() << " " << myVect1.at(0) << endl;
		
	cout << "Vector 2 pop back [size = 4]: " << myVect2.size() << endl;
	myVect3.at(0) = 100;
	cout << "Vector 3 front [100]: " << myVect3.front() << endl;
	myVect3.back() = 5;
	cout << "Vector 3 back [5]: " << myVect3.back() << endl;
	
	myVect2.assign(6, 17);
	int x = myVect2.at(3);
	
	cout << "Value of x should be 17: " << x << endl;
	cout << "myVect2 should have size 6: " << myVect2.size() << endl;
	
	cout << "myVect1 should have capacity of 1: " << myVect1.capacity() <<endl;
	myVect1.reserve(10);
	cout << "Now capacity 10: " << myVect1.capacity() <<endl;
	myVect1.resize(11);
	cout << "Now capacity 20: " << myVect1.capacity() << endl;
	
	for(unsigned i = 0; i < myVect3.size(); i++)
	{
		cout << myVect3.at(i) << " ";
	}
	cout << endl;
	cout << "Inserting 101 in index 2: ";
	myVect3.insert(2, 101);
	
	for(unsigned i = 0; i < myVect3.size(); i++)
	{
		cout << myVect3.at(i) << " ";
	}
	cout << endl;
	
	cout <<"Erasing index 1: ";
	myVect3.erase(1);
	
	for(unsigned i = 0; i < myVect3.size(); i++)
	{
		cout << myVect3.at(i) << " ";
	}
	cout << endl;
	
	myVect3.clear();
	cout << "Clearing myVect3 [size = 0, cap stays the same]: ";
	cout << myVect3.size() << " " << myVect3.capacity() << endl;
	
	cout << "Assigning new content to myVect3: " << endl;
	
	myVect3.assign(15, 3);
	
	for(unsigned i = 0; i < myVect3.size(); i++)
	{
		cout << myVect3.at(i) << " ";
	}
	cout << endl;
	
	return 0;
}
