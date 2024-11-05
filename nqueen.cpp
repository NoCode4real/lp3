#include<iostream>
using namespace std;

const int N = 8;
int board[N][N] = {0};

void printBoard(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout<<endl;
    }
}

bool isSafe(int row, int col){
    for(int i=0; i<row; i++){
        if(board[i][col] || (col - row + i >=0 && board[i][col - row + i]) || (col + row - i < N && board[i][col + row - i]))
            return false;
    }
    return true;
}

bool solve(int row){
    if(row==N) return true;
    for(int col=0; col<N; col++){
        if(isSafe(row, col)){
            board[row][col] = 1;
            if(solve(row + 1)) return true;
            board[row][col] =0;
        }
    }
    return false;
}

int main(){
    board[0][0] = 1;
    if(solve(1)){printBoard();}
    else{
        cout << "No solution found";
    }
    return 0;
}