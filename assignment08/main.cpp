//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment08/main.cpp
/// @brief assignment 07 for CS 12v Winter 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date March 6, 2014
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
#include<fstream>

using namespace std;

//Prototypes for the functions being called
bool diophantine(int a, int b, int c, int &x, int &y);
int gcd(int a, int b);


int main()
{
	ifstream inFile;			// Creates an input and output stream from file
	ofstream outFile;
	
	string filename, outName;			
	
	cout << "Please enter the name of your file: ";
	cin >> filename;
	cout << "Please enter the name of the output file: ";
	cin >> outName;
	
	// Opens up filename that was inputted by user. Converts to c-string
	inFile.open(filename.c_str());
	if(!inFile.is_open())
	{
		cout << "Couldn't find the file. Terminating program." << endl;
		return 1;
	}
	
	outFile.open(outName.c_str());
	
	int x = 0;
	int y = 0;
	int a = 0, b = 0, c = 0;

	// While the file still has data in it, keep running this file.
	while(!inFile.eof())
	{
		inFile >> a >> b >> c;
		if(diophantine(a, b, c, x, y))
		{
			outFile << x << " " << y << " " << endl;
		}
		else
		{
			outFile << "No Solution! " << endl;
		}
	}
	
	inFile.close();
	outFile.close();
	return 0;
}

// This function determines whether the inputted values have integer solutions
// to the equation ax + by = c.
bool diophantine(int a, int b, int c, int &x, int &y)
{
	// q is the quotient between a and b, r is the remainder, u = q*x + y, and
	// v = x
	int q, r, u, v;	
	bool final = false;
	
	r = a % b;
	q = a / b;
	
	// Uses gcd() function to determine greatest common factor.
	if(c % gcd(a,b) == 0)
	{
		// The next two base cases test for whether a|b or b|a, in which case
		// for the former, x will be 0 and y will be c/b. The latter will make
		// y = 0 and x = c/a.
		if(a % b == 0)
		{
			x = 0;
			y = c/b;
			return true;
		}
		else if(b % a == 0)
		{
			y = 0;
			x = c/a;
			return true;
		}
		else
		{
			// Needs to set the return value of the recursive call to a variable
			// so that we won't forget about reassigning the right values back
			// into x and y. We return the value in total once we exit these
			// nested braches.
			final = diophantine(b, a % b, c, u, v);
			x = v;
			y = u - (a/b) * x;
		}
	}
	
	return final;
}

// This function is created from Euclid's extended algorithm to find the 
// greatest common factor between two numbers. Thank you CS 111!
int gcd(int a, int b)
{
	// In order for this function to work, we need to make sure we deal with
	// the absolute values of a and b. So if one is negative, we make it 
	// positive here.
	if(a < 0)
		a *= -1;
	if(b < 0)
		b *= -1;

	// Once the two values are equal here, then we know the gcd of both values.
	if(a == b)
	{
		return a;
	}
	else
	{
		int temp;
		
		//We need a to be the first parameter in the recursive call so we can
		// constantly subtract b from a.
		if(a < b)
		{
			temp = a;
			a = b;
			b = temp;
		}
		
		// Subtract b from a and call gcd recursively. This will get us the 
		// gcd we are looking for.
		return gcd(a - b, b);
	}
}