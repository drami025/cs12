//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab08/IntList.h
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

using namespace std;

// This struct is used to create the nodes in the linked list. The "next" 
//  pointer points to the next node in the list, and 0 if there is none after.
struct IntNode
{
	int data;
	IntNode *next;
	IntNode(int data) : data(data), next(0) {}
};

// The class for our linked list of integers. Head stores the address of the 
//  first element in the list.
class IntList
{
	private:
		IntNode* head;
		IntNode* tail;
	public:
		IntList();
		~IntList();
		void display() const;
		void push_front(int value);
		void push_back(int value);
		void pop_front();
		void select_sort();
		void insert_sorted(int value);
		void remove_duplicates();
};