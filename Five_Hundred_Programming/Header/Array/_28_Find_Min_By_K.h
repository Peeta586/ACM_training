//
//  Find_Min_By_K.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/31.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Min_By_K_h
#define Find_Min_By_K_h
/**给定长度k，求出数组中子串sum最小的且长度为k的子串
 problem:
 Given an array of integers, find minimum sum sub-array of given
 size k.
 **/
/***solution :k大小的窗口向右滑动
 We can solve this problem by using sliding window technique. The idea is to
 maintain a window of size k and for every element in the array, we include it
 in the window and remove leftmost element from the window if window size
 is more than k. We also maintain sum of elements in current window. If current
 window sum is more than minimum found so far, we update the minimum
 sum to current window sum and store window’s end-points.
 */

void Find_Min_By_K(int a[],int n,int k){
    int curr_sum = 0;
    int min_sum = INT_MAX;
    int ending_index = 0;
    
    for(int i = 0;i < n;i++){
        curr_sum += a[i];
        
        if(i + 1 >= k){
            if(curr_sum < min_sum){
                min_sum = curr_sum;
                ending_index = i;
            }
            curr_sum -= a[i + 1 - k];
        }
    }
    cout<<'['<<ending_index + 1 - k<<','<<ending_index<<']'<<endl;
}


#endif /* Find_Min_By_K_h */
