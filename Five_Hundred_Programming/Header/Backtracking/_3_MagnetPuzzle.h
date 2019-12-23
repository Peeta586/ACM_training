#ifndef MAGNETPUZZLE_H_
#define MAGNETPUZZLE_H_


#include <iostream>
using namespace std;

/***
 * we are given set of bipolar magnets each domino-shaped. The objectives is to place magnets
 * on a MxN board which should meet a set of conditions where both N and M are not odd.
* 一定条件下， 磁性块不冲突
Here top[], bottom[], left[], right[] arrays indicates the count of + or - along the top(+)
bottom(-), left(+), and right(-) edges respectively. Values of -1 indicates any number of 
+ or - signs (也就是非-1， 则表示要满足在top行，计算每列中+的个数， 其他同理）， 如果为-1，则不进行约束

top[] = {2, -1, -1}
bottom[] = {-1,-1, 2}
left[] = {-1, -1, 2, -1}
right[] = [0, -1, -1, -1]

Rules[][]={
    T T T
    B B B
    T L R
    B L R
}

output:
+ X +
- X -
+ - +
- + -
*/

namespace MagnetPuzzle{

const int M = 4;
const int N = 3;

// A utility function to print solution
void printSolution(char board[M][N]){
    for( int i =0; i < M; i++){
        for(int j =0; j < N; j++){
            cout<< board[i][j]<<" ";
        }
        cout<< endl; 
    }
}

// A utility function to count number of characters ch in current colum
int countInColums(char board[MOD_FREQUENCY][N], char ch, int j){
    int count = 0;
    for(int i =0; i<M; i++){
        if(board[i][j] == ch){
            count++;
        }
    }
    return count;
}


// A utility function to count number of characters ch in current row
int countInRows(char board[M][N], char ch, int i){
    int count = 0;
    for(int j =0; j<N; j++){
        if(board[i][j] == ch){
            count++;
        }
    }
    return count;
}

bool isSafe(char board[M][N], int row, int col, char ch, int top[], 
    int left[], int bottom[], int right[]){
    // check for adjacent cells
    if((row - 1 >= 0 && board[row-1][col] == ch)||
        (col + 1 < N && board[row][col + 1] == ch)||
        (row + 1 < M && board[row+1][col] == ch)||
        (col - 1 >= 0 && board[row][col-1] == ch)){
        return false;
    }

    // count ch in current row
    int rowCount = countInRows(board, ch, row);
    
    // count ch in current column
    int columnCount = countInColums(board, ch, col);

    if(ch == '+'){
        // check top
        if(top[col] != -1 && columnCount >= top[col]){
            return false;
        }
        // check left
        if(left[row] !=-1 && rowCount >= left[row])
            return false;
    }

    if(ch == '-'){
        // check bottom
        if(bottom[col] != -1 && columnCount >= bottom[col]){
            return false;
        }
        // check right
        if(right[row] !=-1 && rowCount >= right[row])
            return false;
    }
    return true;
}

// 停止条件， function to validate configuration of output board
bool validateConfiguration(char board[M][N], int top[], int left[],
    int bottom[], int right[]){
    // check top
    for(int i=0; i < N;i++){
        if(top[i] != -1 && countInColums(board, '+', i) != top[i])
            return false;
    }
    // check left
    for(int j=0; j< M;j++){
        if(left[j] != -1 && countInRows(board, '+', j) != left[j])
            return false;
    }

    // check bottom
    for(int i=0; i < N;i++){
        if(bottom[i] != -1 && countInColums(board, '-', i) != bottom[i])
            return false;
    }
    // check right
    for(int j=0; j< M;j++){
        if(right[j] != -1 && countInRows(board, '-', j) != right[j])
            return false;
    }
    return true;
}

// function to solve the bipolar magnets puzzle
bool solveMagnetPuzzle(char board[M][N], int row, int col, int top[],
    int left[], int bottom[], int right[], char str[M][N]){
    ///*** 注意这个最结尾的判断，因为中间无法判断处全局有效，所以最后一次要判断
    // if we have reached last cell
    if(row >= M -1 && col >= N-1){
        if(validateConfiguration(board, top, left, bottom, right))
            return true;
        return false;
    }

    // if last columm of current row is already processed
    // go to next row, first column
    if(col >= N){
        col =0;
        row = row + 1;
    }

    if(str[row][col]=='R' || str[row][col] =='B'){
        if(solveMagnetPuzzle(board, row, col+1, top, left, bottom, right,str))
            return true;
    }

    // if horizontal slot contains L and R
    if(str[row][col] == 'L' && str[row][col + 1] == 'R'){
        // put (+,-) pair and recur
        if(isSafe(board, row, col, '+', top, left, bottom, right) &&
            isSafe(board, row, col + 1, '-', top, left, bottom, right)){
            board[row][col] = '+';
            board[row][col + 1] = '-';
            if(solveMagnetPuzzle(board, row, col+2, top, left, bottom, right, str))
                return true;
            board[row][col] = 'X';
            board[row][col + 1] = 'X';
        }

        // put (-,+) pair and recur
        if(isSafe(board, row, col, '-', top, left, bottom, right) &&
            isSafe(board, row, col + 1, '+', top, left, bottom, right)){
            board[row][col] = '-';
            board[row][col + 1] = '+';
            if(solveMagnetPuzzle(board, row, col+2, top, left, bottom, right, str))
                return true;
            board[row][col] = 'X';
            board[row][col + 1] = 'X';
        }
    }

    // if horizontal slot contains L and R
    if(str[row][col] == 'T' && str[row+1][col] == 'B'){
        // put (+,-) pair and recur
        if(isSafe(board, row, col, '+', top, left, bottom, right) &&
            isSafe(board, row+1, col, '-', top, left, bottom, right)){
            board[row][col] = '+';
            board[row+1][col] = '-';
            if(solveMagnetPuzzle(board, row, col+1, top, left, bottom, right, str))
                return true;
            board[row][col] = 'X';
            board[row+1][col] = 'X';
        }

        // put (-,+) pair and recur
        if(isSafe(board, row, col, '-', top, left, bottom, right) &&
            isSafe(board, row+1, col, '+', top, left, bottom, right)){
            board[row][col] = '-';
            board[row+1][col] = '+';
            if(solveMagnetPuzzle(board, row, col+1, top, left, bottom, right, str))
                return true;
            board[row][col] = 'X';
            board[row+1][col] = 'X';
        }
    }

    // ignore current cell and recur; 也就是格一个格子放
    if(solveMagnetPuzzle(board, row, col + 1, top, left, bottom, right, str))
        return true;
    
    // if no solution is possible, return false
    return false;
}


void solveMagnetPuzzle(int top[], int left[], int bottom[], int right[], 
    char str[M][N]){
    // to store result
    char board[M][N];

    // initalize all cells by 'X'
    for(int i=0; i < M; i++){
        for(int j =0; j< N; j++){
            board[i][j] ='X';
        }
    }
    if(!solveMagnetPuzzle(board, 0, 0, top, left,bottom,right,str)){
        cout<<"Solution does not exists";
        return;
    }

    // 
    printSolution(board);
}

} // namespace MagnetPuzzle

#endif // !MAGNETPUZZLE_H_