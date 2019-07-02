//
//  RerangeArray.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/22.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef RerangeArray_h
#define RerangeArray_h

//Rearrange the array with alternate high and low elements
/**
 Given an array of integers, rearrange the array such that 
 every second element of the array is greater than its left
 and right elements. Assume no duplicate elements are present
 in the array.
 input:{1,2,3,4,5,6,7}
 output:{1,3,2,5,4,7,6}
 */
//solution 1:first sort the array, 并且从0开始遍历，一个大一个小
//的遍历读取。
/*** need auxiliary array
 sort(a)
 i = 0,j = n - 1
 while(i<j)
    aux[k++] = a[i++] 一个小，一个大
    aux[k++] = a[j--]
 **/

//方法 2: 对于每一个偶数位置，我们判断其前后是否都小于它
//如果不小就交换
void RerangeArray(int a[],int n){
//    从第二个元素开始
    for(int i = 1;i < n; i += 2){
        if(a[i - 1] > a[i])
            swap(a[ i - 1],a[i]);
        if((i + 1 < n) && (a[i + 1] > a[i]))
            swap(a[i + 1],a[i]);
    }
}



#endif /* RerangeArray_h */
