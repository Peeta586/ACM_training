//
//  Find_Sum_In_Array.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/31.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Sum_In_Array_h
#define Find_Sum_In_Array_h

#include <unordered_set>
using namespace std;
/**
 Find subarray having given sum in given array of integers
 Given an array of integers, find a subarray having given sum in it
 */
// Solution 1:
//using sliding window
/*注意：我们进行滑窗操作，如果滑窗大于sum则我们开始将左边元素删减，如果小于sum
则认为滑窗进入不稳定状态，开始加元素
 We can solve this problem by using a sliding window. The idea is to maintain
 a window that starts from the current element and sum of its elements is
 more than or equal to the given sum. If current window’s sum becomes less
 than the given sum, then the windows is unstable and we keep on adding elements
 to the current window from its right till the window becomes stable
 again. We print the window if it’s sum is equal to the given sum at any point
 of time. This approach will only work on positive sum.
 */
//这种方法不能处理存在负元素的情况
void Find_Sum_In_Array(int a[],int n,int sum){
    int curr_sum = 0;
    int start =0;
    int ending_index = 0;
    for(int i = 0;i < n;i++){
        //注意大于和小于与等号不是互斥的，所以要放到后面统一考虑
//        因为大于零操作后也会导致等于零的情况，所以大于0和小于0
//        都在后面判断是否等于0的情况
        curr_sum +=a[i];
       
        if(curr_sum > sum){ //greater
            while(curr_sum > sum && start <= i){
                curr_sum -= a[start++];
            }
        }
        if(curr_sum == sum){
            ending_index = i;
            break;
        }
    }
    cout<<'['<<start<<','<<ending_index<<']'<<endl;
}
//官方给出的答案，逻辑更加清晰，代码更具有可读性，不宜出逻辑错误
//不能解决存在负元素的情况
void Find_Sum_in_Arr(int a[],int n,int sum){
    // maintains sum of current window
    int windowSum = 0;
    // maintain a window [low, high-1]
    int low = 0, high = 0;
    // consider every sub-array starting from low index
    for (low = 0; low < n; low++)
    {
        // if current window's sum is less than the given su
        // then add elements to current window from right
        while (windowSum < sum && high < n)
        {
            windowSum += a[high];
            high++;
        }
        // if current window's sum is equal to the given sum
        if (windowSum == sum)
        {
            cout << "Subarray found [" << low << "-" <<high-1<<']'<<endl;
            return;
        }
        // At this point the current window's sum is more th
        // remove current element (leftmost element) from th
        windowSum -= a[low];
    }
}

//解决方法2:
/***将array累加，查找当前sum－15是否存在前面存储的hashing中
 Above solution will fail for negative numbers. We can use hashing to check if
 sub-array with given sum exists in the array or not. The idea is to traverse the
 given array and maintain sum of elements seen so far. If the di􀃗erence of
 current sum and given sum is seen before (i.e. the di􀃗erence exists in the
 set), we return true as there exists at-least one sub-array with given sum
 which ends at current index else we insert the sum into the set.
 */
bool Find_Sum_in_Arr_Hash(int a[],int n,int sum){
    
    unordered_set<int> sets;
    
    sets.insert(0);
    int sum_so_far = 0;
    for(int i = 0;i < n;i++){
        sum_so_far +=a[i];
        
        if(sets.find(sum_so_far - sum) != sets.end()){
            return true;
        }
        
        sets.insert(sum_so_far);
    }
    return false;
}


#endif /* Find_Sum_In_Array_h */
