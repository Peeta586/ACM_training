//
//  FindIndex0ForMax.h
//  BeautyOfProgramming
//
//  Created by hyx on 17/10/22.
//  Copyright © 2017年 hyx. All rights reserved.
//

#ifndef FindIndex0ForMax_h
#define FindIndex0ForMax_h

/******
Find index of 0 to be replaced to get maximum length sequence of continuous ones.
 Given a binary array, find the index of 0 to be replaced with 1 to get maximum length sequence of continuous ones.
 就是找一个位置的0，用1替换，使数组能的到最大的连续1子序列
 只替换一次
 **/
using namespace std;

int findIndexofZero(int a[],int n){
    int max_count = 0;
    int max_index = -1;
    
    int pre_zero_index = -1;
    int count = 0;
    
    for(int i = 0;i < n;i++){
        if(a[i] == 1)
            count++;
        else{//很巧妙i － pre_zero_index
            //如果遇到连续为0的情况，count始终为1，表示替换1得到序列长度为1
            count = i - pre_zero_index;
            pre_zero_index = i; //记录前0的位置
        }
        if(count > max_count){
            max_count = count;
            max_index = pre_zero_index;
        }
    }
    
    return max_index;
}


/*********solution 2
 The idea is very simple. We update each non-zero element of array with count of its adjacent consecutive 1’s. For example, array { 0, 0, 1, 0, 1, 1, 1, 0,1, 1 } is converted to { 0, 0, 1, 0, 3, 3, 3, 0, 2, 2 }. Now the problem reduces to ending the index of 0 whose sum of left and right element is maximum.
 Note that this approach will modify the array and at-least requires two traversals of the array. We can use an auxiliary array to avoid modi􀃒cation of original array or restore the original array before returning.
 ****/

/***********solutioin 3:滑动窗口的方式，
 如果一个窗口多于1个0元素，则删除左边元素，重新遍历
 */
int findIndexofZero3(int a[],int n){
    int left = 0;
    int count = 0; //the number of zeros in current window
    
    int max_count = 0;
    int max_index = -1;//全0的话，则没有index输出
    
    int cur_zero_index = -1;
    
    for(int i = 0;i < n;i++){
        if(a[i] == 0){
            cur_zero_index = i;
            count++;
        }
        
        if(count == 2){
            while(a[left])
                left++;
            
            left++;
            
            count = 1;
        }
        
        if(i - left + 1 > max_count){
            max_count = i - left + 1;
            max_index = cur_zero_index;
        }
    }
    return max_index;
}


#endif /* FindIndex0ForMax_h */
