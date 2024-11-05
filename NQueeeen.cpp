#include <iostream>

using namespace std;

// Check if a queen can be placed at (row, col)
bool isSafe(int board[][4], int row, int col) {
  // Check if there is a queen in the same row
  for (int i = 0; i < col; i++) {
    if (board[row][i] == 1) {
      return false;
    }
  }

  // Check if there is a queen in the same diagonal
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 1) {
      return false;
    }
  }

  for (int i = row, j = col; i < 4 && j >= 0; i++, j--) {
    if (board[i][j] == 1) {
      return false;
    }
  }

  // If there is no queen in the same row or diagonal, then the
  // position is safe
  return true;
}

// Solve the N-queens problem using backtracking
void solveNQueens(int board[][4], int col) {
  // If all queens are placed, then print the solution
  if (col >= 4) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;

  }

  // Try placing a queen in each row
  for (int i = 0; i < 4; i++) {
    // If the position is safe, then place the queen
    if (isSafe(board, i, col)) {
      board[i][col] = 1;

      // Solve the N-queens problem for the next column
      solveNQueens(board, col + 1);

      // Backtrack if the N-queens problem cannot be solved for
      // the next column
      board[i][col] = 0;
    }
  }
}

// Driver program
int main() {
  int board[4][4] = {0};

  solveNQueens(board, 0);

  return 0;
}