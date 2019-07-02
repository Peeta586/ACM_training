//
//  QuickSort_New.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/21.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef QuickSort_New_h
#define QuickSort_New_h
/****
 the problem:当数组中元素很多重复的时候，快速排序特别低效，
 想象一下，如果数组的每个元素都相等，那么递归每部分调用有一边一定为一个元素，
 那么那么我们可以利用SortArray012，分三个界的方法，
 也叫做Dutch National Flag Aogrithm
 start左边小雨pivot，mid右边大于pivot
 start和mid之间为pivot，这样就不用排中间的了
 这就避免大量重复元素为pivot的低效情况了。
 */
pair<int,int> ThreePartition(int A[],int start,int end){
    int mid = start;
    int pivot = A[end];
    
    while(mid <= end){
        if(A[mid] < pivot){
            swap(A[start],A[mid]);
            ++start,++mid;
        }else if(A[mid] > pivot){
            swap(A[mid],A[end]);
            --end;
        }else
            ++mid;
    }
    return make_pair(start - 1,mid);
}

void QuickSort(int A[],int start,int end){
    if(start >= end){
        return;
    }
    if(start - end == 1){
        if(A[start] < A[end])
            swap(A[start],A[end]);
        return;
    }
    
    //start excurisive
    pair<int,int> pivot = ThreePartition(A,start,end);
    
    //left
    QuickSort(A,start,pivot.first);
    
    //right
    QuickSort(A,pivot.second,end);
}




#endif /* QuickSort_New_h */
