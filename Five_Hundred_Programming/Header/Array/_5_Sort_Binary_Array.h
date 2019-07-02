//
//  Sort_Binary_Array.h
//  BeautyOfProgramming
//   (四）
//  Created by hyx on 17/10/20.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Sort_Binary_Array_h
#define Sort_Binary_Array_h

#include <iostream>
using namespace std;

/****
 Sort Binary Array in Linear Time
 Given an binary array, sort it in linear time and constant space
 output should print contain all zeroes followed by all ones
 **/
/***
 Solution 1:
 用一个指针index用于放0，另一个索引i遍历数组，遇到0，则将arr[index] =0
 等到i到头，则将index后的值都放1
 ***/
void Print(int A[],int n){
    for(int i = 0;i < n;i++){
        cout<<A[i]<<endl;
    }
}

void Sort_Binary(int A[],int n){
    //k stores index of next availiable position
    int k =0;
    
    for(int i = 0;i < n;i++){
        //if current element is 0
        if(A[i] == 0){
            A[k++] = 0;
        }
    }
    for(;k < n;k++){
        A[k] = 1;
    }
}
/***
 利用快排的分界操作
 the idea is to use 1 as pivot element and make
 one pass of partition process
 **/
void Partition(int A[],int n){
    int pivot = 1;
    int j = 0; //始终指向大的
    
    for(int i = 0;i < n;i++){
        //这样的判断语句，是的j指向的是为不小于pivot的下标
        //当遇到小于pivot时，将后面小的和前面大的交换
        //
        if(A[i] < pivot){
            swap(A[i],A[j]);
            j++;
        }
    }
}
/*****
 扩展考虑：
 将奇偶数组分界，也可利用该函数方式
 
 ***/



#endif /* Sort_Binary_Array_h */
