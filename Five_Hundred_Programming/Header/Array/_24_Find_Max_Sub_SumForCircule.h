//
//  Find_Max_Sub_SumForCircule.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/27.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Max_Sub_SumForCircule_h
#define Find_Max_Sub_SumForCircule_h
/**题目是针对循环的最大和subarray的，，循环的一数组，也就是头尾衔接，
 形成一个环，如下数组，4,-1（后面紧接着），2，1，－5 ...
 Maximum Sum Circular Subarray
 Given an circular array of integers, find subarray in it which has the
 largest sum.
 For example,
 Input: {2, 1, -5, 4, -3, 1, -3, 4, -1}
 Output: Subarray with the largest sum is {4, -1, 2, 1} with sum 6.
 */

/***solution :
 The idea is to find the sequence which will have maximum negative value. If
 we remove that minimum sum sequence from the input sequence, then we
 will be left with maximum sum circular sequence. Finally, we return maximum
 of the maximum-sum circular sequence (includes corner elements)
 and maximum-sum non-circular sequence.
 For example, consider the array {2, 1, -5, 4, -3, 1, -3, 4, -1}. The sequence having
 maximum negative value is {-5, 4, -3, 1, -3} i.e. -6. If we remove this minimum
 sum sequence from the array, we will get the maximum sum circular
 sequence i.e. {2, 1, 4, -1} having sum 6. Since maximum sum circular sequence
 is greater than the maximum sum non-circular sequence i.e. {4} for
 the given array, it is the answer.
 We can find maximum-sum non-circular sequence in linear time by
 using Kadane’s algorithm. We can find maximum-sum circular sequence by
 inverting the sign of all array elements and then applying Kadane’s algorithm.
 For example, if we invert signs of array {2, 1, -5, 4, -3, 1, -3, 4, -1} we get {-2, -1,
 5, -4, 3, -1, 3, -4, 1} which has maximum sum sequence {5, -4, 3, -1, 3} having
 sum 6. Now inverting the signs back, we get minimum sum sequence {-5, 4,
 -3, 1, -3} having sum -6.
 方法思路：就是计算非循环下的max sum subarray值
 然后再计算出将整个数组除去最小sum后的值，比较两者最大的，为循环数组的最大
 子序列
 （要明白最大子串是没有最小子串的部分的）
 **/
#include "_22_23_Find_Print_Max_Sub_Sum.h"
#include <algorithm>

int Find_Max_Sub_SumForCircule(int a[],int n){
    for(int i = 0;i < n;i++)
        a[i] = -a[i];
    
    int neg_max = kadane3(a,n);
    
    //restore the array
    for(int i = 0;i < n;i++)
        a[i] = -a[i];
    /* return maximum of
     1. sum returned by Kadane's algorithm on original array
     2. sum returned by Kadane's algorithm on modified array
     sum of all elements of the array.
     */
    return max(kadane3(a,n),accumulate(a,a+n,0) + neg_max);
    
}

#endif /* Find_Max_Sub_SumForCircule_h */
