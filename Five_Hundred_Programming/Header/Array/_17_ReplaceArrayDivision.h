//
//  ReplaceArrayDivision.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/23.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef ReplaceArrayDivision_h
#define ReplaceArrayDivision_h

/**Problem: Replace each element of the  array with product
 of every other element without using division operator:
 问题是将每一个元素用其余元素的乘积代替
 
 Given an array of integers, replace each element of the array
 with product of every each element in the array without using
 division operator.
 */
// naive solution : O(n)
/**
 we can solve this problem in linear time by using two auxiliary
 arrays left[], and right[],
 where left[i] stores the product of all elements in the sub-array
 A[0..i-1] and right stores the product of elements in the 
 right sub-array A[i+1..n-1], Now we calculate A[i] = left[i] * right[i]
 
 **/
void FindProduct(int a[],int n){
    int left[n],right[n];
    
    left[0] = 1;
    for(int i = 1;i < n;i++){
        left[i] = left[i - 1] * a[i - 1];
    }
    right[n - 1] =1;
    for(int i = n - 2;i >= 0;i--){
        right[i] = right[i + 1] * a[i + 1];
    }
    for(int i = 0;i < n;i++)
        a[i] = left[i] * right[i];
}

//recursive solution
/**
 left:保留的是，i之前i－1个元素的成积，用于在函数中更改a[i] 用的
 i：表示当前index的值。
 而由于我们要求right，则FindProduct要返回右边所有元素的乘积，
 因为是递归方式，所以每次返回curr * right,既当前元素和其后面元素的乘积；
 
 ＃＃＃＃＃
 注意：递归中我们在递归中保存需要的值，每次要返回的是什么（返回目标），
 返回目标在递归中拆分成每次要返回的值
 */
int FindProduct2(int a[],int n,int left,int i){
    //base case: no elements left on right side
    if(i == n){
        return 1;
    }
    //take back-up of current element
    int curr = a[i];
    
    //calculate product of the right sub-array
    int right = FindProduct2(a,n,left * curr,i + 1);
    
    //replace current element with product of left and right
    a[i] = left * right;
    
    //return product of right sub-array including current element
    return curr * right;
    
}


#endif /* ReplaceArrayDivision_h */
