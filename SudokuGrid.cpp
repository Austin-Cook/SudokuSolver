//
// Created by austi_eef6ewn on 1/3/2023.
//

#include <iostream>
#include "SudokuGrid.h"

// initialize each value to 0
SudokuGrid::SudokuGrid() {
	for(int row = 0; row < 9; row++) {
		for(int col = 0; col < 9; col++) {
			grid[row][col] = 0;
		}
	}
}

std::string SudokuGrid::toString() {
	std::string gridString = "";
	for(int row = 0; row < 9; row++) {
		if(row == 0 || row == 3 || row == 6) {
			gridString += "-------------------------\n";
		}
		for(int col = 0; col < 9; col++) {
			if(col == 0 || col == 3 || col == 6) {
				gridString += "| ";
			}
			// use '-' for any box not yet filled
			if(grid[row][col] == 0) {
				gridString += "- ";
			} else {
				gridString += std::to_string(grid[row][col]) + " ";
			}
		}
		gridString += "| \n";
	}
	gridString += "-------------------------\n\n";

	return gridString;
}

void SudokuGrid::insertValue(int row, int col, int value) {
	if(row < 0 || row > 8 || col < 0 || col > 8) {
		// invalid grid position
		std::cerr << "Error: Out of bounds, attempted to insert value at (" << row << ", " << col << ")";
	}
	else if(value < 1 || value > 9) {
		// invalid insert value
		std::cerr << "Error: Attempted to insert value \'" << value <<  "\' which is out of range 1-9";
	} else {
		//valid
		grid[row][col] = value;
	}
}

void SudokuGrid::solveGrid() {
	if(solveGridHelper(0, 0, 1)) {
		std::cout << "Success! Here is the solved grid:" << std::endl << toString();
	} else {
		std::cout << "Failure - there is no solution to the grid.";
	}
}

// Recursive function to update grid values according to valid placement
bool SudokuGrid::solveGridHelper(int row, int col, int valueToCheck) {
	// base case - every row has successfully been completed
	if(row > 8) {
		return true;
	} else if(grid[row][col] == 0) {
		if(validateValid(row, col, valueToCheck)) {
			grid[row][col] = valueToCheck;

			// increment row and col to next space in the grid
			int newRow = row;
			int newCol = col;
			if(col < 8) {
				newCol = newCol + 1;
			} else {
				newRow = newRow + 1;
				newCol = 0;
			}

			// recursively check the next space in the grid
			if(!solveGridHelper(newRow, newCol, 1)) {
				grid[row][col] = 0;
				return solveGridHelper(row, col, valueToCheck + 1);
			} else {
				return true;
			}
		} else if(valueToCheck == 9) {
			// all numbers 1-9 have been tried and none could be entered
			return false;
		} else {
			// valueToCheck can't go to the space so try the next number
			return solveGridHelper(row, col, valueToCheck + 1);
		}
	} else {
		// space is filled so move to the next one
		int newRow = row;
		int newCol = col;
		if(col < 8) {
			newCol = newCol + 1;
		} else {
			newRow = newRow + 1;
			newCol = 0;
		}

		// recursively check the next space in the grid
		return solveGridHelper(newRow, newCol, 1);
	}
}

// Checks each value in the same row, column, and subgrid to see if a value can be placed at a grid space
bool SudokuGrid::validateValid(int row, int col, int valueToCheck) {
	bool isValid = true;

	// validate row and column
	for(int indexToCheck = 0; indexToCheck < 9; indexToCheck++) {
		if(grid[row][indexToCheck] == valueToCheck || grid[indexToCheck][col] == valueToCheck) {
			isValid = false;
		}
	}

	/*
	 * validate subgrid
	 * 1 2 3
	 * 4 5 6
	 * 7 8 9
	*/
	// 1) find index of top left space in the 3x3 subgrid
	// FIXME CHANGE THIS TO USE FLOOR DIVISION TO SIMPLIFY CODE
	int topLeftRow = -1;
	int topLeftCol = -1;
	if(row >= 0 && row <= 2) {
		// row 0
		if(col >= 0 && col <= 2) {
			// subgrid 1
			topLeftRow = 0;
			topLeftCol = 0;
		} else if(col >= 3 && col <= 5) {
			// subgrid 2
			topLeftRow = 0;
			topLeftCol = 3;
		} else if(col >= 6 && col <= 8) {
			// subgrid 3
			topLeftRow = 0;
			topLeftCol = 6;
		}
	} else if(row >= 3 && row <= 5) {
		// row 1
		if (col >= 0 && col <= 2) {
			// subgrid 4
			topLeftRow = 3;
			topLeftCol = 0;
		} else if (col >= 3 && col <= 5) {
			// subgrid 5
			topLeftRow = 3;
			topLeftCol = 3;
		} else if (col >= 6 && col <= 8) {
			// subgrid 6
			topLeftRow = 3;
			topLeftCol = 6;
		}
	} else if(row >= 6 && row <= 8) {
		// row 2
		if (col >= 0 && col <= 2) {
			// subgrid 7
			topLeftRow = 6;
			topLeftCol = 0;
		} else if (col >= 3 && col <= 5) {
			// subgrid 8
			topLeftRow = 6;
			topLeftCol = 3;
		} else if (col >= 6 && col <= 8) {
			// subgrid 9
			topLeftRow = 6;
			topLeftCol = 6;
		}
	}

	// 2) compare each value in the subgrid
	for(int rowOffset = 0; rowOffset < 3; rowOffset++) {
		for(int colOffset = 0; colOffset < 3; colOffset++) {
			if(grid[topLeftRow + rowOffset][topLeftCol + colOffset] == valueToCheck) {
				isValid = false;
			}
		}
	}

	return isValid;
}
