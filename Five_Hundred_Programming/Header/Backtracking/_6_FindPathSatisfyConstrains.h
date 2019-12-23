#ifndef FINDPATHCONSTRAINS_H_
#define FINDPATHCONSTRAINS_H_

#include <iostream>
#include <cstring>
using namespace std;


/**
 * Given a N*N matrix of postive integers, find a path from the first cell of the 
 * matrix to its last cell; 
 * 
 * the constrains:
 * M[ i+ M[i][j]][j] or
 * M[i][j+ M[i][j]] or
 * M[ i- M[i][j]][j] or
 * M[i][j- M[i][j]] 
 * 也就是根据cell的值进行四个方向的跳转；
 * 
 * 注意我们要以每个cell的下一步如果跳转为关注点，然后将当前的值存到一个跟踪list中， 如果跳转结束后
 * 我们再将这个值从list中剔除，达到backtracking模式
 */

namespace findPathConstrains{

const int n = 4;

bool isValid(int x, int y){
    if(x < 0 || y < 0 || x >=n || y >=n){
        return false;
    }
    return true;
}

void countPaths(int maze[n][n], int x, int y, int visited[n][n], int &count){
    // if destination is found
    if(x == n-1 && y == n-1){
        count++;
        return;
    }

    visited[x][y] = 1;

    if(isValid(x,y) && maze[x][y]){
        // go down
        if(x +1 < n && !visited[x+1][y]){
            countPaths(maze, x+1, y, visited, count);
        }
        // go right
        if(y+1 < n && !visited[x][y+1]){
            countPaths(maze, x, y+1, visited, count);
        }
        // go top
        if(x -1 >=0 && !visited[x-1][y]){
            countPaths(maze, x-1, y, visited, count);
        }
        // go left
        if(y-1 >=0 && !visited[x][y-1]){
            countPaths(maze, x, y-1, visited, count);
        }
    }
    visited[x][y] = 0;
}

/***Extend
 * print paths
 * 
 */



} // namespace

#endif // !FINDPATHCONSTRAINS_H_