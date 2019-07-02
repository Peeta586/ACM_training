//
//  FindPairForSum.h
//  BeautyOfProgramming
//     （二）
//  Created by hyx on 17/10/19.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef _1_FindPairForSum_h
#define _1_FindPairForSum_h
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
/*******
 Find Pair with given Sum in the Array
 
 Given an unsorted array of integers,
 find a pair with given sum in it
 */
/// 解法1: O(n^2),遍历每一种情况
///two for loops

void findPair(int arr[],int n,int sum){
    for(int i = 0;i < n-1;i++)
        for(int j = i + 1;j < n;j++){
            if(arr[i] + arr[j] == sum){
                printf("Find Pair is (%d,%d)",i,j);
                return;
            }
        }
    printf("Pair not find");
}
///解法2:O(nlog)using Sorting
/**先利用nlogn的复杂度排序，然后使用O(n)的复杂度遍历查找
 设置两个指针low和high；
 The idea is to sort the given array in ascending order and maintain
 search space by maintaining two indices (low and high) that initially points to two end-points of thearray. Then we loop till low is less than high index and reduce search space arr[low..high] at each iteration of the loop. We compare sum of elements present at index low and high with desired sum and increment low if sum is less than the desired sum else we decrement high is sum is more than the desired sum. Finally, we return if pair found in the array.
 **/

void findPair2(int arr[],int n,int sum){
    //sort the array in ascending order
    sort(arr,arr + n);
    
    //keep two indices pointing to end-points of the array
    int low = 0;
    int high = n - 1;
    
    while(low < high){
        //sum found
        if(arr[low] + arr[high] == sum){
            cout<<"Pair Found"<<endl;
            return;
        }
        (arr[low] + arr[high] < sum)? low++:high--;
    }
    cout<<"Pair not found"<<endl;
}

/**
 O(n)的解法利用hashing: hash的使用
 思路是：用sum － arr[i], 然后在查找后面是否存在差值的值
 We can use map to easily solve this problem in linear time. The
 idea is to insert each element of the array arr[i] in a map. We also
 checks if difference (arr[i], sumarr[i]) already exists in the map
 or not. If the difference is seen before, we print the pair and return.

 ***/
void FindPair3(int arr[],int n,int sum){
    unordered_map<int,int> maps;
    for(int i=0;i < n; i++){
        if(maps.find(sum - arr[i]) != maps.end()){
            cout<<"Pair found"<<endl;
            return;
        }
        //将前面访问的值存入map中，后面的有差值等于前面值的，则存在和为sum的
        maps[arr[i]] = i;
    }
    
    cout<<"Not Found"<<endl;
}



#endif /* FindPairForSum_h */
