#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// this is sample for testing the sudokuSolver function
int sample[9][9] = {{0, 6, 0, 0, 5, 1, 0, 7, 0},{3, 7, 4, 9, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 2, 0},
{4, 9, 0, 0, 0, 0, 0, 3, 2},{2, 0, 8, 0, 6, 9, 7, 0, 5},{7, 0, 3, 2, 0, 0, 1, 9, 0},
{5, 0, 1, 6, 2, 7, 0, 0, 4},{6, 4, 0, 8, 1, 0, 0, 0, 7},{0, 0, 0, 0, 0, 4, 6, 0, 3}};

// checking whether the postion [r][c] is valid from number n
int sudokuCheck(int board[9][9],int r,int c,int n){
    for (int x = 0; x < 9; x++) {
        if (n == board[r][x] || n == board[x][c]) {
            return 0;
        }
    }
    int bR = floor(r / 3);
    int bC = floor(c / 3);
    for (int R = 0; R < 3; R++) {
        for (int C = 0; C < 3; C++) {
            if (n == board[R + 3 * bR][C + 3 * bC]) {
                return 0;
            }
        }
    }
    return 1;
}
// this function check whether given sudoku is valid or invalid
int validation(int board[9][9],int r,int c) {
    if (r == 9) {
        return 1;
    }
    int n = board[r][c];
    if (n == 0) {
        return validation(board,r + (c == 8), (c + 1) % 9);
    }
    board[r][c] = 0;
    if (sudokuCheck(board,r, c, n)) {
        board[r][c] = n;
        return validation(board,r + (c == 8), (c + 1) % 9);
    }
    board[r][c] = n;
    return 0;
}
// sudoku solver main function
int sudoku(int sample[9][9]){
    int sudokuSolver(int board[9][9],int r, int c) {
        if (r == 9) {
            return 1;
        }
        for (int n = 1; n <= 9; n++) {
            if (board[r][c]) {
                return sudokuSolver(board,r + (c == 8), (c + 1) % 9);
            }
            if (sudokuCheck(board,r, c, n)) {
                board[r][c] = n;
                if (sudokuSolver(board,r + (c == 8), (c + 1) % 9)) {
                    return 1;
                }
                board[r][c] = 0;
            }
        }
        return 0;
    }
    if(validation(sample,0,0)){
        if(sudokuSolver(sample,0,0)){
            for (int r = 0; r < 9; r++) {
                for (int c = 0; c < 9; c++) {
                    printf("%d  ",sample[r][c]);
                    }
                printf("\n");
            }
        return 0;
        }
        printf("unsolvable");
        return 0;
    }
    printf("Invalid sudoku");
    return 0;
    
}
int main(){
    printf("This is just a sample\n");
    sudoku(sample);
}