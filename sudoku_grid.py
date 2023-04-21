import numpy as np


class SudokuGrid:
    def __init__(self, grid):
        self.grid = np.array(grid)

    def solve(self):
        print("Original Grid")
        print(self.to_string())

        print("Solved" if self._solve() else "Unsolvable")
        print(self.to_string())

    def _solve(self):
        # find the first empty square
        for row in range(9):
            for col in range(9):
                # if the square is empty
                if self.grid[row][col] == 0:
                    # try each possible value for the square 1-9
                    for possibility in range(1, 10):
                        if self.possible(row, col, possibility):
                            # the value is valid for the square
                            self.grid[row][col] = possibility

                            # recursively solve remaining squares
                            if self._solve():
                                # grid solved
                                return True
                    # none of the values 1-9 are valid
                    # reset the square before backtracking
                    self.grid[row][col] = 0
                    return False
        # grid solved - every square is filled
        return True

    # checks if a value can go in a square
    def possible(self, row, col, value_to_check):
        is_possible = True

        for index_to_check in range(9):
            # validate row and column
            if self.grid[row][index_to_check] == value_to_check or self.grid[index_to_check][col] == value_to_check:
                is_possible = False

            # validate subgrid
            # 1 2 3
            # 4 5 6
            # 7 8 9
            # find index of top left space in the 3x3 subgrid
            top_left_row = row // 3 * 3
            top_left_col = col // 3 * 3

            # compare each value in the subgrid
            for row_offset in range(3):
                for col_offset in range(3):
                    if self.grid[top_left_row + row_offset][top_left_col + col_offset] == value_to_check:
                        is_possible = False

        return is_possible

    # returns a string containing the grid layout
    # -------------------------
    # | - - - | - - - | - - - |
    # | - - - | - - - | - - - |
    # | - - - | - - - | - - - |
    # -------------------------
    # | - - - | - - - | - - - |
    # | - - - | - - - | - - - |
    # | - - - | - - - | - - - |
    # -------------------------
    # | - - - | - - - | - - - |
    # | - - - | - - - | - - - |
    # | - - - | - - - | - - - |
    # -------------------------
    def to_string(self):
        grid_string = ""

        for row in range(9):
            if row == 0 or row == 3 or row == 6:
                grid_string += "-------------------------\n"
            for col in range(9):
                if col == 0 or col == 3 or col == 6:
                    grid_string += "| "
                # use '-' for any box not yet filled
                if self.grid[row][col] == 0:
                    grid_string += "- "
                else:
                    grid_string += str(int(self.grid[row][col])) + " "
            grid_string += "| \n"
        grid_string += "-------------------------\n"

        return grid_string
