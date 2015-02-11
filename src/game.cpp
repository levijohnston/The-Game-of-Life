#include "grid.h"
#include "game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

//Function that runs the game
void game::runGame()
{

	//Initializing variables
	int input1;
	int width;
	int height;
	float density;
	grid start;
	char **grid;
	char **nextGrid;
	char **emptyGrid;
	bool delay;
	int i = 1;
	int j = 0;

	cout << "WELCOME TO THE GAME OF LIFE" << endl;
	cout << "Please provide the dimensions: " << endl;
	cout << "Width: " << endl;
	cin >> width;
	cout << "Height: " << endl;
	cin >> height;
	cout << "Please enter the density of the grid (between 0.1 and 1): " << endl;
	cin >> density;
	cout << "Would you like you program to run: " << endl;
	cout << "1. With a brief pause between generations" << endl;
	cout << "2. Press enter to navigate through generations" << endl;
	cin >> input1;


	
	//Create grids to use
	grid = new char *[width];
	for(int i = 0; i <width; i++)
	{
		grid[i] = new char[height];
	}

	nextGrid = new char *[width];
	for(int i = 0; i <width; i++)
	{
		nextGrid[i] = new char[height];
	}

	//Start with random grid
	cout << "Generation: 0" << endl;
	start.randomGrid(grid,width, height,density);
	sleep(1);

	//If user would like delay or not
	if(input1 == 1)
	{
		delay = true;
	}

	if (input1 == 2)
	{
		delay = false;
	}

	//If delay
	if(delay == true)
	{
		while(true)
		{
			//If the grid is not empty
			if (start.isEmpty(grid,nextGrid,width,height) == false)
			{
				cout<< "Generation: " << i << endl;
				start.nextGeneration(grid,nextGrid, width, height);
				start.switchGrid(grid,nextGrid,width,height);
				i++;
				j++;
				sleep(1);
			}
			//If the grid is empty, end the game
			else if(start.isEmpty(grid,nextGrid,width,height) != false) 
			{
				cout << "The game is over!" << endl;
				break;
			}
		}
	}
	//If user presses enter
	if(delay == false)
	{
		while (true)
		{	
			//If the grid is not empty
			if (start.isEmpty(grid,nextGrid,width,height) == false)
			{
				cout<< "Generation: " << i << endl;
				start.nextGeneration(grid,nextGrid, width, height);
				start.switchGrid(grid,nextGrid,width,height);
				i++;
				j++;
				cin.ignore();
			}
			//If the grid is empty, end the game
			else if(start.isEmpty(grid,nextGrid,width,height) != false) {
				cout << "The game is over!" << endl;
				break;
			}	
		}
	}

}
