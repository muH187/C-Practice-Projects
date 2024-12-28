#include<stdio.h>


int validMove(int sudoku[9][9], int row, int col, int value);
void printSudoku(int sudoku[9][9]);

int sudoku[9][9] = {
    {3,0,0,0,2,0,0,7,0},
    {9,0,0,5,0,0,0,1,4},
    {0,1,6,3,7,0,0,0,8},
    {2,0,0,8,0,0,0,0,1},
    {5,0,0,0,4,1,8,0,0},
    {0,8,9,0,0,0,0,5,0},
    {0,0,5,0,1,0,2,8,0},
    {0,4,0,0,0,6,0,9,3},
    {7,3,1,0,8,2,0,0,0}
};

int main() {

    printf("\n\tWelcome To Sudoku Solver!\n");
    printf("\nOriginal Puzzle.");
    printSudoku(sudoku);

    return 0;
}

int validMove(int sudoku[9][9], int row, int col, int value) {
    // valid row
    for(int i = 0; i < 9; i++) {
        if(sudoku[row][i] == value) {
            return 0;
        }
    }

    // valid column
    for(int i = 0; i < 9; i++) {
        if(sudoku[i][col] == value) {
            return 0;
        }
    }

    // valid square
    int r = row - row % 3;
    int c = col - col % 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(sudoku[r+i][c+j] == value) {
                return 0;
            }
        }
    }

    return 1;
}


void printSudoku(int sudoku[9][9]) {
    printf("\n+-------+-------+-------+\n");
    for(int row = 0; row < 9; row++) {
        if(row % 3 == 0 && row != 0) {
            printf("|-------+-------+-------|\n");
        }
        for(int col = 0; col < 9; col++) {
            if(col % 3 == 0) {
                printf("| "); 
            }
            if(sudoku[row][col] != 0) {
                printf("%d ", sudoku[row][col]);
            } else {
                printf("  "); 
            }
        }
        printf("|\n");
    }
    printf("+-------+-------+-------+");
}