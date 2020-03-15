//
// Created by lshm on 19-3-9.
//

#include <iostream>
#include <cstring>
#include <gtest/gtest.h>
// #include "Array/_21_Find_Max_Diff.h"
#include <Array/_41_find_triplet_sum.h>
#include <Backtracking/_1_findEightQueens.h>
#include <Backtracking/_2_printAllKnightTours.h>
#include <Backtracking/_3_MagnetPuzzle.h>
#include <Backtracking/_4_FindShortPathMaze.h>
#include <Backtracking/_5_FindLongestRoutMatrix.h>
#include <Backtracking/_6_FindPathSatisfyConstrains.h>
#include <Backtracking/_7_FindNumPathsMaze.h>
#include <Backtracking/_8_printAllHamiltonianPath.h>
#include <Backtracking/_9_KcolorableConfig.h>
#include <Backtracking/_10_FindPermutationsString.h>
#include <Backtracking/_11_FindAllBinaryStringsWithpattern.h>

int Array_Test[] = {2,7,4,0,9,5,1,3};

TEST(Array_Test_NAME, tripletExists2){
    ASSERT_EQ(tripletExists2(Array_Test,8,6), true);
    // printAllTriplets(Array_Test, 8, 6);
}

TEST(Array_Test_NAME, printAllTriplets){
    ASSERT_EQ(tripletExists2(Array_Test,8,6), true);
    // printAllTriplets(Array_Test, 8, 6);
}



TEST(QueenTest, nQueen){
    ASSERT_TRUE(EightQueens::nQueen(EightQueens::mat,0));
}

#define NN 5
TEST(KnightTourTest, KnightTour){
    int visited[NN][NN];
    int pos = 1;
    memset(visited, 0, sizeof(visited));
    AllKnightTours::KnightTour(visited, 0, 0, pos);
}

#define NNN 3
#define MMM 4
TEST(solveMagnetPuzzleTest, solveMagnetPuzzle){
    int top[NNN] = {2, -1, -1};
    int bottom[NNN] = {-1,-1, 2};
    int left[MMM] = {-1, -1, 2, -1};
    int right[MMM] = {0, -1, -1, -1};

    char str[MMM][NNN] ={
        {'T', 'T', 'T'},
        {'B','B','B'},
        {'T','L', 'R'},
        {'B', 'L','R'}
    };

    MagnetPuzzle::solveMagnetPuzzle(top, left, bottom, right, str);
}


TEST(FindShortestPathTest, findShortestPath){

    int mat[findshortest::m][findshortest::n] = 
	{
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
	};

    // struct a matrix to keep track of visited cells
	int visited[findshortest::m][findshortest::n];

	// initially all cells are unvisited
    // sizeof(visited)与 sizeof visited 一样
    // 
	memset(visited, 0, sizeof visited);
	
	int min_dist = INT_MAX;
	findshortest::findShortestPath(mat, visited, 0, 0, 7, 5, min_dist, 0);
 
	if(min_dist != INT_MAX)
		cout << "The shortest path from source to destination "
				"has length " << min_dist;
	else 
		cout << "Destination can't be reached from given source";

}

TEST(FindLongestPathTest, findLongestPath){

    int mat[findlongestRout::m][findlongestRout::n] = 
	{
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
	};

    // struct a matrix to keep track of visited cells
	int visited[findlongestRout::m][findlongestRout::n];

	// initially all cells are unvisited
    // sizeof(visited)与 sizeof visited 一样
    // 
	memset(visited, 0, sizeof visited);
	
	int min_dist = 0;
	findlongestRout::findLongestPath(mat, visited, 0, 0, 7, 5, min_dist, 0);
 
	if(min_dist != 0)
		cout << "The shortest path from source to destination "
				"has length " << min_dist;
	else 
		cout << "Destination can't be reached from given source";

}

TEST(countPathsTest, countPaths){
    int maze[findPathConstrains::n][findPathConstrains::n] = 
	{
		{ 1, 1, 1, 1 },
		{ 1, 1, 0, 1 },
		{ 0, 1, 0, 1 },
		{ 1, 1, 1, 1 }
	};

	// stores number of unique paths from source to destination
	int count = 0;

	// 2D matrix to keep track of cells involved in current path
	int visited[findPathConstrains::n][findPathConstrains::n];
	memset(visited, 0, sizeof visited);
	
	// start from source cell (0, 0)
	findPathConstrains::countPaths(maze, 0, 0, visited, count);
	
	cout << "Total number of unique paths are " << count;
}

TEST(countPathTest, countPaths){
	memset(findTotalNumber::visited,0, sizeof findTotalNumber::visited);
	findTotalNumber::countPaths(
		findTotalNumber::maze,
		0,0,
		findTotalNumber::visited,
		findTotalNumber::count
	);
	cout<<"total number is: "<<findTotalNumber::count<<endl;
	memset(findTotalNumber::visited,0, sizeof findTotalNumber::visited);
	findTotalNumber::printPaths(findTotalNumber::maze,
		0,0,
		findTotalNumber::visited,
		findTotalNumber::res);
}

TEST(printAllHamiltonianPathsTest, printAllHamiltonianPaths){
	vector<int> path;
	path.push_back(PrintHamiltonian::start);
	vector<bool> visited(PrintHamiltonian::n);
	visited[PrintHamiltonian::start] = true; // must be set
	PrintHamiltonian::printAllHamiltonianPaths(
		PrintHamiltonian::g,
		PrintHamiltonian::start,
		visited,
		path,
		PrintHamiltonian::n
	);
}

TEST(KColorableConfigTest, kColorable){
	KColorableConfig::kColorable(KColorableConfig::g, 
	KColorableConfig::color,
	KColorableConfig::k,
	0,
	KColorableConfig::n);
}

// 10
TEST(permutationStringTest, permutations){
	PermuatationString::permuatation(PermuatationString::str,
		0,
		PermuatationString::str.size());
	PermuatationString::permuatations2(PermuatationString::str,
		PermuatationString::str.size(), PermuatationString::res);
	ASSERT_TRUE(true);
}

//11
TEST(printAllcombinationsTest, printAllcombinations){
	printAllcombination::printAllcombinations(printAllcombination::pattern, 0);
	ASSERT_TRUE(true);
}
