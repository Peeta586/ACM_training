//
//  find_max_sum_no_adj.h
//  Five_Hundred_Programing
//
//  Created by hyx on 17/11/10.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef find_max_sum_no_adj_h
#define find_max_sum_no_adj_h

/*Decode the array constructed from another array
 Given an array constructed from another array by 
 taking sum of every distinct pair in it, decode
 the array to get back the original array elements.
 If the original array is A[0], A[1], . . , A[n-1], then the input array is
 { (A[0] + A[1]), (A[0] + A[2]), . . , (A[0] + A[n-1]),
 (A[1] + A[2]), (A[1] + A[3]), . . , (A[1] + A[n-1]),
 ..
 ..
 (A[i] + A[i+1]), (A[i] + A[i+2]), . . , (A[i] + A[n-1]),
 ..
 ..
 (A[n-2] + A[n-1]) }
 For example,
 Input: { 3, 4, 5, 5, 6, 7 }
 Output: { 1, 2, 3, 4 }
 Input: { 3, 4, 5, 6, 5, 6, 7, 7, 8, 9 }
 Output: { 1, 2, 3, 4, 5 }
 Input: { 3 }
 Output: { 1, 2 } or { 2, 1 }
 Input: {3, 4, 5 }
 Output: { 1, 2, 3 }
 解码一个数组，该数组是由原始数组的每一项一次叠加的，如上式显示：
 首先我们可以计算出来原始数组n的个数，然后由叠加规律可知，该数组
 inp[n-1]对应着原始数组A1+A2，而inp[0]和inp[1]等于 2*A0+A1+A2
 因此我们可以计算出A0 ＝ inp0+inp1 - inp[n - 1],
 又由于n^2 - n - 2m = 0  ---> n = (sqrt(8 * m + 1) + 1)/ 2
 */
#include <algorithm>
#include <iostream>
using namespace std;
void Decode(int a[], int m){
    // calculate size of original array
    int n = (sqrt(8 * m + 1) + 1) / 2;
    
    int A[n];
    
    if (n == 1){
        A[0] = a[0];
    }else if (n == 2){
        A[0] = 1;  //任意数字，
    }else{
        A[0] = (a[0] + a[1] - a[n-1]) / 2;
    }
    
    for(int i = 1; i < n;i++){
        A[i] = a[i - 1] - A[0];
    }
    
    for (int i = 0;i < n;i++){
        cout<<A[i]<<' ';
    }
}

#endif /* find_max_sum_no_adj_h */
