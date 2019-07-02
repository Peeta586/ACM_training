//
//  Find_MaxSub_Product.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/11/4.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_MaxSub_Product_h
#define Find_MaxSub_Product_h
/**找出最大成绩的子序列，子序列时连续的
 Given an array of integers, find sub-array in it that has maximum
 product of its elements.
 For example,
 Input: { -6, 4, -5, 8, -10, 0, 8 }
 Output: The maximum product sub-array is {4, -5, 8, -10} having product
 1600
 Input: { 40, 0, -20, -10 }
 */
/***naive:
 Naive solution would be to consider every sub-array and find product of their
 elements. Finally, we return the maximum product found among all sub-arrays.
 The implementation can be seen here. The time complexity of this solution
 is O(n ).
 */
/**因为有负数存在，所以我们说过最大和最小标签纪录当前元素前的最大成绩
 最小的为绝对值最大的负数，所以再遇到负元素，可能存在最大成绩，所以不能只计算
 当前最大成绩
 A better solution will be to maintain two variables to store the maximum and
 minimum product ending at current position. Then we traverse the array
 once and for every index i in the array, we update maximum and minimum
 product ending at A[i]. We update the result if maximum product ending at
 any index if more than maximum product found so far.
 **/
int Max_Product(int a[],int n){
//    考虑第一个元素
    int max_ending = 0, min_ending = 0;
    
    int max_so_far = 0;
    
    for(int i = 0;i < n;i++){
        int old_max_ending = max_ending;
        
        max_ending = max(a[i],max(max_ending * a[i],min_ending * a[i]));
        
        min_ending = min(a[i],min(a[i] * old_max_ending,min_ending * a[i]));
        
        max_so_far = max(max_so_far,max_ending);
    }
    return max_so_far;
}





#endif /* Find_MaxSub_Product_h */
