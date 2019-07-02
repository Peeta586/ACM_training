//
//  Find_Max_Path_Two_Arr.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/11/2.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Max_Path_Two_Arr_h
#define Find_Max_Path_Two_Arr_h

/**
 Given two sorted array of integers, find a maximum sum path involving
 elements of both arrays whose sum is maximum. We can
 start from either arrays but we can switch between arrays only
 through its common elements.
 For example,
 Input:
 X = { 3, 6, 7, 8, 10, 12, 15, 18, 100 }
 Y = { 1, 2, 3, 5, 7, 9, 10, 11, 15, 16, 18, 25, 50 }
 The maximum sum path is
 1 —> 2 —> 3 —> 6 —> 7 —> 9 —> 10 —> 12 —> 15 —> 16 —> 18 —> 100
 **/
/**solution 1:
 The idea is very simple. We calculate sum between common elements
 present in the both arrays and include the maximum sum in the output.
 For example, consider below arrays X and Y having four common elements
 A, B, C, D.
 X[]: sum_x1 .., A, .. sum_x2 .., B, .. sum_x3 .., C, .. sum_x4 .., D, .. sum_x5
 Y[]: sum_x1 .., A, .. sum_y2 .., B, .. sum_y3 .., C, .. sum_y4 .., D, .. sum_y5
 Here sum_xi denotes the sum of elements between two common elements in
 array X. Similarly, sum_yi denotes the sum of elements between two common
 elements in array Y. For each pair (sum_xi, sum_yi), we include
 max(sum_xi, sum_yi) in the solution. i.e.
 Result = max(sum_x1, sum_y1) + A + max(sum_x2, sum_y2) + B +
 max(sum_x3, sum_y3)
 + C + max(sum_x4, sum_y4) + D + max(sum_x5, sum_y5)
 解决思路：每次累加X，Y相同元素前的部分，然后比较，选取最大的那个作为路径一部分
 主要的是设计怎么获取相同元素之前的累加和，这就是比较XY当前元素，选较小的累加到
 相应的数组中去，也就是小的先走到相同的元素部分，这样能使得XY元素相等
 相遇。这时候统计前面加的部分，选取最大的就可以了。
 这是个编程技巧，很棒的
 */


int maxSum(int X[],int Y[],int m,int n){
    int sum = 0;
    int sum_x = 0, sum_y = 0;
    
    int x_i = 0, y_i =0;
    while(x_i < m && y_i < n){
        while(x_i < m - 1 && X[x_i] == X[x_i + 1])
            sum_x += X[x_i++];
        while(y_i < n - 1 && Y[y_i] == Y[y_i + 1])
            sum_y += Y[y_i++];
        
        if(Y[y_i] < X[x_i]){
            sum_y += Y[y_i];
            y_i++;
        }else if(Y[y_i] > X[x_i]){
            sum_x += X[x_i];
            x_i++;
        }else{//==
            sum += max(sum_x,sum_y) + X[x_i];
            sum_x = 0, sum_y = 0;
            y_i++,x_i++;
        }
    }
    while(x_i < m){
        sum += X[x_i++];
    }
    while(y_i < n){
        sum += Y[y_i++];
    }
    return sum;
}



#endif /* Find_Max_Path_Two_Arr_h */
