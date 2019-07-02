//
//  Find_Min_Win_Sort.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/11/2.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Min_Win_Sort_h
#define Find_Min_Win_Sort_h
/**找到最小的窗口，对小窗口排序使得整个数组是增序的
 Find the smallest window in array sorting which will make the 
 entire array sorted.
 For example,
 Input: { 1, 2, 3, 7, 5, 6, 4, 8 }
 Output: Sort the array from index 3 to 6
 Input: { 1, 3, 2, 7, 5, 6, 4, 8 }
 Output: Sort the array from index 1 to 6
 */
/**
 We can easily solve this problem in linear time. Below is the complete algorithm
 –算法思路：就是先从左到右遍历，遍历到比遍历过的最大元素小的最右边的元素j，
 从右到左也是，遍历到比遍历过最小元素大的最左边的元素i，这样就保证了两个端点i，j外是排序的
 不用再进行sort。
 1. Traverse array from left to right keeping track of maximum so far and
 note the last encountered index j which is less than the maximum so far.
 2. Traverse array from right to left keeping track of minimum so far and
 note the last encountered index i which is more than the minimum so
 far.
 3. Finally we sort the array from index i to j
 For example, consider below array
 { 1, 2, 3, 7, 5, 6, 4, 8 }
 If we traverse the array from left to right, the last encountered index which is
 less than the maximum so far is 6（8比7大所以最右边比7小的是6）. Similarly, if we traverse the array from
 right to left, the last encountered index which is more than the minimum so
 far is 3. So, we need to sort the array from index 3 to 6.
 **/
void Find_Min_Win_Sort(int a[],int n){
    int leftIndex = -1,rightIndex = -1;
    
    int max_so_far = INT_MIN;
    for(int i = 0;i < n;i++){
        if(max_so_far < a[i])
            max_so_far = a[i];
        // 根据例子来说，最后一次为8，最大没有比它小的了
        if(a[i] < max_so_far)
            rightIndex = i;
    }
    int min_so_far = INT_MAX;
    for(int i = n - 1;i >= 0;i--){
        if(min_so_far > a[i])
            min_so_far = a[i];
        if(a[i] > min_so_far)
            leftIndex = i;
    }
    cout<<'['<<leftIndex<<','<<rightIndex<<']'<<endl;
}


#endif /* Find_Min_Win_Sort_h */
