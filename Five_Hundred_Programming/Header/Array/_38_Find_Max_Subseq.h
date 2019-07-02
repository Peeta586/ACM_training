//
//  Find_Max_Subseq.h
//  BeautyOfProgramming
//   （一）
//  Created by hyx on 17/10/17.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Max_Subseq_h
#define Find_Max_Subseq_h

#include <algorithm>
/****
 Find Maximum sum of subsequence with no adjacent elements
 
 Given an array of integers, find the maximum sum of subsequence of given array where subsequence contains no adjacent elements
 ****/

/***解法1:思想类似于0/1背包问题，
 通过递归的方式对元素取活着不取操作，惯用写法，分两种情况递归下去
 The problem is similar to 0/1 Knapsack problem where for every item,
 we have two choices – to include that element in the solution or to exclude that element from solution.
 We can solve this problem by following the same logic. The only difference is that we include current element only
 if it is not adjacent to previous element considered.
 **/

int maxSubSequence(int a[],int cur_index,int length,int pre_index){
    //the condition of finish
    if (cur_index == length)
        return 0;
    
    //不考虑当前元素
    int excel = maxSubSequence(a,cur_index + 1,length,pre_index);
    int incl = 0;
    
    if (pre_index + 1 != cur_index){//if cur_index is no adjacent pre_index
        incl = maxSubSequence(a,cur_index + 1,length,cur_index) + a[cur_index];
    }
    
    return max(incl,excel);
    
}

/****
 解法2:也可以使用自底向上的思维方式，利用动态规划，每次计算走到cur_index时的最大和
 利用动态规划避免了递归的溢出和代价
 We can also solve this problem in bottom-up fashion using Dynamic Programming (Tabulation). In the bottom-up approach, we solve smaller sub-problems first, then solve larger sub-problems from them. The idea is to create an auxiliary array lookup[] to store solution of sub-problems where for each index i, lookup[i] stores the maximum value that can be attained till index i. It uses value of smaller values i already computed. It has the same asymptotic run-time as Memoization but no recursion overhead.
 ***/
int MaxSubSequence2(int a[],int length){
    //base case
    if (length == 1)
        return a[0];
    
    //create an axiliary array to store solution of sub-problems
    int look_up[length];
    
    //look_up[i] stores the maximum sum possible till index i
    
    //trivial case
    look_up[0] = a[0];
    look_up[1] = max(a[0],a[1]);
    
    for(int i = 2;i < length;i++){
        /**
         // 1. excluding current element & take maximum sum till index i-1
         // 2. including current element arr[i] and take maximum sum
         //      till index i-2
         */
        
        look_up[i] = max(look_up[i - 1],look_up[i - 2] + a[i]);
        //element can be a negative value
        look_up[i] = max(look_up[i],a[i]);
    }
    return look_up[length - 1];
}

/***解法3:可以看出，上面时间复杂度O（n），但是都是需要辅助空间的，
 那第三种解法能否不使用辅助空间呢，我们从第二种解法中可以看出，我们只需要保存前面index的最大总和以及前面的前面index总和
 The time complexity of above solution is O(n) and auxiliary space used by the program is O(n).
Above solution uses extra space. We can also solve this problem without using any extra space. If we analyze the solution, we can see that maximum sum till any index i can be found by knowing the maximum sum of previous index i-1 and index i-2. So instead of storing the complete array, we can maintain two variables that stores the maximum sum till previous index and previous to previous index.
 ***/
int MaxSubSequence3(int a[],int length){
    if (length == 1)
        return a[0];
    
    int pre_pre = a[0];// 前前最大
    
    int pre = max(a[0],a[1]);//前最大
    
    for(int i = 2;i < length;i++){
        //注意：要把a[i]本身最大的情况考虑，避免了负数的元素情况
        int cur_sum = max(a[i],max(pre,pre_pre + a[i]));
        pre_pre = pre;
        pre = cur_sum;
    }
    return pre;
}



#endif /* Find_Max_Subseq_h */
