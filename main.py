from sudoku_grid import SudokuGrid


TEST_GRID_1 = [
    [0, 0, 0, 2, 6, 0, 7, 0, 1],
    [6, 8, 0, 0, 7, 0, 0, 9, 0],
    [1, 9, 0, 0, 0, 4, 5, 0, 0],
    [8, 2, 0, 1, 0, 0, 0, 4, 0],
    [0, 0, 4, 6, 0, 2, 9, 0, 0],
    [0, 5, 0, 0, 0, 3, 0, 2, 8],
    [0, 0, 9, 3, 0, 0, 0, 7, 4],
    [0, 4, 0, 0, 5, 0, 0, 3, 6],
    [7, 0, 3, 0, 1, 8, 0, 0, 0]
]

TEST_GRID_2 = [
    [1, 0, 0, 4, 8, 9, 0, 0, 6],
    [7, 3, 0, 0, 0, 0, 0, 4, 0],
    [0, 0, 0, 0, 0, 1, 2, 9, 5],
    [0, 0, 7, 1, 2, 0, 6, 0, 0],
    [5, 0, 0, 7, 0, 3, 0, 0, 8],
    [0, 0, 6, 0, 9, 5, 7, 0, 0],
    [9, 1, 4, 6, 0, 0, 0, 0, 0],
    [0, 2, 0, 0, 0, 0, 0, 3, 7],
    [8, 0, 0, 5, 1, 2, 0, 0, 4]
]

TEST_GRID_3 = [
    [0, 0, 2, 0, 0, 3, 0, 0, 8],
    [0, 1, 0, 0, 8, 0, 0, 4, 0],
    [5, 0, 0, 9, 0, 0, 6, 0, 0],
    [3, 0, 0, 1, 0, 0, 5, 0, 0],
    [0, 7, 0, 0, 3, 0, 0, 2, 0],
    [0, 0, 5, 0, 0, 6, 0, 0, 4],
    [0, 0, 7, 0, 0, 4, 0, 0, 1],
    [0, 2, 0, 0, 6, 0, 0, 7, 0],
    [9, 0, 0, 3, 0, 0, 2, 0, 0]
]

TEST_GRID_4 = [
    [0, 4, 0, 0, 0, 3, 0, 0, 0],
    [0, 1, 0, 0, 2, 0, 0, 8, 7],
    [0, 0, 6, 0, 7, 0, 1, 0, 0],
    [9, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 6, 8, 0, 4, 0, 2, 3, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 4],
    [0, 0, 5, 0, 1, 0, 6, 0, 0],
    [1, 8, 0, 0, 9, 0, 0, 2, 0],
    [0, 0, 0, 5, 0, 0, 0, 9, 0]
]


def main():
    grid = SudokuGrid(TEST_GRID_4)
    grid.solve()

if __name__ == '__main__':
    main()