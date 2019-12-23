#ifndef FINDNUMPATHSMAZE_H_
#define FINDNUMPATHSMAZE_H_

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <utility>
#include <vector>

using namespace std;

/**
 * find the total number of unique paths which the robot can take in a given maze to
 * reach the destination from given source
 * 
 */

namespace findTotalNumber{
const int N = 4;

int maze[N][N] = {
    { 1, 1, 1, 1 },
    { 1, 1, 0, 1 },
    { 0, 1, 0, 1 },
    { 1, 1, 1, 1 }
};
int count = 0;

int visited[N][N];

bool isValidCell(int x, int y){
    if(x < 0 || y < 0 || x>=N || y >= N){
        return false;
    }
    return true;
}

void countPaths(int maze[N][N], int x, int y, int visited[N][N], int& count){
    if(x == N-1 && y == N -1){
        count++;
        return;
    }

    visited[x][y] = 1;

    if(isValidCell(x,y) && maze[x][y]){
        // go down
        if(x + 1 < N && !visited[x+1][y]){
            countPaths(maze, x+1, y, visited,count);
        }
        // go up
        if(x - 1 >=0 && !visited[x - 1][y]){
            countPaths(maze, x-1, y, visited,count);
        }
        // go left
        if(y - 1 >= 0 && !visited[x][y - 1]){
            countPaths(maze, x, y - 1, visited,count);
        }
        // go right
        if(y + 1 < N && !visited[x][y + 1]){
            countPaths(maze, x, y + 1, visited,count);
        }
    }

    visited[x][y] = 0;
}

vector<pair<int, int> > res;
void printPaths(int maze[N][N], int x, int y, int visited[N][N], 
    vector<pair<int, int> >& res){
    if(x == N-1 && y == N -1){
        cout<<"length of paths: "<<res.size()<<endl;
        return;
    }

    visited[x][y] = 1;
    pair<int,int> p1 = make_pair(x, y);
    res.push_back(p1);
    if(isValidCell(x,y) && maze[x][y]){
        // go down
        if(x + 1 < N && !visited[x+1][y]){
            printPaths(maze, x+1, y, visited,res);
        }
        // go up
        if(x - 1 >=0 && !visited[x - 1][y]){
            printPaths(maze, x-1, y, visited,res);
        }
        // go left
        if(y - 1 >= 0 && !visited[x][y - 1]){
            printPaths(maze, x, y - 1, visited,res);
        }
        // go right
        if(y + 1 < N && !visited[x][y + 1]){
            printPaths(maze, x, y + 1, visited,res);
        }
    }
    res.pop_back();
    visited[x][y] = 0;
}


} // namespace findTotalNumber


#endif // ! FINDNUMPATHSMAZE_H_
