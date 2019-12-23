#ifndef PRINTKNIGHTOURS_H_
#define PRINTKNIGHTOURS_H_


#include <iostream>
#include <cstring>

using namespace std;

/** 回溯的思想很简单，递归前记录，而在递归退出后回复递归前的值就行。
 * Given a chess board, print all sequences of moves of a knight on a chessboard such that
 * the knight visits every square only once.
 * 
 * 棋盘是国际象棋，分黑白间隔的格子组成，而每个棋手只能选择一个颜色的格子走。
 * 而每个位置走向下一个位置的可能性(四周8个方向的走向)，我们编辑处行动数组，
 * row[] = [2, 1, -1, -2, -2, -1, 1, 2, 2]
 * col[] = [1, 2, 2, 1, -1, -2, -2, -1, 1]
 * 
 * (x,y)的有效移动：
 * (x + 2, y + 1)<br>
(x + 1, y + 2)<br>
(x – 1, y + 2)<br>
(x – 2, y + 1)<br>
(x – 2, y – 1)<br>
(x – 1, y – 2)<br>
(x + 1, y – 2)<br>
(x + 2, y – 1)
 * Notes: Please avoid changing sequence of above arrays. the order in which the knight
 * will move is circular and will be optimum. Using above order, we will get to a vacant
 * position in few moves. Also, it is always better to start backtracking from any corner
 * of chessboard. If we start from somewhere middle, the knight can go to 8 different directions
 * If we start from corner, the knight can go to only two points from there. since the algorithm
 * is exponential, optimized input to it can make huge difference.
 * 
 */

namespace AllKnightTours{

// N x N chessboard
const int  N = 5;

// below arrays details all 8 possible movements for a knight
// it is important to avoid changing sequence of below arrays
int row[] = {2, 1, -1, -2, -2, -1, 1, 2, 2};
int col[] = {1, 2, 2, 1, -1, -2, -2, -1, 1};

// check if (x,y) is valid chess board coordinates
bool isValid(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N){
        return false;
    }
    return true;
}

// Recursive function to perform the knight's tour using backtracking
void KnightTour(int visited[N][N], int x, int y, int pos){
    // mark current square as visited
    visited[x][y] = pos;

    // if all squares are visited, print the solution
    // 也就是当停止条件满足的时候
    if(pos >= N*N){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout<<visited[i][j]<< " ";
            }
            cout<<endl;
        }
        cout<<endl;
        // 记得恢复以前设置，也就是回溯 **********************
        // backtracking before returning
        visited[x][y] = 0;
        return;
    }

    // check for all 8 possible movements for a knight
    // and recur for each valid movement
    for(int k =0; k < 8; k++){
        int newX = x + row[k];
        int newY = y + col[k];

        if(isValid(newX, newY) && !visited[newX][newY]){
            KnightTour(visited, newX, newY, pos + 1);
        }
    }

    // 都走完时，回溯 ******************************************
    // backtracking from current square and remove it from current path
    visited[x][y] = 0;
}

} // namespace AllKnightTours

#endif // !PRINTKNIGHTOURS_H_