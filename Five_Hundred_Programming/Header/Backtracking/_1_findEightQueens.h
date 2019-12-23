#ifndef FIND_N_QUEENS_H_
#define FIND_N_QUEENS_H_

/**
 * problem:  Print all possible solutions to N Queens
 * the N queens puzzle is the problem of placing N chess
 * queens on an NxN chessboard so that no two queens
 * threaten each other. thus,a sulution requires that no
 * two queens share the same row, column or diagonal.
 *
 * solution:
 *  we can solve this problem with the help of backtracking.
 * the idea very simple. we start from the first row and place
 * Queen in each square of the first row and recursively explore
 * remaining rows to check if they leads to the solution or not
 * if current configuration doesn't result in a solution
 * we backtrack. before exploring any square, we ignore the square if
 * two queens threaten each other.
 */

#include <iostream>
#include <cstring>

using namespace std;

namespace EightQueens{
const int N  = 8;
char mat[N][N];

// function to check if two queens threaten each other or not
bool isSafe(char mat[][N], int r, int c){
    // return false if the two queens share the same column
    for(int i=0; i < r; i++){
        if(mat[i][c] == 'Q')
            return false;
    }

    // return false if two queens share the same \diagonal
    for(int i =r, j=c; i>=0&& j>=0; i--,j--){
        if(mat[i][j] == 'Q'){
            return false;
        }
    }

    // return false if two queens share the same /diagonal
    for(int i=r,j=c; i>=0&&j<N;i--,j++){
        if(mat[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

bool nQueen(char mat[][N], int r){
    // if N queens are placed successfully, print the solution
    if(r == N){
        for(int i =0; i< N;i++){
            for(int j = 0; j<N;j++){
                cout<< mat[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    // place queen at every square in current row r
    // and recur for each valid movement
    for(int i =0; i < N; i++){
        if(isSafe(mat, r, i)){
            //place
            mat[r][i] = 'Q';

            //recur for next row
            nQueen(mat, r + 1);
            // backtrack and remove queen from current square
            mat[r][i] = '-';
        }
    }
    return true;
}
  
} // namespace EightQueens
#endif // FIND_N_QUEENS_H_
