//
//  Find_Max_Diff.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/27.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Max_Diff_h
#define Find_Max_Diff_h
/***
 找出数组中差距最大的一对数字，而且小的数前面
 Given an array of integers, find the maximum difference between
 two elements in the array such that smaller element appears 
 before the larger element.
 **/
// solution 1: Naive solution is to consider every pair present in
//the array and keep track of maximum difference found so far.
//time: O(n)

//solution 2:we solve this problem in linear time.
/* the idea is to traverse the array from the right and keep
 track of maximum difference found so far. if the current element
 is less than the maximum element found so far and their difference
 is more than maximum difference found so far,then we update
 the maximum difference with current difference.
 
 //从左到右也可以，每次记录最小值
 */
#include <climits>
using namespace std;

int diff(int a[],int n){
    int max_diff = INT_MIN;
    int min_elem = a[0];
    
    for(int i = 1;i < n;i++){
        if(a[i] < min_elem)
            min_elem = a[i];
        max_diff = max(max_diff,a[i] - min_elem);
    }
    return max_diff;
}





#endif /* Find_Max_Diff_h */
