#include<fstream>
#include <iostream>
#include <string>

using namespace std;

//initialize input data var
char maze[200][200];


//initialize the neccessary rows and cols for the maze
int row, col, startrow, startcol, exitrow, exitcol;
bool checkMatrixpath = false;


void printmaze()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << maze[i][j];
		cout << endl;
	}
}

bool checkCoordinateinMatrix(int x, int y)
{
	if (x >= 0 && x < row && y >= 0 && y < col)
		return true;
	else
		return false;
}



void readfile() {
	ifstream inputFile;
	string filename;
	//get filename from user
	cout << "Enter file name:";
	cin >> filename;

	inputFile.open(filename);

	if (inputFile) {

		//start reading the given file in ordered of the line
		//read first line row and col
		inputFile >> row >> col;
		//read 2nd line is entrance
		inputFile >> startrow >> startcol;
		//read 3rd line is exit
		inputFile >> exitrow >> exitcol;
		// read given maze
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				inputFile >> maze[i][j];
	}
	else {
		cout << "NO FILE";
	}

	inputFile.close();
}


void findpath(int x, int y) {

	//if happen to be at the exit , produce the result with the *
	maze[x][y] = '*';

	//start at the coordinate of chosen file from the main
	//condition that meet the exit

	if (x == exitrow && y == exitcol) {
		
		//if happen to be at the exit , produce the result with the *
		printmaze();
		//find the actual path
		checkMatrixpath = true;
		//exit the maze when the path is found
		exit(0);
	}
	else {
		//calculate which direction  to go
		// mark went by path from entrance to the exit with '*'
		//initialize the coordinate of the direction
		int x1 = x - 1, y1 = y; //up
		int x2 = x, y2 = y + 1; //right
		int x3 = x + 1, y3 = y; //down
		int x4 = x, y4 = y - 1; //left

		//apply recursion concept
		//check to see be able to:

		//go up

		if (maze[x1][y1] == '+'
			&& checkCoordinateinMatrix(x1, y1))
			findpath(x1, y1);

		//go down
		if (maze[x2][y2] == '+'
			&& checkCoordinateinMatrix(x2, y2))
			findpath(x2, y2);

		//go right
		if (maze[x3][y3] == '+'
			&& checkCoordinateinMatrix(x3, y3))
			findpath(x3, y3);

		// go left
		if (maze[x4][y4] == '+'
			&& checkCoordinateinMatrix(x4, y4))
			findpath(x4, y4);
	}
	//mark B if not the way to the exit	
	maze[x][y] = 'B';
}


 
int main()
{
	//Read the chosen file
	readfile();
	printmaze();

	cout << endl;

	//Find the path from the chosen file
	findpath(startrow, startcol);

	//print fileread
	if (!checkMatrixpath)
		cout << "NO SOLUTION FOUND." << endl;
	return 0;
}

