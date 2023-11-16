#include <stdio.h>
#include <stdbool.h>
#define N 8
void printSolution(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
bool isSafe(char board[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i] == 'Q')
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j] == 'Q')
            return false;
        return true;
}
bool solveNQueens(char board[N][N], int col) {
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 'Q';
            if (solveNQueens(board, col + 1))
                return true;
            board[i][col] = '.';
        }
    }
    return false;
}
int main() {
    char board[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = '.';
    if (solveNQueens(board, 0))
        printSolution(board);
    else
        printf("Solution does not exist.");
    return 0; 
}