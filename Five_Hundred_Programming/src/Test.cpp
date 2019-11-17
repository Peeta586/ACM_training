//
// Created by lshm on 19-3-9.
//

#include <iostream>
#include <gtest/gtest.h>
// #include "Array/_21_Find_Max_Diff.h"
#include <Array/_41_find_triplet_sum.h>
#include <Backtracking/_1_findEightQueens.h>

int Array_Test[] = {2,7,4,0,9,5,1,3};

TEST(Array_Test_NAME, tripletExists2){
    ASSERT_EQ(tripletExists2(Array_Test,8,6), true);
    // printAllTriplets(Array_Test, 8, 6);
}

TEST(Array_Test_NAME, printAllTriplets){
    ASSERT_EQ(tripletExists2(Array_Test,8,6), true);
    // printAllTriplets(Array_Test, 8, 6);
}

#define N 8
char mat[N][N];

TEST(QueenTest, nQueen){
    ASSERT_TRUE(nQueen(mat,0));
}
