#ifndef FINDSHORTPATHMAZE_H_
#define FINDSHORTPATHMAZE_H_

#include<iostream>
#include <climits>
#include <cstring>
using namespace std;

namespace findshortest{
/**
 * Find shortest path in a Maze
 * 
 * Given a maze in the form of the binary rectangular matrix, find length of the shortest
 * path in maze from given source to given destination. the path can only be constructed out of 
 * cells having value 1 and at any given moment, we can only move one step in one of
 * the four directions.
 * 
 * Solution:
 * To find shortest path in maze, we search for all possible paths in the maze 
 * from the starting position to the goal position until all possibilities are exhausted. 
 * We can easily achieve this with the help of backtracking. 
 * We start from given source cell in the matrix and explore all four paths possible 
 * and recursively check if they will leads to the destination or not. 
 * We update the minimum path length whenever destination cell is reached. 
 * If a path doesn’t reach destination or we have explored all possible routes 
 * from the current cell, we backtrack. To make sure that the path is simple 
 * and doesn’t contain any cycles, we keep track of cells involved in current path 
 * in an matrix and before exploring any cell, 
 * we ignore the cell if it is already covered in current path.
 * 
 * discussion: BFS
 * the time complexity of above backtracking solution will be higher since all paths need to
 * be traveled. However, since it is an shortest path problem, BFS would be an ideal choice
 * if we use BFS to solve this problem, we travel level by level, so the first occurrence
 * of the detination node gives us the result and we can stop our search there.
 * 
 */

const int m = 10;
const int n = 10;

// check if it is possible to go to
bool isSafe(int mat[m][n], int visited[m][n], int x, int y){
    if(mat[x][y] == 0 || visited[x][y]){
        return false;
    }
    return true;
}

bool isValid(int x, int y){
    if(x < m && y < n && y >= 0 && x >=0){
        return true;
    }
    return false;
}

// find the shortest possible route in a matrix mat from source cell(0,0)
// to distination cell(x,y)

// min_dist is passed by reference
void findShortestPath(int mat[m][n], int visited[m][n], int i, int j,
    int x, int y,int& min_dist, int dist){
    // if destination is found, update min_dist
    if(i == x && j == y){
        min_dist = min(dist, min_dist);
        return;
    }
    // set(i,j)
    visited[i][j] = 1;
    
    // go to bottom cell
    if(isValid(i+1, j)&& isSafe(mat, visited, i+1, j)){
        findShortestPath(mat, visited, i+1, j, x, y, min_dist, dist +1);
    }

    // to right
    if(isValid(i, j+1)&& isSafe(mat, visited, i, j+1)){
        findShortestPath(mat, visited, i, j+1, x, y, min_dist, dist +1);
    }

    // to top
    if(isValid(i-1, j)&& isSafe(mat, visited, i-1, j)){
        findShortestPath(mat, visited, i-1, j, x, y, min_dist, dist+1);
    }

    // to left
    if(isValid(i, j-1)&& isSafe(mat, visited, i, j-1)){
        findShortestPath(mat, visited, i, j-1, x, y, min_dist, dist +1);
    }
    visited[i][j] = 0; // recover
}

} // namespace findshortest

#endif // !FINDSHORTPATHMAZE_H_