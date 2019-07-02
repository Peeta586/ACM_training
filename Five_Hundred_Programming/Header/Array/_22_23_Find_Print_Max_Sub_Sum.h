//
//  Find_Max_Sub_Sum.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/27.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Max_Sub_Sum_h
#define Find_Max_Sub_Sum_h

/***Maximum subarray problem (kadane's algorithm)
 1)Given an array of integers, find contiguous subarray within it
 which has the largest sum
 2) 将最大和的子串打印，这就需要最大子串的下标区间
 */
// solution 1:
/**we can easily solve this problem in linear time using kadane's
 algorithm. the idea is to maintain maximum (positive sum) subarray
 ending ar each index of the given array. the subarray is either
 empty (in which case its sum is zero) or consists of one more
 element than the maximum subarray ending at the previous index
 利用两个变量保存i之前最大的sum以及到i时的当前sum，只有当前sum<0,才开始
 重新计算，即将当前sum ＝ 0
 time:O(n)
*/
using namespace std;
int kadane(int a[], int n){
    int max_so_far = 0;
    int max_ending_here = 0;
    
    for(int i = 0;i < n;i++){
        max_ending_here = max_ending_here + a[i];
        
        max_ending_here = max(max_ending_here,0);
        
        max_so_far = max(max_so_far,max_ending_here);
    }
    return max_so_far;
}

/***SOlution 2:
 above code doesn't handle the case when all elements of the 
 array are negative. if the array contains all  negative values
 the answer is the maximum element. we can easily place this 
 check before continuing to the algorithm.
 即先求出最大元素，如果最大元素<0 ,那么我们直接返回最大元素，说明所有元素<0
 */
int maximum(int a[],int n){
    int res = a[0];
    for(int i = 1;i < n;i++){
        res = max(res,a[i]);
    }
    return res;
}
int kadane2(int a[], int n){
    int max_elem = maximum(a,n);
    if(max_elem < 0)
        return max_elem;
    
    int max_so_far = 0;
    int max_ending_here = 0;
    
    for(int i = 0;i < n;i++){
        max_ending_here = max_ending_here + a[i];
        
        max_ending_here = max(max_ending_here,0);
        
        max_so_far = max(max_so_far,max_ending_here);
    }
    return max_so_far;
}
// solution 3:
/* for solution 2: this approach requires two traversals of the 
 input array. we can easily modify the main algorithm to handle 
 negative integers as well.
 很巧妙地运用了元素之间的比较，将第一种方法的初始化和与0对比，改为与当前
 元素对比，这样就能保留最大元素
 **/
int kadane3(int a[], int n){
    int max_so_far = a[0];
    int max_ending_here = a[0];
    
    for(int i = 1;i < n;i++){
        max_ending_here = max_ending_here + a[i];
        
        max_ending_here = max(max_ending_here,a[i]);
        
        max_so_far = max(max_so_far,max_ending_here);
    }
    return max_so_far;
}


// ＃＃＃＃＃＃＃＃＃＃Print
/*** we can easily solve this problem in linear time using Kadane's
 algorithm by maintaining maximum sum subarray ending at each index
 of the array, then this subarray is :
 1)either empty in which case its sum is zero or
 2) consists of one more element than the maximum subarray ending
 at the previous index. by tracking the starting and ending
 indices of the maximum subarray.
 考虑了全为负的情况
 */
int print_kadane(int a[], int n){
    int max_so_far = a[0];
    int max_ending_here = a[0];
    
    int starting =0,ending=0;
    
    for(int i = 1;i < n;i++){
        
        max_ending_here = max_ending_here + a[i];
        
        int cur_start = starting;
        
        if (max_ending_here < a[i]){
            cur_start = i;
            max_ending_here = a[i];
        }
        
        if(max_so_far < max_ending_here){
            starting = cur_start;
            ending = i;
            max_so_far = max_ending_here;
        }
    }
    cout<<'['<<starting<<','<<ending<<']'<<endl;
    return max_so_far;
}










#endif /* Find_Max_Sub_Sum_h */
