//
//  main.cpp
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/14.
//  Copyright © 2017年 hyx. All rights reserved.
//

#include <iostream>
#include "BP_Elevator.h"
#include "Find_Max_Subseq.h"
#include "FindPairForSum.h"
#include "Print_All_subseq_sum.h"
#include "Sort_Binary_Array.h"
#include "Find_Duplicated.h"
#include "Find_Largest_SubArr.h"
#include "Find_lengthest_subarr.h"
#include "Find_maximum_len_01.h"
#include "SortArray012.h"
#include "FindIndex0ForMax.h"
#include "FindMaxProduct.h"
#include "Shuffle_Array.h"
#include "FindEquilibrium.h"
#include "Find_Majority.h"
#include "MoveEnd0.h"
#include "ReplaceArrayDivision.h"
#include "Find_Longest_Bitnic.h"
#include "Find_Max_Diff.h"
#include "Find_Print_Max_Sub_Sum.h"
#include "Find_Max_Sub_SumForCircule.h"
#include "Find_Distinct_Combination.h"
#include "Find_Distinct_Comb_Repeat.h"
#include "Find_Max_Sub1_k.h"
#include "Find_Min_By_K.h"
#include "Find_Sum_In_Array.h"
#include "Find_MinLen_For_Sum.h"
#include "Find_Max_Number.h"
#include "Find_Min_Win_Sort.h"
#include "Find_Max_Path_Two_Arr.h"
#include "Find_Max_Profit.h"
#include "Trapping_Rain_Water_Bar.h"
#include "Find_MaxSub_Product.h"

using namespace std;

void print(int a[],int n){
    for(int i = 0;i < n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //test_elevator();
    int a[] = {-6, 4, -5, 8, -10, 0, 8};
//int b[] ={1, 2, 3, 5, 7, 9, 10, 11, 15, 16, 18, 25, 50};
    //generate a random number j such that 0<=j<=i
    int m = sizeof(a) / sizeof(a[0]);
//  int n = sizeof(b) / sizeof(b[0]);
//    int sum =21;
    cout<<Max_Product(a, m)<<endl;
//  print(a,n);
    
    return 0;
}
