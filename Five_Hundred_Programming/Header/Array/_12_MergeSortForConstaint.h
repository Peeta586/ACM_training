//
//  MergeSortForConstaint.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/22.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef MergeSortForConstaint_h
#define MergeSortForConstaint_h
/******
 Given two sorted arrays x,Y,size m and n, each where m >= n and X[] has exactly n vacant cells, merge element of Y in their correct position in array X,i.e. merge (X,Y) by keeping the sorted order
 X = {0,2,0,3,0,5,6,0,0}
 Y = {1,8,9,10,15}
 output {1,2,3,5,6,8,9,10,15}
******/
using namespace std;

//因为merge都元素挨着的，对于X的稀疏元素，我们可以先将它的非零元素对到前面，然后再与Y从后面进行遍历填充X

void Merge(int X[],int Y[],int m,int n){
    int k = m + n +1;
    
    while(m >= 0 && n >= 0){
        if(X[m] > Y[n]){
            X[k--] = X[m--];
        }else{
            X[k--] = Y[n--];
        }
    }
//    m没到头的话，不用移动了再，因为它本身就在X中
    while(n >= 0){
        X[k--] = Y[n--];
    }
}

void MergeForConstaint(int X[],int Y,int m,int n){
    // moves non-empty elements of X in the begining
    int k = 0;
    for(int i = 0;i < m;i++){
        if(X[i] != 0){
            X[k++] = X[i]
        }
    }
    Merge(X,Y,k - 1,n - 1);
}



#endif /* MergeSortForConstaint_h */
