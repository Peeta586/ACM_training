//
//  Find_lengthest_subarr.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/20.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_lengthest_subarr_h
#define Find_lengthest_subarr_h
#include <iostream>
using namespace std;
/**
 find maximum length sub-array having given sum
 given an array of integers, find maximum length sub-array having given sum
 */
//solutoin 1: O(n^2)遍历每种情况，累加记忆每个子串的sum，然后如果＝＝给定的sum并且长度更长，则更新length
void maxLengthSubArray(int a[], int n, int s){
    int len = 0;
    int ending_index = 1;
    
    //consider all sub-arrays starting from 1
    for(int i = 0;i < n;i++){
        int sum = 0;
        ///j =i, 考虑a[i]本身
        for(int j = i;j < n;j++){
            sum += a[j];
            
            if(sum == s){
                if(j - i + 1 > len){
                    len = j - i + 1;
                    ending_index = j;
                }
            }
        }
    }
    cout<<'['<<(ending_index - len + 1)<<','<<ending_index<<']'<<endl;
}

///solution 2 :
/***
 这种子串和的求解，要考虑用map存储累加的sum和index，然后通过遍历以前是否出现过相同的sum值，来判断子串为sum＝0
 We can use map to solve this problem in linear time. The idea
 is to create an empty map to store ending index of first subarray
 having given sum. We traverse the given array, and maintain
 sum of elements seen so far. 
 If sum is seen for first time, insert the sum with its index into the map. 
 If (sum – S) is seen before, there exists a sub-array with given sum which end  at current index and we update maximum length sub-array having sum S if current sub-array has more length.
 time: O(n),maps为hashing
 **/
void maxLengthSubArray2(int a[],int n,int s){
    //create an empty map to store ending index of first sub-array
    //having some sum(判断条件是 sum-s在前面出现过)
    unordered_map<int, int> maps;
    
    //insert(0,-1) to handle the case when sub-array with sum s starts from index 0
    maps[0] = -1;  //当sum ＝ s时，则len = i - maps[0] = i + 1;
    
    int sum = 0;
    
    int len = 0;
    
    int ending_index = -1;
    
    for(int i = 0;i < n;i++){
        
        sum += a[i];
        
        if(maps.find(sum) == maps.end()){
            maps[sum] = i;
        }
        
        if(maps.find(sum - s) != maps.end() && len < i - maps[sum - s]){
            len = i - maps[sum - s];
            ending_index = i;
        }
    }
    cout<<'['<<(ending_index - len + 1)<<','<<ending_index<<']'<<endl;
}





#endif /* Find_lengthest_subarr_h */
