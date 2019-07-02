//
//  MergeSorted_Inplace.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/21.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef MergeSorted_Inplace_h
#define MergeSorted_Inplace_h
/****
 the problem:将排序的两个数组合并，使得X存储整个合并排序后的前半部分，Y为后半部分，X，Y大小不变（也就是并非真正的融合为一个新的排序数组，而是将合并排序的序列再次分配到XY中），注意题目要求的是in-place,不能使用辅助的数据结构
 conversion should be done in-place and without using any other data structure
 X = {1,4,7,8,10}
 Y = {2,3,9}
 output:
 X = {1,2,3,4,7}
 Y = {8,9,10}
 ***/
void merge(int X[],int Y[],int m,int n){
    int i =0;
    
    while( i < m){
        if(X[i] > Y[0]){
            swap(X[i],Y[0]);
            int first = Y[0];
        
            //Y 保持顺序,每次都能使得X得到Y的最小值，这样Y就能保持最后面的值序列。
            int k;
            for(k = 1; k < n && Y[k] < first;k++){
                Y[k - 1] = Y[k];
            }
            Y[k - 1] = first;
        }
        i++;
    }
}



#endif /* MergeSorted_Inplace_h */
