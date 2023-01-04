//
// Created by austi_eef6ewn on 1/3/2023.
//

#ifndef SUDOKUSOLVER_SUDOKUGRID_H
#define SUDOKUSOLVER_SUDOKUGRID_H

#include <string>

class SudokuGrid {
private:
	int n = 9;
	int grid[9][9];
public:
	SudokuGrid();
	std::string toString();
	void insertValue(int row, int col, int value);
};


#endif //SUDOKUSOLVER_SUDOKUGRID_H
