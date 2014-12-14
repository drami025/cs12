//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab08/IntList.cpp
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

// Constructor creates a linked integer list with head and tail pointing to 0.
IntList::IntList()
	: head(0), tail(0)
{}

// Destructor deallocates dynamically allocated nodes but simply popping back
//   all elements in the list. 
IntList::~IntList()
{
	while(head != 0)
	{
		pop_front();
	}
}

// Member function displays all elements in the linked list. Prints nothing
// when it is empty.
void IntList::display() const
{
	if(head != 0)
	{
		IntNode *temp = head->next;		// temp points to next node after first
		cout << head->data;				// Displays first node in list
		while(temp != 0)			
		{
			cout << " " << temp->data; // Points to next node and prints
			temp = temp->next;			// Temp points to node after temp.
		}
	}
}

// Member function adds a new node to the front of the list.
void IntList::push_front(int value)
{
	// If head doesn't point to address 0, then we make sure we point head to
	//  a new node, but to preserve the address that head was pointing to, we
	// save that address in temp. New list: head -> temp, temp.next-> head[prev]
	if(head != 0)
	{
		IntNode *temp = new IntNode(value);		
		temp->next = head;		
		head = temp;
	}
	else
	{
		head = new IntNode(value); // Creates new node is head was 0
		tail = head;
	}
}

// Member function adds a new node to the end of the list
void IntList::push_back(int value)
{
	// In the case that the list is empty, then head and tail must point to the
	//  same node, which would be the first one.
	if(head == 0)
	{
		head = tail = new IntNode(value);
		return;
	}
	
	// If the list is not empty, then tail must be equal to the last node, but 
	//  before we can point it to the last node, the current node for tail must
	//  point to the new node.
	IntNode *temp = new IntNode(value);
	tail->next = temp;
	tail = temp;
}

// Member function removes the node in the front of the list.
void IntList::pop_front()
{
	// While head doesn't point to address 0, we remove the front node.
	if (head == 0)
		return;
	else if(head != 0)
	{
		IntNode *temp = head->next;
		delete head;
		head = temp;
	}
}

// Member function sorts the list in ascending order but using two nested loops
void IntList::select_sort()
{
	// First loop compares the current index-value to the rest of the list
	for(IntNode *i = head; i != 0; i = i->next)
	{
		int min = i->data;
		// Second loop compares all other indices to the one in the first loop.
		for(IntNode *j = i->next; j != 0; j = j->next)
		{
			// Swaps the index-values if the one at index j is smaller.
			if(j->data < min)
			{
				min = j->data;
				j->data = i->data;
				i->data = min;
			}
		}
	}
}

// Member function inserts a value into the list, assuming the list is sorted.
void IntList::insert_sorted(int value)
{
	// If there is no list, then inserted value goes in the front.
	if(head == 0)
	{
		push_front(value);
	}
	else if(head->next == 0)
	{
		// If there is only one value in the list, then value goes either in
		// the front [push_front] or back [push_back]
		if(head->data >= value)
		{
			push_front(value);
		}
		else
		{
			push_back(value);
		}
	}
	else if(tail->data <= value)
	{
		// If value is greater than value in the back, then we only do push_back
		push_back(value);
	}
	else if(head->data >= value)
	{
		// If value is less then the value in the front, then only do push_front
		push_front(value);
	}
	else 
	{
		// Now, if the value goes between two middle values in the list, we
		// must traverse the list, keeping track of the next value(curr) and
		// current value (prev). If the value is greater than prev->data and
		// less than curr->data, then value must go in between
		IntNode *prev = head, *curr = head->next;
		IntNode *i = 0;
		
		// This loop determines where to put our new value
		for(i = head; !(prev->data <= value && value <= curr->data);
				i = i->next)
		{
			prev = i->next;
			curr = i->next->next;
		}
		
		// Using the index found in loop, we insert value here.
		IntNode *temp = new IntNode(value);
		temp->next = curr;
		prev->next = temp;
	}
}

// Member function removes all duplicate data members in the list.
void IntList::remove_duplicates()
{
	// First loop is to get the number we are comparing the rest of the values
	// in the list to.
	for(IntNode *i = head; i != 0; i = i->next)
	{
		int compare = i->data;
		IntNode *prev = i;
		
		//Second loop traverses the loop to find any duplicates of the compared
		// value.
		for(IntNode *j = i->next; j != 0;)
		{
			// If the compared value equals the data in the node pointed to by
			// j, and so long as the node pointed to by j does not equal 0,
			// we have the prev node point to one after the next node, delete
			// the node pointed to by j, and point j to node pointed to by prev.
			if(compare == j->data && j->next != 0)
			{
				prev->next = j->next;
				delete j;
				j = prev;
			}
			else if(compare == j->data && j == tail)
			{
				// In the case j == to the tail, we meerly set the tail to point
				// to the prev node, delete the tail (which is j at this point)
				// and set the tail node's next to 0;
				tail = prev;
				delete j;
				tail->next = 0;
			}
			
			// In order to make sure we keep comparing the next node after
			// deleting a previous one, if we did delete one we only increment
			// j to point to the next node. Otherwise we increment point prev
			// and j.
			if(j == prev)
			{
				j = j->next;
			}
			else
			{
				j = j->next;
				prev = prev->next;
			}
		}
	}
}