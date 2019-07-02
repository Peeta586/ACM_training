//
//  MoveEnd0.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/23.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef MoveEnd0_h
#define MoveEnd0_h
/***将数组的0元素移到后面
 **/
/****
 solution 1:
 the idea is simple, if current element is non-zero, we can place the
 element to next availiable position in the array,after all element in
 the array are processed,we fill all remaining indices by 0
 */

void reorder(int a[],int n){
    int k = 0;
    for(int i = 0;i < n;i++){
        if(a[i] != 0){
            a[k++] = a[i];
        }
    }
    for(int i = k;i < n;i++)
        a[i] = 0;
}



// use partitioning logic quick-sort
void reoder2(int a[],int n){
    int pivot = 0;
    int start = 0;
    for(int i = 0;i < n;i++){
        if(a[i] != pivot){
            swap(a[i],a[start]);
            start++;
        }
    }
}




#endif /* MoveEnd0_h */
