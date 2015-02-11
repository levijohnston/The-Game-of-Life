#include "grid.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <time.h>
#include <cstdlib>


using namespace std;

// Function that creates random grid depending on percent density
void grid::randomGrid(char **a, int rows, int columns, float percent)
{
	float random;
	srand (time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			random = ((float)rand() / (float)RAND_MAX);

			// If random number is less than or equal to percet, make the cell alive
			if ((random <= percent)) 
			{
				a[i][j] = 'X';
			}
			// Else cell is dead
			else
			{
				a[i][j] = '-';
			}
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << "*******************************************" << endl;	
};

//Function to check and see if the current valuesx is in the matrix or not
bool grid::inGrid(int a, int b, int rows, int columns)
{
	return ((a >= 0 && a < rows) && (b >= 0 && b < columns));
}

// Function that checks if the current grid or next grid are empty
bool grid::isEmpty(char **a, char **b, int rows, int columns)
{
	bool check = true;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if( a[i][j] == 'X' || b[i][j] == 'X')
			{
				check = false;
			}
		}
	}
	return check;
}		

// Function to determine next generation in classic mode
void grid::nextGeneration(char **a, char **b, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int neighbor = 0;

			//Checks surrounding values and if they are alive, adds a neighbor
			if (!(i == 0 && j == 0) && inGrid(i-1,j-1,rows,columns) && a[i-1][j-1] == alive)
			{
				neighbor++;
			}
			if (!(i == 0 && j == 0) && inGrid(i-1,j,rows,columns) && a[i-1][j] == alive)
			{
				neighbor++;
			}
			if (!(i == 0 && j == 0) && inGrid(i-1,j+1,rows,columns) && a[i-1][j+1] == alive)
			{
				neighbor++;
			}
			if (!(i == 0 && j == 0) && inGrid(i,j-1,rows,columns)&& a[i][j-1] == alive)
			{
				neighbor++;
			}
			if (!(i == 0 && j == 0) && inGrid(i,j+1,rows,columns) && a[i][j+1] == alive)
			{
				neighbor++;
			}
			if (!(i == 0 && j == 0) && inGrid(i+1,j-1,rows,columns) && a[i+1][j-1] == alive)
			{
				neighbor++;
			}
			if (!(i == 0 && j == 0) && inGrid(i+1,j,rows,columns) && a[i+1][j] == alive)
			{
				neighbor++;
			}
			if (!(i == 0 && j == 0) && inGrid(i+1,j+1,rows,columns) && a[i+1][j+1] == alive)
			{
				neighbor++;
			}

			// Set new grid = to old grid
			b[i][j] = a[i][j];
			
			// Determines if new cell is live or dead depending on the amount of neighbors
			if(a[i][j] == dead && neighbor == 2)
			{
				b[i][j] = dead;
			}

			else if(a[i][j] == alive && neighbor <= 1)
			{
				b[i][j] = dead;
			}
			else if((a[i][j] == alive) && (neighbor == 2 || neighbor == 3))
			{
				b[i][j] = alive;
			}
			else if(a[i][j] == alive && neighbor > 3)
			{
				b[i][j] = dead;
			}
			else if(a[i][j] == dead && neighbor == 3)
			{
				b[i][j] = alive;
			}
			cout << b[i][j];
		}	
		cout << endl;		
	}	
	cout<< "*******************************************" << endl;
}

// Function that switches the old grid and the new grid
void grid::switchGrid(char **a, char **b, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}




