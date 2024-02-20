#include<iostream>
#include <windows.h>
#include<time.h>
#include<thread>
using namespace std;
#include"help.h"

void Timer() //displays time.
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int minutes = 0, seconds = 0;
	for (int i = 0; i < 2; i++)   //i<2 because the game runs for 2 minutes.
	{
		seconds = 0;
		for (int j = 0; j < 60; j++)
		{
			Sleep(1000);
			SetConsoleCursorPosition(hConsole, { 0, 0 });
			cout << "Time : " << minutes << " Minutes : " << seconds << " Seconds";
			seconds++;
		}
		minutes++;
	}
}

void PrintouterBoundary()
{   //Prints the outer boundary of the game board.
	myLine(700, 300, 1204, 300, 255, 255, 255);
	myLine(1204, 300, 1204, 804, 255, 255, 255);
	myLine(700, 804, 1204, 804, 255, 255, 255);
	myLine(700, 300, 700, 804, 255, 255, 255);
}

void DrawShape(int id, int x, int y)
{   /*Each shape is drawn in a 40X40 Square.This function takes the top left
	corner of that square and draws the shape according to the id passed.
	There are 5 shapes with 3 variants each.*/
	if (id == 0)  //normal triangle
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myTriangle(x, y, 204, 0, 204, 0);
	}
	else if (id == 1) //normal rectangle
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myRectangle(x, y, x + 40, y + 40, 155, 17, 30, 0);
	}
	else if (id == 2)  // normal circle
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myEllipse(x, y, x + 40, y + 40, 130, 130, 130, 0);
	}
	else if (id == 3) //normal hexagon
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myHexagon(x, y, 80, 200, 120, 0);
	}
	else if (id == 4) //normal diamond
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myDiamond(x, y, 15, 82, 186, 0);
	}
	else if (id == 5) //special triangle
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myTriangle(x, y, 204, 0, 204, 1);
	}
	else if (id == 6) // special rectangle
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myRectangle(x, y, x + 40, y + 40, 155, 17, 30, 1);
	}
	else if (id == 7) // special circle
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myEllipse(x, y, x + 40, y + 40, 130, 130, 130, 1);
	}
	else if (id == 8) // special hexagon
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myHexagon(x, y, 80, 200, 120, 1);
	}
	else if (id == 9) // special diamond
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myDiamond(x, y, 15, 82, 186, 1);
	}
	else if (id == 10) // destroyer triangle
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myTriangle(x, y, 204, 0, 204, 2);
	}
	else if (id == 11) // destroyer rectangle
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myRectangle(x, y, x + 40, y + 40, 155, 17, 30, 2);
	}
	else if (id == 12) //destroyer circle
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myEllipse(x, y, x + 40, y + 40, 130, 130, 130, 2);
	}
	else if (id == 13) //destroyer hexagon
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myHexagon(x, y, 80, 200, 120, 2);
	}
	else if (id == 14) //destroyer diamond
	{
		myRectangle(x - 2, y - 2, x + 42, y + 42, 12, 12, 12, 0);
		myDiamond(x, y, 15, 82, 186, 2);
	}
}

void DropAndAdd(int grid[8][8], int row, int column, int& scoreToAdd)
/*This function takes the coordinates of the shape, destroys it and brings all the shapes
above it one box down and adds a random shape at the top of that column. This function also
adds 100 to the score. This function is called in all the combination checkers.*/
{
	int x = 722 + (60 * column), y = 322 + (60 * row);
	for (int i = row; i > 0; i--)
	{
		myRectangle(x - 1, y - 1, x + 41, y + 41, 12, 12, 12, 0);
		grid[i][column] = grid[i - 1][column];
		DrawShape(grid[i][column], x, y);
		y -= 60;
		Sleep(10);
	}
	y = 322;
	grid[0][column] = rand() % 5;
	myRectangle(x - 1, y - 1, x + 41, y + 41, 12, 12, 12, 0);
	DrawShape(grid[0][column], x, y);
	Sleep(10);
	scoreToAdd += 100;
}

void SpecialGem(int grid[8][8], int row, int col, int& scoreToAdd)
//This function takes the coordinates of the special gem and destroys all the shapes within one box in its surrounding
{
	int rightboundary = col + 1, leftboundary = col - 1, bottomboundary = row + 1, topboundary = 3;
	if (col == 7)
		rightboundary = col;
	if (col == 0)
		leftboundary = col;
	if (row == 7)
	{
		topboundary = 2;
		bottomboundary = row;
	}
	if (row == 0)
		topboundary = 2;
	for (int i = leftboundary; i <= rightboundary; i++)
	{
		for (int j = 0; j < topboundary; j++)
		{
			DropAndAdd(grid, bottomboundary, i, scoreToAdd);
		}
	}
}

void DestroyerGem(int grid[8][8], int row, int col, int& scoreToAdd)
//This function takes the coordinates of the destroyer gem and destroys all the shapes within its row and column.
{
	for (int i = 0; i < 8; i++)
	{
		DropAndAdd(grid, row, i, scoreToAdd);
	}
	for (int i = 0; i < 8; i++)
	{
		DropAndAdd(grid, 7, col, scoreToAdd);
	}
}

void UniqueGemChecker(int grid[8][8], int row, int column, int pattern, int& scoreToAdd)
/*This function takes the row and column of the first shape and pattern of the combination made. Then
checks whether that combination contains a special or a destroyer gem. Then takes action accordingly.*/
{
	if (pattern == 0) // 3 in a row
	{
		if (grid[row][column] > 4 && grid[row][column] < 10)
			SpecialGem(grid, row, column, scoreToAdd);
		else if (grid[row][column] > 9)
			DestroyerGem(grid, row, column, scoreToAdd);
		else if (grid[row][column + 1] > 4 && grid[row][column + 1] < 10)
			SpecialGem(grid, row, column + 1, scoreToAdd);
		else if (grid[row][column + 1] > 9)
			DestroyerGem(grid, row, column + 1, scoreToAdd);
		else if (grid[row][column + 2] > 4 && grid[row][column + 2] < 10)
			SpecialGem(grid, row, column + 2, scoreToAdd);
		else if (grid[row][column + 2] > 9)
			DestroyerGem(grid, row, column + 2, scoreToAdd);
	}
	if (pattern == 1) // 3 in a column
	{
		if (grid[row][column] > 4 && grid[row][column] < 10)
			SpecialGem(grid, row, column, scoreToAdd);
		else if (grid[row][column] > 9)
			DestroyerGem(grid, row, column, scoreToAdd);
		else if (grid[row + 1][column] > 4 && grid[row + 1][column] < 10)
			SpecialGem(grid, row + 1, column, scoreToAdd);
		else if (grid[row + 1][column] > 9)
			DestroyerGem(grid, row + 1, column, scoreToAdd);
		else if (grid[row + 2][column] > 4 && grid[row + 2][column] < 10)
			SpecialGem(grid, row + 2, column, scoreToAdd);
		else if (grid[row + 2][column] > 9)
			DestroyerGem(grid, row + 2, column, scoreToAdd);
	}
	if (pattern == 2) //4 in a row
	{
		if (grid[row][column] > 4 && grid[row][column] < 10)
			SpecialGem(grid, row, column, scoreToAdd);
		else if (grid[row][column] > 9)
			DestroyerGem(grid, row, column, scoreToAdd);
		else if (grid[row][column + 1] > 4 && grid[row][column + 1] < 10)
			SpecialGem(grid, row, column + 1, scoreToAdd);
		else if (grid[row][column + 1] > 9)
			DestroyerGem(grid, row, column + 1, scoreToAdd);
		else if (grid[row][column + 2] > 4 && grid[row][column + 2] < 10)
			SpecialGem(grid, row, column + 2, scoreToAdd);
		else if (grid[row][column + 2] > 9)
			DestroyerGem(grid, row, column + 2, scoreToAdd);
		else if (grid[row][column + 3] > 4 && grid[row][column + 3] < 10)
			SpecialGem(grid, row, column + 3, scoreToAdd);
		else if (grid[row][column + 3] > 9)
			DestroyerGem(grid, row, column + 3, scoreToAdd);
	}
	if (pattern == 3) //4 in a column
	{
		if (grid[row][column] > 4 && grid[row][column] < 10)
			SpecialGem(grid, row, column, scoreToAdd);
		else if (grid[row][column] > 9)
			DestroyerGem(grid, row, column, scoreToAdd);
		else if (grid[row + 1][column] > 4 && grid[row + 1][column] < 10)
			SpecialGem(grid, row + 1, column, scoreToAdd);
		else if (grid[row + 1][column] > 9)
			DestroyerGem(grid, row + 1, column, scoreToAdd);
		else if (grid[row + 2][column] > 4 && grid[row + 2][column] < 10)
			SpecialGem(grid, row + 2, column, scoreToAdd);
		else if (grid[row + 2][column] > 9)
			DestroyerGem(grid, row + 2, column, scoreToAdd);
		else if (grid[row + 3][column] > 4 && grid[row + 3][column] < 10)
			SpecialGem(grid, row + 3, column, scoreToAdd);
		else if (grid[row + 3][column] > 9)
			DestroyerGem(grid, row + 3, column, scoreToAdd);
	}
	if (pattern == 4) // elbow left and up 
	{
		if (grid[row][column - 2] > 4 && grid[row][column - 2] < 10)
			SpecialGem(grid, row, column - 2, scoreToAdd);
		else if (grid[row][column - 1] > 4 && grid[row][column - 1] < 10)
			SpecialGem(grid, row, column - 1, scoreToAdd);
		else if (grid[row][column] > 4 && grid[row][column])
			SpecialGem(grid, row, column, scoreToAdd);
		else if (grid[row - 1][column] > 4 && grid[row - 1][column] < 10)
			SpecialGem(grid, row - 1, column, scoreToAdd);
		else if (grid[row - 2][column] > 4 && grid[row - 2][column] < 10)
			SpecialGem(grid, row - 2, column, scoreToAdd);
		else if (grid[row][column - 2] > 9)
			DestroyerGem(grid, row, column - 2, scoreToAdd);
		else if (grid[row][column - 1] > 9)
			DestroyerGem(grid, row, column - 1, scoreToAdd);
		else if (grid[row][column] > 9)
			DestroyerGem(grid, row, column, scoreToAdd);
		else if (grid[row - 1][column] > 9)
			DestroyerGem(grid, row - 1, column, scoreToAdd);
		else if (grid[row - 2][column] > 9)
			DestroyerGem(grid, row - 2, column, scoreToAdd);
	}
	if (pattern == 5) // elbow right and up 
	{
		if (grid[row][column + 2] > 4 && grid[row][column + 2] < 10)
			SpecialGem(grid, row, column + 2, scoreToAdd);
		else if (grid[row][column + 1] > 4 && grid[row][column + 1] < 10)
			SpecialGem(grid, row, column - 1, scoreToAdd);
		else if (grid[row][column] > 4 && grid[row][column])
			SpecialGem(grid, row, column, scoreToAdd);
		else if (grid[row - 1][column] > 4 && grid[row - 1][column] < 10)
			SpecialGem(grid, row - 1, column, scoreToAdd);
		else if (grid[row - 2][column] > 4 && grid[row - 2][column] < 10)
			SpecialGem(grid, row - 2, column, scoreToAdd);
		else if (grid[row][column + 2] > 9)
			DestroyerGem(grid, row, column + 2, scoreToAdd);
		else if (grid[row][column + 1] > 9)
			DestroyerGem(grid, row, column + 1, scoreToAdd);
		else if (grid[row][column] > 9)
			DestroyerGem(grid, row, column, scoreToAdd);
		else if (grid[row - 1][column] > 9)
			DestroyerGem(grid, row - 1, column, scoreToAdd);
		else if (grid[row - 2][column] > 9)
			DestroyerGem(grid, row - 2, column, scoreToAdd);
	}
	if (pattern == 6) // elbow right and down 
	{
		if (grid[row][column + 2] > 4 && grid[row][column + 2] < 10)
			SpecialGem(grid, row, column + 2, scoreToAdd);
		else if (grid[row][column + 1] > 4 && grid[row][column + 1] < 10)
			SpecialGem(grid, row, column + 1, scoreToAdd);
		else if (grid[row][column] > 4 && grid[row][column])
			SpecialGem(grid, row, column, scoreToAdd);
		else if (grid[row + 1][column] > 4 && grid[row + 1][column] < 10)
			SpecialGem(grid, row + 1, column, scoreToAdd);
		else if (grid[row + 2][column] > 4 && grid[row + 2][column] < 10)
			SpecialGem(grid, row + 2, column, scoreToAdd);
		else if (grid[row][column + 2] > 9)
			DestroyerGem(grid, row, column + 2, scoreToAdd);
		else if (grid[row][column + 1] > 9)
			DestroyerGem(grid, row, column + 1, scoreToAdd);
		else if (grid[row][column] > 9)
			DestroyerGem(grid, row, column, scoreToAdd);
		else if (grid[row + 1][column] > 9)
			DestroyerGem(grid, row + 1, column, scoreToAdd);
		else if (grid[row + 2][column] > 9)
			DestroyerGem(grid, row + 2, column, scoreToAdd);
	}
	if (pattern == 7) // elbow left and down 
	{
		if (grid[row][column - 2] > 4 && grid[row][column - 2] < 10)
			SpecialGem(grid, row, column - 2, scoreToAdd);
		else if (grid[row][column - 1] > 4 && grid[row][column - 1] < 10)
			SpecialGem(grid, row, column - 1, scoreToAdd);
		else if (grid[row][column] > 4 && grid[row][column])
			SpecialGem(grid, row, column, scoreToAdd);
		else if (grid[row + 1][column] > 4 && grid[row + 1][column] < 10)
			SpecialGem(grid, row + 1, column, scoreToAdd);
		else if (grid[row + 2][column] > 4 && grid[row + 2][column] < 10)
			SpecialGem(grid, row + 2, column, scoreToAdd);
		else if (grid[row][column - 2] > 9)
			DestroyerGem(grid, row, column - 2, scoreToAdd);
		else if (grid[row][column - 1] > 9)
			DestroyerGem(grid, row, column - 1, scoreToAdd);
		else if (grid[row][column] > 9)
			DestroyerGem(grid, row, column, scoreToAdd);
		else if (grid[row + 1][column] > 9)
			DestroyerGem(grid, row + 1, column, scoreToAdd);
		else if (grid[row + 2][column] > 9)
			DestroyerGem(grid, row + 2, column, scoreToAdd);
	}
}

bool ElbowChecker(int grid[8][8], int row, int col, int& scoreToAdd)
/* This Functioin takes in the coordinates of the gem and then checks if an elbow can be made where the given gem is the center gem.
If an elbow is detected then it destroys the shapes making the elbow using the DropAndAdd function.
Return true if an elbow is made, otherwise false*/
{
	int originalshape = grid[row][col] % 5;
	if (grid[row][col] % 5 == grid[row][col - 2] % 5 && grid[row][col] % 5 == grid[row][col - 1] % 5 && grid[row][col] % 5 == grid[row - 1][col] % 5 && grid[row][col] % 5 == grid[row - 2][col] % 5 && col > 1 && row > 1)
	{   //elbow left and up
		UniqueGemChecker(grid, row, col, 4, scoreToAdd);
		grid[row][col] = originalshape + 10;
		DrawShape(grid[row][col], 722 + col * 60, 322 + row * 60);
		DropAndAdd(grid, row, col - 2, scoreToAdd);
		DropAndAdd(grid, row, col - 1, scoreToAdd);
		DropAndAdd(grid, row - 1, col, scoreToAdd);
		DropAndAdd(grid, row - 1, col, scoreToAdd);
		return true;
	}
	if (grid[row][col] % 5 == grid[row - 1][col] % 5 && grid[row][col] % 5 == grid[row - 2][col] % 5 && grid[row][col] % 5 == grid[row][col + 1] % 5 && grid[row][col] % 5 == grid[row][col + 2] % 5 && col < 6 && row > 1)
	{   //elbow right and up
		UniqueGemChecker(grid, row, col, 5, scoreToAdd);
		grid[row][col] = originalshape + 10;
		DrawShape(grid[row][col], 722 + col * 60, 322 + row * 60);
		DropAndAdd(grid, row, col + 2, scoreToAdd);
		DropAndAdd(grid, row, col + 1, scoreToAdd);
		DropAndAdd(grid, row - 1, col, scoreToAdd);
		DropAndAdd(grid, row - 1, col, scoreToAdd);

		return true;
	}
	if (grid[row][col] % 5 == grid[row][col + 1] % 5 && grid[row][col] % 5 == grid[row][col + 2] % 5 && grid[row][col] % 5 == grid[row + 1][col] % 5 && grid[row][col] % 5 == grid[row + 2][col] % 5 && col < 6 && row < 6)
	{   //elbow right and down
		UniqueGemChecker(grid, row, col, 6, scoreToAdd);
		grid[row + 2][col] = originalshape + 10;
		DrawShape(grid[row + 2][col], 722 + col * 60, 322 + (row + 2) * 60);
		DropAndAdd(grid, row, col + 2, scoreToAdd);
		DropAndAdd(grid, row, col + 1, scoreToAdd);
		DropAndAdd(grid, row + 1, col, scoreToAdd);
		DropAndAdd(grid, row + 1, col, scoreToAdd);

		return true;
	}
	if (grid[row][col] % 5 == grid[row][col - 2] % 5 && grid[row][col] % 5 == grid[row][col - 1] % 5 && grid[row][col] % 5 == grid[row + 1][col] % 5 && grid[row][col] % 5 == grid[row + 2][col] % 5 && col > 1 && row < 6)
	{   //elbow left and down
		UniqueGemChecker(grid, row, col, 7, scoreToAdd);
		grid[row + 2][col] = originalshape + 10;
		DrawShape(grid[row + 2][col], 722 + col * 60, 322 + (row + 2) * 60);
		DropAndAdd(grid, row, col - 2, scoreToAdd);
		DropAndAdd(grid, row, col - 1, scoreToAdd);
		DropAndAdd(grid, row + 1, col, scoreToAdd);
		DropAndAdd(grid, row + 1, col, scoreToAdd);

		return true;
	}
	return false;
}

bool HorizontalChecker(int grid[8][8], int& scoreToAdd, int row)
/*This function looks for a linear combination of 3 or
4 horizontally in a column and then takes action accordingly using DropAndAdd.
returns true if a combination is made, otherwise returns false.*/
{
	bool check = false;
	for (int j = 0; j < 5; j++)
	{
		if (grid[row][j] % 5 == grid[row][j + 1] % 5 && grid[row][j] % 5 == grid[row][j + 2] % 5 && grid[row][j] % 5 == grid[row][j + 3] % 5) //4 horizontally
		{
			UniqueGemChecker(grid, row, j, 2, scoreToAdd);
			DropAndAdd(grid, row, j, scoreToAdd);
			DropAndAdd(grid, row, j + 1, scoreToAdd);
			DropAndAdd(grid, row, j + 3, scoreToAdd);
			grid[row][j + 2] = grid[row][j + 2] % 5 + 5;
			DrawShape(grid[row][j + 2], 722 + 60 * (j + 2), 322 + 60 * row);
			check = true;
		}
	}
	for (int j = 0; j < 6 && check == false; j++)
	{
		if (grid[row][j] % 5 == grid[row][j + 1] % 5 && grid[row][j] % 5 == grid[row][j + 2] % 5)  // 3 horizontally
		{
			UniqueGemChecker(grid, row, j, 0, scoreToAdd);
			DropAndAdd(grid, row, j, scoreToAdd);
			DropAndAdd(grid, row, j + 1, scoreToAdd);
			DropAndAdd(grid, row, j + 2, scoreToAdd);
			check = true;
		}
	}
	return check;
}

bool VerticalChecker(int grid[8][8], int& scoreToAdd, int column)
/*This function looks for a linear combination of 3 or
4 vertically in a row and takes action accordingly using DropAndAdd.
returns true if a combination is made, otherwise returns false.*/
{
	bool check = false;
	for (int j = 0; j < 5; j++)
	{
		if (grid[j][column] % 5 == grid[j + 1][column] % 5 && grid[j][column] % 5 == grid[j + 2][column] % 5 && grid[j][column] % 5 == grid[j + 3][column] % 5) // 4 vertically
		{
			UniqueGemChecker(grid, j, column, 3, scoreToAdd);
			DropAndAdd(grid, j + 2, column, scoreToAdd);
			DropAndAdd(grid, j + 2, column, scoreToAdd);
			DropAndAdd(grid, j + 2, column, scoreToAdd);
			grid[j + 3][column] = grid[j + 3][column] % 5 + 5;
			DrawShape(grid[j + 3][column], 722 + 60 * column, 322 + 60 * (j + 3));
			check = true;
		}
	}
	for (int j = 0; j < 6 && check == false; j++)
	{

		if (grid[j][column] % 5 == grid[j + 1][column] % 5 && grid[j][column] % 5 == grid[j + 2][column] % 5)  //3 vertically
		{
			UniqueGemChecker(grid, j, column, 1, scoreToAdd);
			DropAndAdd(grid, j + 2, column, scoreToAdd);
			DropAndAdd(grid, j + 2, column, scoreToAdd);
			DropAndAdd(grid, j + 2, column, scoreToAdd);
			check = true;
		}
	}
	return check;
}

void AllPossibleCombo(int grid[8][8], int& scoreToAdd)
/*checks the whole board if any combination can be made*/
{
	bool check1 = true, check2 = true; // check1 is for vertical checking and check2 is for horizontal checking. both are set to true at first so that both orientations are checked at least once
	while (check1 || check2)
	{
		int count = 0;
		for (int i = 7; i >= 0; i--)
		{
			while (check1 == true)  // this while loop keeps checking the same column until there are no combinations possible in that column.
			{
				check1 = VerticalChecker(grid, scoreToAdd, i);
				count++;  // count is incremented every time we have to check a column again
			}
			check1 = true;
			if (count > 8)  // count will be 8 when every column is checked once only which means there were no virtical combos made. if count is greater than 8 then that means a vertical combo was made hence it is possible that a horizontal combination is automatically made so we set check2 to true
				check2 = true;

		}
		check1 = false;
		count = 0;
		for (int j = 7; j >= 0; j--)
		{
			while (check2 == true) // this while loop keeps checking the same row until there are no combinations possible in that row.
			{
				check2 = HorizontalChecker(grid, scoreToAdd, j);
				count++;   // count is incremented every time we have to check a row.
			}
			check2 = true;
			if (count > 8) // count will be 8 when every row is checked once only which means there were no horizontal combos made. if count is greater than 8 then that means a horizontal combo was made hence it is possible that a vertical combination is automatically made so we set check1 to true
				check1 = true;
		}
		check2 = false;
	}
}

void InitialiseBoard(int grid[8][8])
{   /*Prints the game board for the first time and generates random shapes throughout the board.
	It also makes sure that no already made combination is present in the board.*/
	PrintouterBoundary();
	int x, y = 302, id, score = 0;


	for (int i = 0; i < 8; i++)
	{
		x = 702;
		y += 20;
		for (int j = 0; j < 8; j++)
		{
			x += 20;
			id = rand() % 5;
			grid[i][j] = id;
			DrawShape(id, x, y);
			x += 40;
		}
		y += 40;

	}
	AllPossibleCombo(grid, score);
	score = 0;
}

void Cursor(int x, int y, int r, int g, int b)
{   // Draws Cursor
	myLine(x - 10, y - 10, x + 50, y - 10, r, g, b);
	myLine(x + 50, y - 10, x + 50, y + 50, r, g, b);
	myLine(x + 50, y + 50, x - 10, y + 50, r, g, b);
	myLine(x - 10, y + 50, x - 10, y - 10, r, g, b);
}

void GemSwap(int grid[8][8], int row1, int column1, int row2, int column2, int x_coordinate1, int y_coordinate1, int x_coordinate2, int y_coordinate2)
{   //Swaps the gem using the user's input
	swap(grid[row1][column1], grid[row2][column2]);
	DrawShape(grid[row1][column1], x_coordinate1, y_coordinate1);
	DrawShape(grid[row2][column2], x_coordinate2, y_coordinate2);

}

int main()
{
	while (true)
		PrintouterBoundary();
}