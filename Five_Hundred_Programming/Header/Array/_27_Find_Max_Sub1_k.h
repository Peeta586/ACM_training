//
//  Find_Max_Sub1_k.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/30.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Max_Sub1_k_h
#define Find_Max_Sub1_k_h
/******
 Find the maximum sequence of continuous 1's that can be formed
 by repacing at-most k zeroes by ones
 也就是说给定一个k，将binary数组中的k个0替换，能得到最长的连续为1的子串
 */

//solution:
/**
 We can solve this problem by using sliding window technique. The idea is to
 maintain a window containing at-most k zeroes at any point. We add elements
 to the window from right until it becomes unstable. The window becomes
 unstable if number of zeros in it becomes more than k. Then we remove
 elements from its left side till it becomes stable again (by removing leftmost
 zero). If the window is stable and current window length is more than
 maximum window found so far, we set the maximum window size to current
 window size.
 */

int Find_Max_Sub1_k(int a[],int n,int k){
    int count = 0;//count the number of 0 has passed
    
    int left = 0;  //最左边的0开头
    int max_count = 0;///连续1的最大长度
    
    for(int i = 0;i < n;i++){
        if(a[i] == 0){
            count++;
        }
        if(count == k + 1){
            while(a[left])
                left++;
            left++; //第一个零后面的1
            count--;
        }
        if(i - left + 1 > max_count){
            max_count = i - left + 1;
        }
    }
    return max_count;
}

#endif /* Find_Max_Sub1_k_h */
