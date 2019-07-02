//
//  Find_Largest_SubArr.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/20.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Largest_SubArr_h
#define Find_Largest_SubArr_h
#include <vector>
using namespace std;
/****
 Find largest sub-array formed by consecutive integers
 Given an array of integers, find largest subarray formed by consecutive integers, the sub-array should contain all distance value
 获得最大长度子串，子串时有连续int数组成，但是不一定要顺序的，只要能所有元素能形成连续的值即可，且子串元素不重复
 */
/***
solution 1:
 1)判断是否为连续的值，是否没有重复
 2）开始遍历所有情况
*/
bool isConsecutive(int a[],int i,int j,int min_val,int max_val){
    //i,j为数组下标，则元素如果是连续的，则
//    则最大值－最小值应该等于j－i
//    并且没有重复数字，则一定为连续的
    if(max_val - min_val != j - i){
        return false;
    }
    
    vector<bool> visited(j - i + 1);
    
    for(int k = i;k < j;k++){
        if(visited[a[k] - min_val])
            return false;
        visited[a[k] - min_val] =true;
    }
//    we reach here when all elements in array are distinct
    return true;
}

void findMaxSubArray(int a[],int n){
    int len = 1;
    int start =0,end = 0;
    
//    consider each sub-array formed by a[i..j]
    //i denotes the begining of sub-array
    for(int i = 0;i < n - 1;i++){
        int min_val = a[i],max_val = a[i];
        
        //j denotes the end of sub-array
        for(int j = i + 1;j < n;j++){
            min_val = min(min_val,a[j]);
            max_val = max(max_val,a[j]);
            
            if(isConsecutive(a,i,j,min_val,max_val)){
                if(len < max_val - min_val + 1)
                    len = max_val - min_val + 1,
                    start = i, end = j;
            }
        }
    }
    cout<<"sub array is ["<<start<<".."<<end<<']'<<endl;
}


#endif /* Find_Largest_SubArr_h */
