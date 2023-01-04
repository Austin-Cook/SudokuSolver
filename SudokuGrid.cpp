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
