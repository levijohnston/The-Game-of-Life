#ifndef GRID_H
#define GRID_H
#include <iostream>
using namespace std;

class grid
{
	public:
		static const char alive = 'X';
		static const char dead = '-';	
		char **grid;
		char **nextGrid;
		int width;
		int height;

		void randomGrid(char **a, int rows, int columns, float percent);
		void nextGeneration(char **a, char **b, int rows, int columns);
		bool inGrid(int a, int b, int rows,int columns);
		void switchGrid(char **a, char **b, int rows, int columns);
		bool isEmpty(char **a, char **b, int rows, int columns);





};
#endif
