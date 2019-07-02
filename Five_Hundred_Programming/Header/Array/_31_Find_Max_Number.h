//
//  Find_Max_Number.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/11/1.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef Find_Max_Number_h
#define Find_Max_Number_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

/****
 将一个数组的元素拼接成一个数字，使其最大：
 Find largest number possible from set of given numbers. The numbers
 should be appended to each other in any order to form the
 largest number.
 简单的排序存在错误
 Simply sorting the array in descending order and considering the sorted order
 is not a possibility here as sorted array {75, 68, 21, 12, 10, 7} will result in
 number 75682112107 which is less than largest number possible
 77568211210.
 我们需要自定义比较函数
 The idea is to write our own custom comparator function for the sorting routine.
 For two numbers X and Y, the custom comparator function will not compare
 X and Y with each other but it compares XY with YX and the greater
 number will come firrst in sorted order. Here, XY denotes number formed by
 appending Y to X and YX denotes number formed by appending X to Y.
 For example, for X = 15 and Y = 4, XY = 154 and YX = 415.
 As evident from above example, X > Y but XY < YX, so the comparator function
 will consider Y > X.
 */

//注意必须是const void＊类型作为参数，使用前仔转化为原来的类型
int comp(const void * a,const void *b){
    const char ** X = (const char **)a;
    const char ** Y = (const char **)b;
    
    int len = strlen(*X) + strlen(*Y) + 1;
    
    char XY[len];
    strcpy(XY,*X);
    strcat(XY,*Y);
    
    char YX[len];
    strcpy(YX,*Y);
    strcat(YX,*X);
    
    return strcmp(YX,XY);
}

int Find_Max_Number(char* a[],int n){
    
    qsort(a,n,sizeof(a[0]),comp);
    
    for(int i = 0;i < n;i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}



#endif /* Find_Max_Number_h */
