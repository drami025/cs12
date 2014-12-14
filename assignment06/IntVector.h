//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment05/IntVector.h 
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

using namespace std;

// Interface for IntVector class, a simpler version of an STL vector
class IntVector{
	private:
		unsigned sz;
		unsigned cap;
		int *data;
		
	public:
		IntVector();
		~IntVector();
		IntVector(unsigned size);
		IntVector(unsigned size, int value);
		unsigned size() const;
		unsigned capacity() const;
		bool empty()const;
		const int& at(unsigned index) const;
		int& at(unsigned index);
		const int &front() const;
		int& front();
		const int &back() const;
		int& back();
		void expand();
		void expand(unsigned amount);
		void insert(unsigned index, int value);
		void erase(unsigned index);
		void push_back(int value);
		void pop_back();
		void clear();
		void resize(unsigned size);
		void resize(unsigned size, int value);
		void reserve(unsigned n);
		void assign(unsigned n, int value);
};