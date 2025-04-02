#include <stdio.h>
#include <stdbool.h>

#define MAX 10 // Maximum size for N (can be adjusted)

// Function to print the chessboard
void printBoard(int board[MAX][MAX], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[MAX][MAX], int row, int col, int N)
{
    // Check the column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
        }
        
    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    
    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Function to solve N-Queen problem using backtracking
bool solveNQueens(int board[MAX][MAX], int row, int N)
{
    if (row >= N)
    {
        return true; // All queens are placed
    }
    
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col, N))
        {
            board[row][col] = 1; // Place queen
            if (solveNQueens(board, row + 1, N))
            {
                return true; // Recur to place the next queen
            }
            board[row][col] = 0; // Backtrack if placing queen leads to no solution
        }
    }

    return false; // No valid place for queen in this row
}

int main()
{
    int N;
    printf("\n\t****NISHAN DHAKAL****\n      **** N-Queen Problem ****\n\n");
    printf("Enter the value of N (size of board): ");
    scanf("%d", &N);

    if (N <= 3)
    {
        printf("No solution exists for N = %d\n", N); // No solution for N = 2 or N = 3
        return 0;
    }

    int board[MAX][MAX] = {0}; // Initialize the board with 0s (no queens placed)

    if (solveNQueens(board, 0, N))
    {
        printBoard(board, N);
    }
    else
    {
        printf("Solution does not exist for N = %d\n", N);
    }

    return 0;
}
