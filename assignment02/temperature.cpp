//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment02/main.cpp 
/// @brief Assignment 02 for CS 12v Winter 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date January 22, 2014
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
#include<iomanip>


using namespace std;

//Constants to determine the size of grid.
const int ROWS = 6, COLUMNS = 8;

//Prototypes for functions used in main.
void setGrid(double grid[][COLUMNS], double, double, double, double);
void updateTemps(double grid[][COLUMNS], double&);
bool isEquil(double, double);

int main()
{
    //Declares objects to be associated with the input and output file.
    ifstream inFile;
    ofstream outFile;
    
    //Creates strings for the user to input name of files.
    //Declares and initializes grid.
    //Declares variables for top, right, bottom, and left temperature.
    //Declares variable for the tolerance and the max difference between
    // a point's former temperature and current temperature.
    string inFileName, outFileName;
    double grid[ROWS][COLUMNS] = {0};
    double top, right, bottom, left, tolerance, maxDif = 0.0;
    bool in_equil = false;

    cout << "Enter the name of your input file: ";
    cin >> inFileName;
    cout << endl;
    cout << "Enter the name of your output file: ";
    cin >> outFileName;
    cout << endl; 
    
    //Opens input and output files by turning the strings of the file names into
    // c-strings.
    inFile.open(inFileName.c_str());
    outFile.open(outFileName.c_str());
    
    if(!inFile.is_open())
    {
        cout << "Could not locate: " << inFileName << endl;
        return 1;
    }
    
    inFile >> top >> right >> bottom >> left >> tolerance;
    
    //Initializes the grid.
    setGrid(grid, top, right, bottom, left);
    
    //Loop the constantly updates the grid until the grid is in termal 
    // equilibrium.
    while(!in_equil)
    {
        updateTemps(grid, maxDif);
        in_equil = isEquil(tolerance, maxDif);
    }
    
    //Outputs the result into output file.
    for(int i = 1; i < ROWS - 1; i++)
    {
        for(int j = 1; j < COLUMNS - 1; j++)
        {
            outFile << setw(10) << grid[i][j] << " ";
        }
        outFile << endl;
    }
    
    //Closes input and output files.
    inFile.close();
    outFile.close();
    
    return 0;
}

//Function sets the grid to the values specified in problem: top row is assigned
// the value of top, right column is assigned value of right, etc.
void setGrid(double grid[][COLUMNS], double top, double right, double bottom,
                double left)
{
    for(int i = 0; i < ROWS; i++)
    {
        //First if is for top row.
        if(i == 0)
        {
            for(int j = 0; j < COLUMNS; j++)
            {
                grid[i][j] = top;
            }
        }
        //Assigns the entire bottom row to value of "bottom"
        else if(i == ROWS - 1)
        {
            for(int j = 0; j < COLUMNS; j++)
            {
                grid[i][j] = bottom;
            }
        }
        //Assigns left and right to left and right columns between top and 
        // bottom rows.
        else
        {
            grid[i][0] = left;
            grid[i][COLUMNS - 1] = right;
        }
    }
}

//Function updates the entire grid by adding the numbers adjacent to a point
// on the grid and taking the average.
void updateTemps(double grid[][COLUMNS], double& maxDif)
{
    //maxDif is assigned to 0.0 every time the grid updates to receive the
    // max difference between the point with the largest difference between
    // its former temp and updated temp.
    double temp;
    maxDif = 0.0;
    
    for(int i = 1; i < ROWS - 1; i++)
    {
        for(int j = 1; j < COLUMNS - 1; j++)
        {
            //Saves former temp to compare with updated temp for maxDif
            temp = grid[i][j];
            
            //Updates temp by taking the average of the 4 adjacent temps
            grid[i][j] = (grid[i][j-1] + grid[i-1][j] + grid[i][j+1] 
                        + grid[i+1][j]) / 4;
            
            //save the greatest maxDif for this update            
            if(grid[i][j] - temp > maxDif)
            {
                maxDif = grid[i][j] - temp;
            }
        }
    }
}

//If maximum difference between a point's former and updated temperature is
// within the tolerance level, function returns true.
bool isEquil(double tolerance, double maxDif)
{
    return (maxDif <= tolerance);
}