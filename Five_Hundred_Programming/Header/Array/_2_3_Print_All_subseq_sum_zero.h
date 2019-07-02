//
//  Print_All_subseq_sum.h
//  BeautyOfProgramming
//    （三）
//  Created by hyx on 17/10/19.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Print_All_subseq_sum_h
#define Print_All_subseq_sum_h

/**
 题目为打印总串中子串和为0的所有子串
 **/
#include <iostream>
#include <unordered_map>

using namespace std;

//最笨的解法，遍历所有可能，O(n^2),
void Print_All_SubArray(int arr[],int n){
    //start from i
    for(int i = 0;i < n;i++){
        int sum =0;
        
        //End at j
        for(int j = i;j < n;j++){
            sum += arr[j];
            
            if(sum == 0){
                cout<<"Sub Array["<<i<<".."<<j<<"]"<<endl;
            }
        }
    }
}

//方法二：用map辅助,＊＊＊＊＊＊思维技巧＊＊＊＊
///有一个技巧需要知道：就是如果一个串出现过子串为0的情况，
//那么这个串会存在累加和出现两次的情况，第二次与第一次出现sum相等之间的串为sum＝0的子串，我们只需要利用multimap保存前面的累加和即可
//这相当于，子串中查找等于sum的串的hashing方法，
void Print_All_SubArray2(int arr[],int n){
    //store previous  sum's value
    unordered_map<int, int> maps;
    
    maps.insert(pair<int,int>(0,-1));
    int sum = 0;
    
    for(int i = 0;i < n;i++){
        //sum of elements so far
        sum += arr[i];
        
        // if sum is seen before, there exists ar least on e
        //sub-array with 0 sum
        if(maps.find(sum) != maps.end()){
            auto it = maps.find(sum);
            
            //find all sub array with same sum
            //可能存在多个sum和当前sum相等的值
            while(it != maps.end() && it->first == sum){
                cout<<"Subarray is"<<it->second<<".."<<i<<endl;
                it++;
            }
        }
        maps.insert(pair<int,int>(sum,i));
    }
    
}


#endif /* Print_All_subseq_sum_h */
