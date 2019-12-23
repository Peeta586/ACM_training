#ifndef FINDLONGESTROUT_H_
#define FINDLONGESTROUT_H_

#include <iostream>

using namespace std;

/**
 * Given a rectangular path in the form of binary matrix, find the length of longest possible
 * route from source to distination position of the matrix by moving to only non-zero
 * adjacent positives. i.e route can be formed from positions having their value as1 
 * Note there should not be any cycles in the output path
 */

namespace findlongestRout{

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
void findLongestPath(int mat[m][n], int visited[m][n], int i, int j,
    int x, int y,int& max_dist, int dist){
    if(mat[i][j] == 0)
        return;
    // if destination is found, update min_dist
    if(i == x && j == y){
        max_dist = max(dist, max_dist);
        return;
    }
    // set(i,j)
    visited[i][j] = 1;
    
    // go to bottom cell
    if(isValid(i+1, j)&& isSafe(mat, visited, i+1, j)){
        findLongestPath(mat, visited, i+1, j, x, y, max_dist, dist +1);
    }

    // to right
    if(isValid(i, j+1)&& isSafe(mat, visited, i, j+1)){
        findLongestPath(mat, visited, i, j+1, x, y, max_dist, dist +1);
    }

    // to top
    if(isValid(i-1, j)&& isSafe(mat, visited, i-1, j)){
        findLongestPath(mat, visited, i-1, j, x, y, max_dist, dist+1);
    }

    // to left
    if(isValid(i, j-1)&& isSafe(mat, visited, i, j-1)){
        findLongestPath(mat, visited, i, j-1, x, y, max_dist, dist +1);
    }
    visited[i][j] = 0; // recover
}


} // namespace  findlongestRout
#endif // !FINDLONGESTROUT_H_