#include <iostream>
#include "SudokuGrid.h"

int main() {
	std::cout << "Welcome to Sudoku!" << std::endl << std::endl;

	SudokuGrid myGrid;
	std::cout << myGrid.toString();

	myGrid.insertValue(0,0, 9);
	myGrid.insertValue(4,4, 5);
	myGrid.insertValue(8,8, 1);

	std::cout << myGrid.toString();

	return 0;
}
