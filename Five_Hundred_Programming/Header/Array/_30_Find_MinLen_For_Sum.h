//
//  Find_MinLen_For_Sum.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/31.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_MinLen_For_Sum_h
#define Find_MinLen_For_Sum_h

/**找到最小长度大于等于给定sum的子串
 Given an array of integers, find the length of smallest subarray
 whose sum of elements is greater than the given positive number.
 solution1:
 
 We can solve this problem by using a sliding window. The idea is to maintain
 a window that ends at the current element and sum of its elements is less
 than or equal to the given sum. If current window’s sum becomes more than
 the given sum at any point of time, then the window is unstable and continue
 removing elements from the window’ left till it becomes stable again. We also
 update the result if unstable window’s length is less than minimum found so
 far.
 */
//return the length of subarray
int Find_MinLen_For_Sum(int a[],int n,int sum){
    int win_sum =0;
    int len = INT_MAX;
    int left = 0;
    
    for(int right = 0;right < n;right++){
        win_sum += a[right];
        
//        (to handle negative numbers in the array)
        // if window's sum becomes negative, discard the win
        if(win_sum <= 0){
            left = right;
            win_sum =0;
        }
        while(win_sum >= sum && left <= right){
            len = min(len,right +1 - left);
            win_sum -= a[left];
            left++;
        }
        
    }
    return len;
}



#endif /* Find_MinLen_For_Sum_h */
