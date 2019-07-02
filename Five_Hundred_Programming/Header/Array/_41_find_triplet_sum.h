//
//  find_max_sum_no_adj.h
//  Five_Hundred_Programing
//
//  Created by lshm on 19/06/01.
//  Copyright © 2019年 lshm. All rights reserved.
//

#ifndef find_triplet_sum
#define find_triplet_sum

/***
 * this problem is a standard variation of 3sum problem where instead of looking
 * for numbers whose sum is 0, we look for numbers whose sum is any constant C.
 * 
 * input: 
 *  arr = [2,7,4,0,9,5,1,3]
 *  sum = 6
 * 
 * output: triplet exists.
 * 
 * below are triplet with given sum 6
 * (0,1,5), (0,2,4), (1,2,3)
 * 
*/

#include <iostream>

// naive recursive function to check if triplet exists in array with given sum
bool tripletExists(int arr[], int n, int sum, int count){
    // if triplet has desired sum, return true
    if (count == 3 && sum == 0){
        return true;
    }

    // return false, if sum is not possible with current configuration
    if (count ==3 || n == 0 || sum < 0){
        return false;
    }

    // recur with:
    //1. including current element
    // 2. excluding current element
    return tripletExists(arr, n-1, sum - arr[n-1],count+1) ||
            tripletExists(arr, n-1, sum, count);
}

/************
 * O(n^2) solution using Hashing
 *  the idea is insert each element of the array in a map(map<arr,index>)
 * then we consider all pair present in the array(two for loop) and check
 * if remaining sum exists in the map or not, if remaining sum is seen before
 * and triplet don't overlap with each other i.e, (i,j,i) or (i,j,j) 
*/

#include <algorithm>
#include <unordered_map>

bool tripletExists2(int arr[], int n, int sum){
   // create an empty map
   std::unordered_map<int, int> map;

   // insert (element,index), pair in map for each element in the array
   for (int i = 0; i < n; i++){
       map[arr[i]] = i;
    } 
    
    // consider each element except last element
    for (int i = 0; i < n - 1; i++){
        //start from i'th element till last element
        for (int j = i + 1; j < n; j++){
            int var = sum  - (arr[i] + arr[j]);

            if (map.find(var) != map.end()){
                if (map[var]!=i && map[var] != j){
                    return true;
                }
            }
        }
    }
    return false;
}

/********************
 * How to print all distinct triplets?
 * the idea is to sort the given array in ascending order
 * and for each element arr[i] in the array,
 * we check if triplet is formed by arr[i] and a pair
 * from sub-array arr[i+1,..n];
 * 
*/

void printAllTriplets(int arr[], int n, int sum){

    std::sort(arr, arr+n);

    // check if triplet is formed by arr[i] and a pair
    // from sub array arr[i+1,n]
    for (int i = 0; i <= n - 3; i++){
        int k = sum - arr[i];

        int low = i + 1, high = n - 1;

        while(low < high){
            if (arr[low] + arr[high] < k){
                low++;
            }else if (arr[low] + arr[high] > k){
                high--;
            }else{
                std::cout<<"("<<arr[i]<<" "<<arr[low]<<
                " "<<arr[high]<<")\n";

                // jump current result, to find another triplet
                low++, high--;
            }
        }
    }
}












#endif /* find_triplet_sum */