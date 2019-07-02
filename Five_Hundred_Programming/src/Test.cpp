//
// Created by lshm on 19-3-9.
//

#include <iostream>
#include <gtest/gtest.h>
// #include "Array/_21_Find_Max_Diff.h"
#include <Array/_41_find_triplet_sum.h>

int Array_Test[] = {2,7,4,0,9,5,1,3};

TEST(Array_Test, tripletExists2){
    ASSERT_EQ(tripletExists2(Array_Test,8,6), true);
    // printAllTriplets(Array_Test, 8, 6);
}

TEST(Array_Test, printAllTriplets){
    ASSERT_EQ(tripletExists2(Array_Test,8,6), true);
    // printAllTriplets(Array_Test, 8, 6);
}
