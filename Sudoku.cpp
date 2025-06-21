#include <iostream>
using namespace std;

const int N = 9;

bool isValid(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
        if (grid[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num)
            return false;
    }
    return true;
}

bool solveSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid))
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

int main() {
    int grid[N][N] = {
        {5, 1, 7, 6, 0, 0, 0, 3, 4},
        {2, 8, 9, 0, 0, 4, 0, 0, 0},
        {3, 4, 6, 2, 0, 5, 0, 9, 0},
        {6, 0, 2, 0, 0, 0, 0, 1, 0},
        {0, 3, 8, 0, 0, 6, 0, 4, 7},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 9, 0, 0, 0, 0, 0, 7, 8},
        {7, 0, 3, 4, 0, 0, 5, 6, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    if (solveSudoku(grid))
        printGrid(grid);
    else
        cout << "No solution exists.\n";

    return 0;
}