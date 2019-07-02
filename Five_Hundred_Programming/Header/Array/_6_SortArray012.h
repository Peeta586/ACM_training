//
//  SortArray012.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/21.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef SortArray012_h
#define SortArray012_h
/***
 sort an array containing 0's,1's,2's, 
 in linear time and in constant space
 假设像 快拍分界一样，我们分三界：先选一个pivot = 1
 value less than the pivot
 value equal to the pivot and
 value greater than the pivot
 **/
#include <iostream>
using namespace std;
void threewaypartition(int A[],int end){
    int start = 0, mid = 0;
    int pivot = 1;
    
    while(mid <= end){
        if(A[mid] < pivot){ // current element is 0
            swap(A[start],A[mid]);
            ++start,++mid;
        }else if(A[mid] > pivot){//current element is 2
            swap(A[mid],A[end]);
            end--;
        }else{ //current element is 1
            ++mid;
        }
    }
}



#endif /* SortArray012_h */
