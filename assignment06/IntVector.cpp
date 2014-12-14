//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment06/IntVector.cpp
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
#include<cstdlib>
#include"IntVector.h"

using namespace std;

//First constructor initializes sz and cap to 0. Also points the pointer to int
//   data member to address 0.
IntVector::IntVector()
	: sz(0), cap(0), data(0)
{}

IntVector::~IntVector()
{
	delete[] data;
}

// Second constructor initializes sz and cap to 0. Also allocates a new array
//  dynamically of length "size." Initializes all elements of array to 0.
IntVector::IntVector(unsigned size)
	:	sz(size), cap(size), data(new int[size])
{
	for(unsigned i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}

// Second constructor initializes sz and cap to 0. Also allocates a new array
//  dynamically of length "size." Initializes all elements of array to "value."
IntVector::IntVector(unsigned size, int value)
	: sz(size), cap(size), data(new int[size])
{
	for(unsigned i = 0; i < size; i++)
	{
		data[i] = value;
	}
}

// Member function returns the size of the array/vector.
unsigned IntVector::size() const
{
	return sz;
}

// Member function returns the capacity (not size) of the array/vector.
unsigned IntVector::capacity() const
{
	return cap;
}

// Member function returns true if array/vector has no elements(is empty) and
//  false otherwise.
bool IntVector::empty() const
{
	if(sz == 0)
		return true;
	else
		return false;
}

// Returns the value of the "index" of the array.
const int& IntVector::at(unsigned index) const
{
	if(index >= sz)
	{
		exit(1);
	}
	
	return data[index];
}

// This function is used to write to the specified indexed address of the array,
// but it can also be used to return the value at the index of array
int& IntVector::at(unsigned index)
{
	if(index >= sz)
	{
		exit(1);
	}
	
	return data[index];
}

// Member function returns the first element in the vector/array
const int& IntVector::front() const
{
	return data[0];
}

// Member function returns the first element in the vector/array, but it also
// is able to write to the front of the vector as well
int& IntVector::front()
{
	return data[0];
}

// Member function returns the last element in the vector/array
const int& IntVector::back() const
{
	return data[sz - 1];
}

// Member function returns the last element in the vector/array, but can also be
// used to write to the last element of the array
int& IntVector::back()
{
	return data[sz - 1];
}

// Member function double the size of the capacity. Also adds 1 if capacity is
// 0.
void IntVector::expand()
{
	
	int *temp = data;		//assigns address in data to temp
	cap *= 2;
	if(cap == 0)		// Sets cap to 1 if capacity was initially 0.
		cap += 1;
	
	data = new int[cap];	//data now points to new dynamically allocated mem
	
	// Copies all the elements in old array into the new dynamically allocated
	// array.
	for(unsigned i = 0; i < sz; i++)
	{
		data[i] = temp[i];
	}
	
	delete[] temp;	// We deallocate the array data was first pointing to here.
}

// Member function increases the capacity of vector/array by the amount in 
// the parameter.
void IntVector::expand(unsigned amount)
{
	int *temp = data;
	cap += amount;
	
	data = new int[cap];
	for(unsigned i = 0; i < sz; i++)
	{
		data[i] = temp[i];
	}
	
	delete[] temp;
}

// Member function inserts value of parameter into the index. Shift all the 
// elements after it to the right one.
void IntVector::insert(unsigned index, int value)
{
	sz += 1;		// first increases size of vector by 1
	if(sz > cap)
	{
		expand();	// if size is less than cap, we increase cap
	}
	
	if(index >= sz)	// program exits if index is greater than sz
	{
		exit(1);
	}
	
	// This loop moves all values to the right after the newly inserted value.
	// It starts from the end of array and stops at the index parameter.
	for(unsigned i = sz - 1; i > index; i--)
	{
		data[i] = data[i - 1]; 
	}
	
	data[index] = value;
}


// Member function erase an element at the given index. Also reduces size of 
// vector by 1 and left shifts all elements after deleted element.
void IntVector::erase(unsigned index)
{
	if(index >= sz)
	{
		exit(1);
	}
	
	// Loop starts at the index and sets the value of the array after index to
	// the current index.
	for(unsigned i = index; i < sz; i++)
	{
		data[i] = data[i + 1];
	}
	
	sz -= 1;
}

// Appends a new element to the back of the list while also increasing the size
// of the vector.
void IntVector::push_back(int value)
{
	sz += 1;  //adds 1 to the size of vector.
	
	// If size is 1 after sz increases, then we must dynamically allocate a new
	// array for the vector.
	if(sz == 1)
	{
		data = new int[sz];
	}
	// if sz is greater than cap, we must expand capacity of array.
	if(sz > cap)
	{
		expand();
	}
	data[sz - 1] = value;
}

// Reduces the size of the vector by 1. Doesn't need to delete the last element
void IntVector::pop_back()
{
	if(empty())
	{
		exit(1);
	}
	
	sz -= 1;
}

// Sets the size of the vector to 0, essentially making the vector have a size
// of 0. Doesn't necessarily delete the old elements though, but not necessary.
void IntVector::clear()
{
	sz = 0;
}

// Resizes the vector to the given size parameter.
void IntVector::resize(unsigned size)
{
	if(size <= sz)
	{
		sz = size;
	}
	else if(size > sz)
	{
		if(size > cap)
		{
			if(2 * cap <= size - cap)
				expand(size - cap);
			else
				expand();
		}
		
		for(unsigned i = sz; i < size; i++)
		{
			data[i] = 0;
		}
		
		sz = size;
	}
}

// Resizes vector to the given size parameter and initializes all elements to
// the value given.
void IntVector::resize(unsigned size, int value)
{
	if(size <= sz)
	{
		sz = size;
	}
	else if(size > sz)
	{
		if(size > cap)
		{
			if(2 * cap <= size - cap)
				expand(size - cap);
			else
				expand();
		}
		
		for(unsigned i = sz; i < size; i++)
		{
			data[i] = value;
		}
		
		sz = size;
	}
}

// Reserves space for the vector, increasing its capacity to be either double
// the original capacity or the value of parameter n. Only works if n > cap.
void IntVector::reserve(unsigned n)
{
	if(n > cap)
	{
		if (2 * cap < n)
			expand(n - cap);
		else
			expand();
	}
}

// Resizes capacity and size of vector and initializes all elements to value.
void IntVector::assign(unsigned n, int value)
{
	reserve(n);
	
	sz = n;
	for(unsigned i = 0; i < sz; i++)
	{
		data[i] = value;
	}
}