//
//  Find_Majority.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/23.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Majority_h
#define Find_Majority_h

/****找到主元素即元素个数大于n/2
 Find majority of integers containing duplicates,return the maojority
 element in an array if present. A majority element appears more than
 n/2 times where n is the size of array.
 **/
// naive solution N^2
//solution 2: first to sort the array, and then perform binary
//search for first and last occurrence of each element
// O(nlogn)

// O(n) solutioin:--
/*
 we can use hashing to solve this problem in linear time. the idea
 is to store each element's frequency in a map and return element
 if its frequency becomes more than n/2, if no such element is present
 , then majority element does not exists in the array and we return -1

 */

int majorityElement(int a[],int n){
    unordered_map<int,int> maps;
    for(int i = 0;i < n;i++){
        maps[a[i]]++;
    }
    
    for(auto pair:maps){
        if(pair.second > n/2){
            return pair.first;
        }
    }
    
    return -1;
}


#endif /* Find_Majority_h */
